#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void displayDiskUsage(long long totalSpace, long long freeSpace) {
    long long usedSpace = totalSpace - freeSpace;
    int percentUsed = (int)((usedSpace * 100) / totalSpace); // Vulnerability: Integer overflow if totalSpace is very small

    printf("Total Space: %lld GB\n", totalSpace);
    printf("Free Space: %lld GB\n", freeSpace);
    printf("Used Space: %lld GB\n", usedSpace);
    printf("Percentage Used: %d%%\n", percentUsed);
}

int main() {
    long long totalSpace = 1024LL * 1024 * 1024; // 1 GB
    long long freeSpace = 512LL * 1024 * 1024;  // 512 MB

    displayDiskUsage(totalSpace, freeSpace);

    return 0;
}
