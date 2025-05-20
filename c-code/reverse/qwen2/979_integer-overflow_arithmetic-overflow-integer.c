#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

void print_disk_usage(const char *path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        perror("statvfs");
        return;
    }

    unsigned long total_blocks = buf.f_blocks;
    unsigned long free_blocks = buf.f_bfree;
    unsigned long used_blocks = total_blocks - free_blocks;

    double total_space = (double)total_blocks * buf.f_frsize / 1024.0 / 1024.0 / 1024.0;
    double free_space = (double)free_blocks * buf.f_frsize / 1024.0 / 1024.0 / 1024.0;
    double used_space = total_space - free_space;

    double percent_used = (used_space / total_space) * 100.0;

    printf("Path: %s\n", path);
    printf("Total Space: %.2f GB\n", total_space);
    printf("Used Space: %.2f GB\n", used_space);
    printf("Free Space: %.2f GB\n", free_space);
    printf("Percentage Used: %.2f%%\n", percent_used);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path> [<path> ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        print_disk_usage(argv[i]);
    }

    return 0;
}
