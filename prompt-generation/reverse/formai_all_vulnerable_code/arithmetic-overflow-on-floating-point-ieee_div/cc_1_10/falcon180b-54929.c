//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define KB 1024
#define MB (KB * KB)
#define GB (MB * KB)

int main(int argc, char *argv[]) {
    struct statvfs stat;
    int i, j;
    double total, used, free, percent;

    // get total, used and free memory in bytes
    if (statvfs("/", &stat) == -1) {
        printf("Error: cannot get file system statistics\n");
        exit(1);
    }
    total = (double)stat.f_blocks * (double)stat.f_frsize;
    used = (double)stat.f_blocks - (double)stat.f_bfree * (double)stat.f_frsize;
    free = (double)stat.f_bfree * (double)stat.f_frsize;

    // print memory usage in human-readable format
    printf("Memory usage:\n");
    printf("Total: %.2f MB\n", total / MB);
    printf("Used: %.2f MB\n", used / MB);
    printf("Free: %.2f MB\n", free / MB);
    printf("\n");

    // print memory usage as a percentage
    percent = (used / total) * 100;
    printf("Memory usage: %.2f%%\n", percent);

    // print memory usage in a bar graph
    printf("\n");
    for (i = 0; i < 50; i++) {
        printf("=");
    }
    printf("\n");
    for (i = 0; i < 50; i++) {
        j = (int)((double)i / 50 * 100);
        if (j < (int)(used / total * 50)) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}