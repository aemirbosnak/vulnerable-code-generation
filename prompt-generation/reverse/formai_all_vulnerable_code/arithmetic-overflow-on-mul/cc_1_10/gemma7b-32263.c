//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_NAME_LENGTH 256

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat stat_buf;
    char dir_name[MAX_DIR_NAME_LENGTH];
    long total_space = 0;
    long free_space = 0;

    // Get the current working directory
    getcwd(dir_name, MAX_DIR_NAME_LENGTH);

    // Open a directory stream
    dir = opendir(dir_name);

    // Iterate over the directory entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.')
            continue;

        // Get the full path of the file or directory
        char full_path[MAX_DIR_NAME_LENGTH];
        snprintf(full_path, MAX_DIR_NAME_LENGTH, "%s/%s", dir_name, entry->d_name);

        // Get the file or directory statistics
        stat(full_path, &stat_buf);

        // Add the file or directory size to the total space
        total_space += stat_buf.st_size;

        // Add the free space to the free space
        free_space += stat_buf.st_size * (stat_buf.st_blocks - stat_buf.st_blocks * 8);
    }

    // Close the directory stream
    closedir(dir);

    // Print the total and free space
    printf("Total space used: %ld bytes\n", total_space);
    printf("Free space available: %ld bytes\n", free_space);

    return 0;
}