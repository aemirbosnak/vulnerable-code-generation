//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    char directory_path[100];
    struct dirent *dptr;
    struct stat statbuf;
    int total_size = 0;

    // Get the path of the directory to scan
    printf("Enter directory path to scan: ");
    scanf("%s", directory_path);

    // Open the directory
    DIR *directory = opendir(directory_path);

    if(directory == NULL)
    {
        printf("Error: Could not open directory.\n");
        return 1;
    }

    // Loop through each file/directory in the directory
    while((dptr = readdir(directory)) != NULL)
    {
        // Ignore "." and ".." directories
        if(strcmp(dptr->d_name, ".") == 0 || strcmp(dptr->d_name, "..") == 0)
            continue;

        // Get the path of the file/directory
        char filepath[200];
        sprintf(filepath, "%s/%s", directory_path, dptr->d_name);

        // Get the stats of the file/directory
        if(stat(filepath, &statbuf) == -1)
        {
            printf("Error: Could not get stats for %s\n", filepath);
            continue;
        }

        // If it's a directory, recursively scan it and add its size to the total
        if(S_ISDIR(statbuf.st_mode))
        {
            int dir_size = 0;

            // Recursively scan the directory
            DIR *subdir = opendir(filepath);

            if(subdir == NULL)
            {
                printf("Error: Could not open subdirectory %s\n", filepath);
                continue;
            }

            while((dptr = readdir(subdir)) != NULL)
            {
                if(strcmp(dptr->d_name, ".") == 0 || strcmp(dptr->d_name, "..") == 0)
                    continue;

                char subfilepath[200];
                sprintf(subfilepath, "%s/%s", filepath, dptr->d_name);

                if(stat(subfilepath, &statbuf) == -1)
                {
                    printf("Error: Could not get stats for %s\n", subfilepath);
                    continue;
                }

                dir_size += statbuf.st_size;
            }

            printf("%s [DIR] - %d bytes\n", filepath, dir_size);

            total_size += dir_size;

            closedir(subdir);
        }
        else // If it's a file, just add its size to the total
        {
            printf("%s - %d bytes\n", filepath, statbuf.st_size);

            total_size += statbuf.st_size;
        }
    }

    // Display the total size
    printf("Total size of %s - %d bytes\n", directory_path, total_size);

    closedir(directory);

    return 0;
}