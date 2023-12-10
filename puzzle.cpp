//
// Created by Vlad Isan on 05/12/2023.
//

#include "puzzle.h"

int puzzle_sample_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

int puzzle_sample_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int puzzle_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

int puzzle_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int do_puzzle_1(std::ifstream &file) {
    std::string line;
    uint64_t total_area = 0;

    while (std::getline(file, line)) {
        std::string dim;
        std::vector<uint64_t> dimensions{};
        std::istringstream iss{line};

        while (std::getline(iss, dim, 'x')) {
            dimensions.push_back(std::stoul(dim));
        }

        std::ranges::sort(dimensions);

        uint64_t area = 2 * dimensions[0] * dimensions[1];
        area += 2 * dimensions[1] * dimensions[2];
        area += 2 * dimensions[2] * dimensions[0];

        area += dimensions[0] * dimensions[1];

        total_area += area;
    }

    return total_area;
}

int do_puzzle_2(std::ifstream &file) {
    std::string line;
    uint64_t total_area = 0;

    while (std::getline(file, line)) {
        std::string dim;
        std::vector<uint64_t> dimensions{};
        std::istringstream iss{line};

        while (std::getline(iss, dim, 'x')) {
            dimensions.push_back(std::stoul(dim));
        }

        std::ranges::sort(dimensions);

        uint64_t length = 2 * dimensions[0] + 2 * dimensions[1];

        length += dimensions[0] * dimensions[1] * dimensions[2];

        total_area += length;
    }

    return total_area;
}
