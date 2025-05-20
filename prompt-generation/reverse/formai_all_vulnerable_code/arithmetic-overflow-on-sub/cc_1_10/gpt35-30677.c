//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<sys/statvfs.h>

int main(){
    struct statvfs buf;
    char drive_path[512];
    long long total, free, used, percent_used;
    int i, count = 0;

    // Enter the path to the drive or leave blank to use current directory
    printf("Enter drive path (or leave blank to use current directory): ");
    scanf("%s", drive_path);

    // Check if the path exists
    if(statvfs(drive_path, &buf) == -1){
        printf("\nPath does not exist.\n");
        exit(1);
    }

    total = (long long)buf.f_frsize * (long long)buf.f_blocks;
    free = (long long)buf.f_frsize * (long long)buf.f_bfree;
    used = total - free;
    percent_used = (used * 100) / total;

    printf("\nDisk space analyzer:");
    printf("\n------------------------\n\n");

    // Print the usage bar
    for(i = 0; i < 100; i += 2){
        if(i < percent_used)
            printf("\033[0;31m");
        else
            printf("\033[0;32m");

        count++;
        if(count == 10){
            printf(" "); // add a space every 10 characters
            count = 0;
        }

        printf("|");
        printf("\033[0m"); // reset color
    }

    printf("\n\nTotal disk size: %.2Lf GB", (long double)total / (1024 * 1024 * 1024));
    printf("\nFree disk space: %.2Lf GB", (long double)free / (1024 * 1024 * 1024));
    printf("\nUsed disk space: %.2Lf GB (%lld%%)", (long double)used / (1024 * 1024 * 1024), percent_used);

    return 0;
}