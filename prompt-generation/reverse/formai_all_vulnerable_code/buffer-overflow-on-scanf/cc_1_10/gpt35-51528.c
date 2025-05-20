//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    //initialize variables
    char path[100];
    struct dirent *entry;
    struct stat fileStats;
    unsigned long long totalSize = 0;

    //prompt user for directory path
    printf("Enter directory path: ");
    scanf("%s", path);

    DIR *dir = opendir(path);

    //check if directory can be opened
    if(!dir) {
        printf("Error opening directory.\n");
        return -1;
    }

    //loop through all files in directory
    while((entry = readdir(dir)) != NULL) {
        char filePath[200];
        sprintf(filePath, "%s/%s", path, entry->d_name);

        //check file stats
        if(stat(filePath, &fileStats) < 0) {
            printf("Error getting file stat.\n");
            continue;
        }

        //add file size to total size
        totalSize += fileStats.st_size;
    }

    closedir(dir);

    //print total size in bytes, kilobytes, megabytes, and gigabytes
    printf("Total size: %llu bytes\n", totalSize);
    printf("Total size: %llu KB\n", totalSize/1024);
    printf("Total size: %llu MB\n", totalSize/(1024*1024));
    printf("Total size: %llu GB\n", totalSize/(1024*1024*1024));

    return 0;
}