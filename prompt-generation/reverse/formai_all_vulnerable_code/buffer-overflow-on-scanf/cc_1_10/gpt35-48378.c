//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Function to recursively analyze the disk space
void analyzeDiskSpace(char *path, int depth, long *totalSize) {
    struct dirent *entry;
    struct stat info;
    DIR *dir = opendir(path);
    
    // Check if the directory exists
    if (dir == NULL) {
        printf("Cannot open directory %s\n", path);
        return;
    }
    
    // Loop through all the entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        char newPath[1024];
        sprintf(newPath, "%s/%s", path, entry->d_name);
        
        // Ignore "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Get the file/directory information
        if (lstat(newPath, &info) == -1) {
            printf("Could not get info for file %s\n", newPath);
            continue;
        }
        
        // If it is a directory, recursively call the function
        if (S_ISDIR(info.st_mode)) {
            printf("%*s%s/\n", depth * 2, "", entry->d_name);
            analyzeDiskSpace(newPath, depth + 1, totalSize);
        } else {
            printf("%*s%s\n", depth * 2, "", entry->d_name);
            *totalSize += info.st_size;
        }
    }
    
    closedir(dir);
}

int main() {
    char path[1024];
    printf("Enter the path to analyze:\n");
    scanf("%s", path);
    
    long totalSize = 0;
    printf("Analyzing disk space...\n");
    analyzeDiskSpace(path, 0, &totalSize);
    
    printf("Total size of %s is %ld bytes\n", path, totalSize);
    
    return 0;
}