//Falcon-180B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024

void print_files(char *path, int level)
{
    DIR *dp;
    struct dirent *dirp;
    char next_path[MAX_LINE];

    dp = opendir(path);
    if (!dp)
    {
        perror("opendir");
        exit(1);
    }

    while ((dirp = readdir(dp))!= NULL)
    {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
        {
            continue;
        }

        strcpy(next_path, path);
        strcat(next_path, "/");
        strcat(next_path, dirp->d_name);

        if (dirp->d_type == DT_DIR)
        {
            print_files(next_path, level + 1);
        }
        else
        {
            printf("%*s%s\n", level * 2, "", dirp->d_name);
        }
    }

    closedir(dp);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s directory\n", argv[0]);
        exit(1);
    }

    printf("Directory listing:\n");
    print_files(argv[1], 0);

    return 0;
}