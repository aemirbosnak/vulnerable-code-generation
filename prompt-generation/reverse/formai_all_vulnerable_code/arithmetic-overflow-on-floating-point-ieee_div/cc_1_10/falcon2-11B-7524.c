//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Check if the directory to be analyzed is provided as a command line argument
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Get the path to the directory to be analyzed
    char *directory = argv[1];

    // Check if the directory exists
    if (access(directory, F_OK)!= 0)
    {
        fprintf(stderr, "Error: Directory '%s' does not exist\n", directory);
        return 1;
    }

    // Get the current working directory
    char *cwd = getcwd(NULL, 0);

    // Check if the directory to be analyzed is a subdirectory of the current working directory
    if (strcmp(cwd, directory)!= 0)
    {
        fprintf(stderr, "Error: Directory '%s' is not a subdirectory of the current working directory\n", directory);
        return 1;
    }

    // Get the total disk space available on the system
    struct stat st;
    if (stat("/", &st)!= 0)
    {
        fprintf(stderr, "Error: Failed to get total disk space available on the system\n");
        return 1;
    }

    // Get the total disk space used on the system
    struct stat st_used;
    if (stat(directory, &st_used)!= 0)
    {
        fprintf(stderr, "Error: Failed to get total disk space used on the system\n");
        return 1;
    }

    // Calculate the percentage of disk space used
    double percentage_used = ((double)st_used.st_size * 100) / (double)st.st_size;

    // Print the results
    printf("Directory: %s\n", directory);
    printf("Total disk space available: %lu bytes\n", st.st_size);
    printf("Total disk space used: %lu bytes\n", st_used.st_size);
    printf("Percentage of disk space used: %f%%\n", percentage_used);

    return 0;
}