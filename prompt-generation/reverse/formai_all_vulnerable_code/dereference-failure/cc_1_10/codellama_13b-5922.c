//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
/*
 * Unique C Disk Space Analyzer Program
 * Written in a cheerful style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <errno.h>

#define DISK_NAME_SIZE 100
#define PATH_NAME_SIZE 100

int main(int argc, char *argv[]) {
    struct statvfs disk_stats;
    char disk_name[DISK_NAME_SIZE];
    char path_name[PATH_NAME_SIZE];
    double total_space, free_space, used_space;
    int disk_name_len;

    if (argc != 2) {
        printf("Usage: %s <disk name>\n", argv[0]);
        return 1;
    }

    disk_name_len = strlen(argv[1]);
    if (disk_name_len >= DISK_NAME_SIZE) {
        printf("Disk name too long\n");
        return 1;
    }

    strcpy(disk_name, argv[1]);
    strcpy(path_name, "/");

    if (statvfs(path_name, &disk_stats) != 0) {
        printf("Error getting disk stats: %s\n", strerror(errno));
        return 1;
    }

    total_space = (double)disk_stats.f_blocks * disk_stats.f_frsize;
    free_space = (double)disk_stats.f_bfree * disk_stats.f_frsize;
    used_space = total_space - free_space;

    printf("Disk Space Analyzer\n");
    printf("------------------\n");
    printf("Disk Name: %s\n", disk_name);
    printf("Total Space: %.2f GB\n", total_space / 1024.0 / 1024.0 / 1024.0);
    printf("Free Space: %.2f GB\n", free_space / 1024.0 / 1024.0 / 1024.0);
    printf("Used Space: %.2f GB\n", used_space / 1024.0 / 1024.0 / 1024.0);
    printf("Percentage Used: %.2f%%\n", (used_space / total_space) * 100.0);

    return 0;
}