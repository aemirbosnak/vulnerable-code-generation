//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <math.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

void printSize(double size) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int index = 0;

    while (size >= 1024) {
        size /= 1024;
        index++;
    }

    printf("%.2lf %s\n", size, units[index]);
}

void analyzeDiskSpace(char* folderPath) {
    DIR* dir = opendir(folderPath);

    if (dir == NULL) {
        printf("Could not open directory \"%s\"\n", folderPath);
        return;
    }

    struct dirent* entry;
    struct stat st;
    double totalSize = 0;

    while ((entry = readdir(dir)) != NULL) {
        char filePath[1024];
        strcpy(filePath, folderPath);
        strcat(filePath, "/");
        strcat(filePath, entry->d_name);
        stat(filePath, &st);

        if (S_ISDIR(st.st_mode) && (strcmp(entry->d_name, ".") != 0) && (strcmp(entry->d_name, "..") != 0)) {
            analyzeDiskSpace(filePath);
        } else {
            totalSize += st.st_size;
        }
    }
    
    printf("Total size of \"%s\": ", folderPath);
    printSize(totalSize);
    closedir(dir);
}

int main() {
    printf("Enter folder path: ");
    char folderPath[1024];
    fgets(folderPath, 1024, stdin);
    folderPath[strlen(folderPath)-1] = '\0';

    analyzeDiskSpace(folderPath);

    return 0;
}