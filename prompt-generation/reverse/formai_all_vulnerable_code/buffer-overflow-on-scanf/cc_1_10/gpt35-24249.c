//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <math.h>

unsigned long long getTotalSize(char *path);
void displaySize(unsigned long long size);

int main()
{
    char path[10000];
    printf("Enter the path of the directory you want to analyze:\n");
    scanf("%s", path);

    unsigned long long totalSize = getTotalSize(path);
    printf("\nTotal space occupied by the directory: ");
    displaySize(totalSize);
}

unsigned long long getTotalSize(char *path)
{
    DIR *dir = opendir(path);

    if (!dir) 
    {
        printf("Unable to find the directory.");
        exit(EXIT_FAILURE);
    }

    struct dirent *de;
    unsigned long long totalSize = 0;

    while ((de = readdir(dir)) != NULL)
    {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
        {
            continue;
        }

        char filePath[10000];
        sprintf(filePath, "%s/%s", path, de->d_name);

        struct stat st;

        if (stat(filePath, &st) == -1) 
        {
            printf("Unable to access the file or directory: %s", de->d_name);
            continue;
        }

        if (S_ISDIR(st.st_mode))
        {
            totalSize += getTotalSize(filePath);
        }
        else 
        {
            totalSize += st.st_size;
        }
    }

    closedir(dir);

    return totalSize;
}

void displaySize(unsigned long long size) 
{
    char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int i;
    double base = log(size) / log(1024);

    if (size == 0)
    {
        printf("0 B");
        return;
    }

    if (base < 1)
    {
        printf("%d B", (int) size);
        return;
    }

    i = (int) floor(base);

    size = size / pow(1024, i);

    printf("%.2lf %s", size, units[i]);
}