//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    DIR *dir;
    struct dirent *dp;
    struct stat filestat;
    long long total_size = 0;
    
    // Open the current directory
    dir = opendir(".");
    if (!dir)
    {
        printf("Failed to open directory.\n");
        return -1;
    }
    printf("Welcome to Happy Disk Analyzer!\n");
    printf("Let's find out how much disk space you are using!\n");
    printf("Here are the file sizes in this directory:\n");
    printf("\n");
    
    // Loop through all the files in the directory
    while ((dp = readdir(dir)) != NULL)
    {
        if (stat(dp->d_name, &filestat))
            continue;
        if (S_ISDIR(filestat.st_mode))
            continue;
        printf("%-20s %lld bytes\n", dp->d_name, (long long)filestat.st_size);
        total_size += filestat.st_size;
    }
    printf("\n");
    printf("Total size of files in this directory: %lld bytes.\n", total_size);
    
    // Check if we can calculate the free disk space
    if (stat(".", &filestat) == 0)
    {
        printf("Total disk size: %lld bytes.\n", filestat.st_size);
        printf("Free disk space: %lld bytes.\n", filestat.st_size - total_size);
    }
    else
    {
        printf("Failed to get disk space information.\n");
    }
    
    closedir(dir);
    return 0;
}