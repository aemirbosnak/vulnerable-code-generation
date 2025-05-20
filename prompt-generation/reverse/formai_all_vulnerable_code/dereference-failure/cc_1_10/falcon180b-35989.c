//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH 1024

// Function to calculate directory size
long long int calculate_directory_size(char* path)
{
    long long int size = 0;
    DIR* dir;
    struct dirent* ent;

    dir = opendir(path);
    if (dir!= NULL)
    {
        while ((ent = readdir(dir))!= NULL)
        {
            if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0)
            {
                char file_path[MAX_PATH];
                sprintf(file_path, "%s/%s", path, ent->d_name);

                struct stat stats;
                stat(file_path, &stats);

                if (S_ISDIR(stats.st_mode))
                {
                    size += calculate_directory_size(file_path);
                }
                else
                {
                    size += stats.st_size;
                }
            }
        }
        closedir(dir);
    }

    return size;
}

int main(int argc, char* argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH];
    strcpy(path, argv[1]);

    long long int total_size = calculate_directory_size(path);
    printf("Total size of '%s': %lld bytes\n", path, total_size);

    return 0;
}