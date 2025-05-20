//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>

void displayDiskUsage() {
    struct statvfs stat;

    // Gather disk statistics for the root directory
    if (statvfs("/", &stat) != 0) {
        perror("Could not retrieve disk statistics");
        return;
    }
    
    // Calculate disk space values
    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;

    // Prepare the output message
    printf("\n");
    printf("==== Disk Space Analysis ====\n");
    printf("Total Disk Space: %lu bytes (%.2f GB)\n", total, total / (1024.0 * 1024 * 1024));
    printf("Used Disk Space:  %lu bytes (%.2f GB)\n", used, used / (1024.0 * 1024 * 1024));
    printf("Free Disk Space:  %lu bytes (%.2f GB)\n", free, free / (1024.0 * 1024 * 1024));

    // Show percentage of used space
    double usedPercentage = ((double)used / total) * 100;
    printf("Used Space Percentage: %.2f%%\n", usedPercentage);
    printf("=============================\n");
}

void givePeacefulAdvice(double usedPercentage) {
    if (usedPercentage < 70) {
        printf("Your disk space is in a good state. Maintain the balance, and all shall be well.\n");
    } else if (usedPercentage < 90) {
        printf("Caution! Your disk is getting full. It may be time to liberate some space.\n");
    } else {
        printf("Warning! Your disk is nearly full. Consider removing unnecessary files or expanding storage.\n");
    }
}

int main() {
    printf("Welcome, seeker of knowledge.\n");
    printf("Let us contemplate upon the state of your sacred disk space...\n\n");

    // Display disk usage
    displayDiskUsage();

    // Calculate and give advice on used disk space
    unsigned long total = 0, used = 0, free = 0; 
    struct statvfs stat;

    if (statvfs("/", &stat) == 0) {
        total = stat.f_blocks * stat.f_frsize;
        used = total - (stat.f_bfree * stat.f_frsize);
    } 

    double usedPercentage = ((double)used / total) * 100;    
    givePeacefulAdvice(usedPercentage);
    
    printf("\nThank you for pausing to reflect on your disk space.\n");
    return 0;
}