//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
/*
 * Unique C Disk Space Analyzer Program
 *
 * This program analyzes the disk space usage on the system and reports the results
 * in a fun and enthusiastic way.
 *
 * Usage:
 *  $ ./disk_space_analyzer
 *
 * Example Output:
 *  You have 1000 GB of disk space left on your system!
 *  You're doing great! Keep it up!
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <sys/types.h>

int main() {
    struct statvfs fs;
    double total, free, used, percent;

    // Get the file system statistics
    if (statvfs("/", &fs) < 0) {
        perror("statvfs");
        exit(1);
    }

    // Calculate the total and free disk space
    total = (double)fs.f_blocks * fs.f_bsize;
    free = (double)fs.f_bfree * fs.f_bsize;

    // Calculate the used disk space and percentage
    used = total - free;
    percent = (used / total) * 100;

    // Print the results
    printf("You have %f GB of disk space left on your system!\n", free / 1e9);
    if (percent < 20) {
        printf("You're doing great! Keep it up!\n");
    } else if (percent < 50) {
        printf("You're almost out of space! Get rid of some files!\n");
    } else if (percent < 80) {
        printf("You're getting low on space! Clean up those files!\n");
    } else {
        printf("You're in danger of running out of space! Delete some files NOW!\n");
    }

    return 0;
}