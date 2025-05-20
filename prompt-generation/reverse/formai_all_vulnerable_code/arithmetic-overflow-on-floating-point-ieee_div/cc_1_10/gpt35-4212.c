//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GB 1073741824
#define MB 1048576
#define KB 1024

int main(void) {
    long long totalSpace = 0;
    long long usedSpace = 0;
    long long freeSpace = 0;

    // Get the total space of the disk 
    FILE* fp = popen("df -h / | awk 'NR==2 {print $2}'", "r");
    char totalSpaceCmd[100];
    if (fp != NULL) {
        fgets(totalSpaceCmd, sizeof(totalSpaceCmd), fp);
        totalSpace = atol(totalSpaceCmd) * GB;
        pclose(fp);
    }

    // Get the used space of the disk 
    fp = popen("df -h / | awk 'NR==2 {print $3}'", "r");
    char usedSpaceCmd[100];
    if (fp != NULL) {
        fgets(usedSpaceCmd, sizeof(usedSpaceCmd), fp);
        usedSpace = atol(usedSpaceCmd) * GB;
        pclose(fp);
    }

    // Get the free space of the disk 
    fp = popen("df -h / | awk 'NR==2 {print $4}'", "r");
    char freeSpaceCmd[100];
    if (fp != NULL) {
        fgets(freeSpaceCmd, sizeof(freeSpaceCmd), fp);
        freeSpace = atol(freeSpaceCmd) * GB;
        pclose(fp);
    }

    printf("Total Space = %lld GB\n", totalSpace/GB);
    printf("Used Space = %lld GB\n", usedSpace/GB);
    printf("Free Space = %lld GB\n", freeSpace/GB);

    // Calculate the percentage of used space
    int percentUsed = (int)((double)usedSpace / (double)totalSpace * 100);

    // Print some information based on percentage of used space 
    if (percentUsed >= 90) {
        printf("\nWARNING: You have used over 90%% of your disk space!\n");
        printf("Please start deleting unnecessary files to free up some space!\n");
    } else if (percentUsed >= 75) {
        printf("\nCAUTION: You have used over 75%% of your disk space!\n");
        printf("You should consider deleting some files to free up some space!\n");
    } else {
        printf("\nYou still have %lld GB of free space left! Keep it up!\n", freeSpace/GB);
    }

     return 0;
}