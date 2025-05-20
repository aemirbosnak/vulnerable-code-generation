//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Function to iterate through files and directories in a given path
void traverse(char *path, int depth, long long *total_size)
{
    struct dirent *entry;
    DIR *dir = opendir(path);

    // Check if directory can be opened
    if (dir == NULL)
    {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char new_path[1024];
        sprintf(new_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;

        // Get file/directory attributes
        if (stat(new_path, &statbuf) == -1)
        {
            perror("Could not get file/directory attributes");
            continue;
        }

        // Add file size to total size if it is a file
        if (S_ISREG(statbuf.st_mode))
        {
            *total_size += statbuf.st_size;
        }

        // Recurse through subdirectories
        if (S_ISDIR(statbuf.st_mode))
        {
            traverse(new_path, depth + 1, total_size);
        }
    }

    closedir(dir);
}

int main()
{
    char path[1024];
    printf("Enter the path to analyze:\n");
    scanf("%s", path);

    long long total_size = 0;

    // Traverse through directories and files to get total size
    traverse(path, 0, &total_size);

    printf("\nDisk space analysis for path: %s\n", path);
    printf("Total size of files: %lld bytes\n", total_size);

    return 0;
}