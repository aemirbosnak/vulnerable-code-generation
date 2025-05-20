//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <dirent.h>
#include <sys/statvfs.h>

// Function to get directory size
unsigned int getDirSize(const char* dirPath)
{
    DIR* dir;
    struct dirent* entry;
    struct statvfs st;

    unsigned int totalSize = 0;

    dir = opendir(dirPath);

    if (dir == NULL)
    {
        printf("Error opening directory.\n");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        char fullPath[100];
        sprintf(fullPath, "%s/%s", dirPath, entry->d_name);

        // Getting the file stats
        if (statvfs(fullPath, &st) != 0)
        {
            printf("Error getting file stats.\n");
            return 0;
        }

        // Calculating directory size
        totalSize += st.f_frsize * st.f_blocks;
    }

    closedir(dir);

    return totalSize;
}

// Main function
int main()
{
    printf("==== C Disk Space Analyzer ====\n");

    // Selecting the directory to analyze
    char dirPath[100];
    printf("Enter the path of the directory to analyze: ");
    scanf("%s", dirPath);

    // Getting the directory size
    unsigned int dirSize = getDirSize(dirPath);

    // Converting the size to human-readable format
    char sizeSuffixes[] = {'B', 'K', 'M', 'G', 'T'};
    int sizeSuffixIndex = 0;

    while (dirSize > 1024 && sizeSuffixIndex < 4)
    {
        dirSize /= 1024;
        sizeSuffixIndex++;
    }

    // Printing the results
    printf("Directory size: %d %c\n", dirSize, sizeSuffixes[sizeSuffixIndex]);

    // Getting the free space on the disk
    struct statvfs st;
    if (statvfs(dirPath, &st) != 0)
    {
        printf("Error getting disk stats.\n");
        return 0;
    }

    unsigned int freeSpace = st.f_frsize * st.f_bfree;

    sizeSuffixIndex = 0;

    while (freeSpace > 1024 && sizeSuffixIndex < 4)
    {
        freeSpace /= 1024;
        sizeSuffixIndex++;
    }

    printf("Free space on disk: %d %c\n", freeSpace, sizeSuffixes[sizeSuffixIndex]);

    return 0;
}