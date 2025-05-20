//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define GB_SIZE 1073741824
#define MB_SIZE 1048576
#define KB_SIZE 1024

// Function to get the folder size
long long int getFolderSize(char *path) {
    long long int folderSize = 0;
    struct stat st;
    char *filePath = malloc(sizeof(char) * 200);
    DIR *dir = opendir(path);
    struct dirent *entry;
    
    if (dir == NULL) {
        free(filePath);
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            sprintf(filePath, "%s/%s", path, entry->d_name);

            if (stat(filePath, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    folderSize += getFolderSize(filePath);
                } else {
                    folderSize += st.st_size;
                }
            }
        }
    }

    closedir(dir);
    free(filePath);
    return folderSize;
}

// Function to print the folder size in a friendly format
void printSize(long long int size) {
    if (size >= GB_SIZE) {
        printf("%.2f GB\n", (float) size / GB_SIZE);
    } else if (size >= MB_SIZE) {
        printf("%.2f MB\n", (float) size / MB_SIZE);
    } else if (size >= KB_SIZE) {
        printf("%.2f KB\n", (float) size / KB_SIZE);
    } else {
        printf("%lld bytes\n", size);
    }
}

int main() {
    char *path = malloc(sizeof(char) * 200);

    printf("Enter the path to analyze: ");
    scanf("%s", path);

    long long int folderSize = getFolderSize(path);
    printf("Folder size: ");
    printSize(folderSize);

    free(path);
    return 0;
}