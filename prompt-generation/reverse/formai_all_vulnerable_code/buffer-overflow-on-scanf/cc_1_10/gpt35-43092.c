//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Function to convert bytes to human-readable format
void convertSize(long int size, char *result) {
    double val = size;
    int cnt = 0;
    char *units[] = {"B", "KB", "MB", "GB", "TB"};

    while (val >= 1024 && cnt < 4){
        val /= 1024;
        cnt++;
    }

    sprintf(result, "%.2f %s", val, units[cnt]);
}

// Function to check if pathname is a directory
int isdir(char *pathname) {
    struct stat path_stat;
    stat(pathname, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

// Function to calculate the size of a directory recursively
long int dirSize(char *path) {
    long int size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL)
        return 0;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char *name = entry->d_name;

        // Skip the "." and ".." directories
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
            continue;

        // Get the full path of the file/directory
        char pathbuf[1024];
        snprintf(pathbuf, sizeof(pathbuf), "%s/%s", path, name);
        
        if (isdir(pathbuf)) {
            // The path is a directory, so call recursively
            size += dirSize(pathbuf);
        } else {
            // The path is a file, so add its size to the total
            struct stat st;
            if (stat(pathbuf, &st) == 0)
                size += st.st_size;
        }
    }
    closedir(dir);

    return size;
}

int main() {
    char path[1024];
    printf("Enter a path to analyze: ");
    scanf("%s", path);

    printf("Analyzing disk usage of \"%s\"...\n", path);

    long int size = dirSize(path);
    char result[50];
    convertSize(size, result);

    printf("Disk usage: %s\n", result);

    return 0;
}