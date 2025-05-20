//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    //Get the current working directory
    char currentDir[1024];
    if (getcwd(currentDir, sizeof(currentDir)) == NULL)
    {
        perror("getcwd");
        exit(1);
    }
    //Get the disk space info
    struct stat disk_info;
    if (stat(currentDir, &disk_info) == -1)
    {
        perror("stat");
        exit(1);
    }
    //Calculate disk space usage
    double total_space = disk_info.st_blocks * disk_info.st_blksize;
    double used_space = 0;
    DIR *dirp;
    struct dirent *dp;
    char path[1024];
    if ((dirp = opendir(currentDir))!= NULL)
    {
        while ((dp = readdir(dirp))!= NULL)
        {
            sprintf(path, "%s/%s", currentDir, dp->d_name);
            struct stat stat_buf;
            if (stat(path, &stat_buf) == -1)
            {
                perror("stat");
                exit(1);
            }
            used_space += stat_buf.st_blocks * stat_buf.st_blksize;
        }
        closedir(dirp);
    }
    else
    {
        perror("opendir");
        exit(1);
    }
    //Calculate disk space usage percentage
    double free_space = total_space - used_space;
    double free_percent = 100 * (free_space / total_space);
    printf("Total disk space: %.2f GB\n", total_space / (1024 * 1024 * 1024));
    printf("Used disk space: %.2f GB\n", used_space / (1024 * 1024 * 1024));
    printf("Free disk space: %.2f GB\n", free_space / (1024 * 1024 * 1024));
    printf("Free disk space percentage: %.2f %%\n", free_percent);
    return 0;
}