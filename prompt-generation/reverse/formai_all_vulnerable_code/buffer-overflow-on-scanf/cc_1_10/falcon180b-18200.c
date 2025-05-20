//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct dirent *readdir(DIR *dirp);

int main()
{
    char path[1024];
    DIR *dir;
    struct dirent *ent;
    int total_size = 0;
    int num_files = 0;

    printf("Enter directory path: ");
    scanf("%s", path);

    dir = opendir(path);

    if (dir!= NULL)
    {
        while ((ent = readdir(dir))!= NULL)
        {
            if (ent->d_type == DT_REG)
            {
                num_files++;
                total_size += ent->d_reclen;
            }
        }

        closedir(dir);

        printf("Total number of files: %d\n", num_files);
        printf("Total size of files: %d bytes\n", total_size);
    }
    else
    {
        printf("Directory does not exist.\n");
    }

    return 0;
}

struct dirent *readdir(DIR *dirp)
{
    return readdir(dirp);
}