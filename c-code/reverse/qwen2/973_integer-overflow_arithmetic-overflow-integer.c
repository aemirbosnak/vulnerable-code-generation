#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

void print_usage(const char *path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        perror("statvfs");
        return;
    }

    off_t total = buf.f_blocks * buf.f_frsize;
    off_t free = buf.f_bfree * buf.f_frsize;
    off_t used = total - free;

    double percent_used = ((double)used / total) * 100.0;

    printf("Path: %s\n", path);
    printf("Total Space: %lld bytes\n", total);
    printf("Used Space: %lld bytes (%.2f%%)\n", used, percent_used);
    printf("Free Space: %lld bytes\n", free);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path> [<path> ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i) {
        print_usage(argv[i]);
    }

    return EXIT_SUCCESS;
}
