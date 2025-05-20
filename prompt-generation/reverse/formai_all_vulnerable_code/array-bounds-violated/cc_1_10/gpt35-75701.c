//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

// Function to convert size from bytes to KB, MB, GB, TB
void convert_size(double *size, char *unit) {
    char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int i;
    for (i = 0; i < 5 && *size >= 1024; i++) {
        (*size) /= 1024;
    }
    sprintf(unit, "%s", units[i]);
}

// Main function
int main() {
    struct statvfs fiData;
    char dir[50];
    double total_size, available_size, free_size;
    char total_size_unit[3], available_size_unit[3], free_size_unit[3];

    printf("Enter the directory path to be analyzed:\n");
    fgets(dir, sizeof(dir), stdin);
    dir[strcspn(dir, "\n")] = '\0';

    if (statvfs(dir, &fiData) == -1) {
        printf("Error: Invalid directory path");
        exit(EXIT_FAILURE);
    }

    total_size = (double)fiData.f_blocks * fiData.f_frsize;
    available_size = (double)fiData.f_bavail * fiData.f_frsize;
    free_size = (double)fiData.f_bfree * fiData.f_frsize;

    convert_size(&total_size, total_size_unit);
    convert_size(&available_size, available_size_unit);
    convert_size(&free_size, free_size_unit);

    printf("\n---------------------\n");
    printf("Disk Space Analyzer\n");
    printf("---------------------\n");
    printf("Directory: %s\n", dir);
    printf("Total Size: %.2f%s\n", total_size, total_size_unit);
    printf("Available Size: %.2f%s\n", available_size, available_size_unit);
    printf("Free Size: %.2f%s\n", free_size, free_size_unit);
    printf("---------------------\n");

    return 0;
}