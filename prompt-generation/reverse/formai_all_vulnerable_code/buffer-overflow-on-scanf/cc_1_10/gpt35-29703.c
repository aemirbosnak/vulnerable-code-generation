//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LENGTH 1000

/* Define a function that retrieves the disk usage of the given directory */
long long get_directory_usage(char *directory_path)
{
    DIR *directory;
    struct dirent *entry;
    struct stat s;
    char path[MAX_PATH_LENGTH];
    long long total_usage = 0;

    /* Open the directory */
    directory = opendir(directory_path);
    if (directory == NULL)
    {
        return -1;
    }

    /* Loop through all entries in the directory */
    while ((entry = readdir(directory)) != NULL)
    {
        /* Create the full path for the entry */
        snprintf(path, MAX_PATH_LENGTH, "%s/%s", directory_path, entry->d_name);

        /* Get information about the entry */
        if (stat(path, &s) == -1)
        {
            continue;
        }

        /* If the entry is a directory, recurse into it */
        if (S_ISDIR(s.st_mode))
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }
            total_usage += get_directory_usage(path);
        }

        /* If the entry is a file, add its size to the total usage */
        else if (S_ISREG(s.st_mode))
        {
            total_usage += s.st_size;
        }
    }

    /* Close the directory and return the total usage */
    closedir(directory);
    return total_usage;
}

int main()
{
    char directory_path[MAX_PATH_LENGTH];
    long long total_usage;

    /* Get the path of the directory to analyze */
    printf("Enter the path of the directory to analyze: ");
    scanf("%s", directory_path);

    /* Get the total disk usage of the directory */
    total_usage = get_directory_usage(directory_path);
    if (total_usage == -1)
    {
        printf("Error: Could not open directory.\n");
        return 1;
    }

    /* Print the total disk usage of the directory in a human-readable format */
    printf("Total disk usage: ");
    if (total_usage < 1024)
    {
        printf("%lld bytes\n", total_usage);
    }
    else if (total_usage < 1024 * 1024)
    {
        printf("%.2f KB\n", (double)total_usage / 1024);
    }
    else if (total_usage < 1024 * 1024 * 1024)
    {
        printf("%.2f MB\n", (double)total_usage / (1024 * 1024));
    }
    else
    {
        printf("%.2f GB\n", (double)total_usage / (1024 * 1024 * 1024));
    }

    return 0;
}