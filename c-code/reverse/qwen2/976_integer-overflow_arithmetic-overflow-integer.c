#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void calculateDiskUsage(int totalSpace, int usedSpace) {
    int freeSpace = totalSpace - usedSpace;
    int percentageUsed = (usedSpace * 100) / totalSpace; // Vulnerable line
    printf("Total Space: %d\n", totalSpace);
    printf("Used Space: %d\n", usedSpace);
    printf("Free Space: %d\n", freeSpace);
    printf("Percentage Used: %d%%\n", percentageUsed);
}

int main() {
    calculateDiskUsage(2147483647, 2147483647); // Intentionally causing overflow
    return 0;
}
