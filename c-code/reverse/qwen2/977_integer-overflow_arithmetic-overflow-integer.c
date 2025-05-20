#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    long long totalSpace, usedSpace, freeSpace;
    
    printf("Enter total disk space in bytes: ");
    scanf("%lld", &totalSpace);
    
    printf("Enter used disk space in bytes: ");
    scanf("%lld", &usedSpace);
    
    if (usedSpace > totalSpace) {
        printf("Error: Used space cannot be greater than total space.\n");
        return 1;
    }
    
    freeSpace = totalSpace - usedSpace;
    
    double usedPercentage = ((double)usedSpace / totalSpace) * 100.0;
    double freePercentage = ((double)freeSpace / totalSpace) * 100.0;
    
    printf("Used Space: %.2f%%\n", usedPercentage);
    printf("Free Space: %.2f%%\n", freePercentage);
    
    return 0;
}
