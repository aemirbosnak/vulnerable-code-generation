#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

void print_stats(const char *path) {
    struct statvfs buf;
    if (statvfs(path, &buf) != 0) {
        perror("statvfs");
        return;
    }

    double total_size_gb = (double)buf.f_blocks * buf.f_frsize / (1024 * 1024 * 1024);
    double used_space_gb = (double)(buf.f_blocks - buf.f_bfree) * buf.f_frsize / (1024 * 1024 * 1024);
    double free_space_gb = (double)buf.f_bfree * buf.f_frsize / (1024 * 1024 * 1024);

    printf("Path: %s\n", path);
    printf("Total Size: %.2f GB\n", total_size_gb);
    printf("Used Space: %.2f GB\n", used_space_gb);
    printf("Free Space: %.2f GB\n", free_space_gb);
    printf("Usage Percentage: %.2f%%\n", (used_space_gb / total_size_gb) * 100);
    printf("Blocks: %lu\n", buf.f_blocks);
    printf("Inodes: %lu\n", buf.f_files);
    printf("Files: %lu\n", buf.f_files - buf.f_ffree);
    printf("Directories: %lu\n", buf.f_files - buf.f_ffree + 1); // Assuming each directory is represented by a file
}

int main() {
    print_stats("/");
    print_stats("/home");
    return 0;
}
