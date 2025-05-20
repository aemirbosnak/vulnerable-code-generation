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
    printf("Path: %s\n", path);
    printf("Total space: %lu bytes\n", buf.f_blocks * buf.f_frsize);
    printf("Free space: %lu bytes\n", buf.f_bfree * buf.f_frsize);
    printf("Used space: %lu bytes\n", (buf.f_blocks - buf.f_bfree) * buf.f_frsize);
    double used_percent = ((double)(buf.f_blocks - buf.f_bfree) / buf.f_blocks) * 100.0;
    printf("Used space percentage: %.2f%%\n", used_percent);
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
