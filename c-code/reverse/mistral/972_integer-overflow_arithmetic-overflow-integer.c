#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    struct statvfs stats;
    char mountpoint[1024];
    if (statvfs("/", &stats) == -1) {
        perror("Error getting file system stats");
        return 1;
    }

    long long total = stats.f_blocks * stats.f_frsize;
    long long used = total - stats.f_bfree * stats.f_frsize;
    long long free = stats.f_bavail * stats.f_frsize;

    printf("Total size: %lld bytes\n", total);
    printf("Used space: %lld bytes\n", used);
    printf("Free space: %lld bytes\n", free);
    printf("Total percentage: %lld%%\n", (total - used)*100/total);
    printf("Used percentage: %lld%%\n", used*100/total);
    printf("Free percentage: %lld%%\n", free*100/total);

    return 0;
}
