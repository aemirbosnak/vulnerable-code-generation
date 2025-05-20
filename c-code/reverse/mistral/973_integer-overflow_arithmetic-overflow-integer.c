#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct statvfs stats;
    if (statvfs(argv[1], &stats) == -1) {
        perror("Error getting file system stats");
        return 1;
    }

    long long total = stats.f_blocks * stats.f_bsize;
    long long used = total - stats.f_bfree * stats.f_bsize;
    double percentage = (double)used / total * 100;

    printf("Path: %s\n", argv[1]);
    printf("Total space: %lld bytes\n", total);
    printf("Used space: %lld bytes\n", used);
    printf("Percentage usage: %.2f%%\n", percentage);

    return 0;
}
