//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Function to calculate file size in bytes
long long int calculateFileSize(char* filename){
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL){
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    long long int fileSize = ftell(fp);
    fclose(fp);
    return fileSize;
}

// Function to recursively traverse the directory and calculate size of all files & subdirectories
long long int traverseDirectory(char* path, int level, long long int* files, long long int* dirs){
    struct dirent* dp;
    struct stat st;
    DIR* dir = opendir(path);
    long long int totalSize = 0;
    if (!dir){
        return totalSize;
    }
    while ((dp = readdir(dir)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            char filePath[200];
            sprintf(filePath, "%s/%s", path, dp->d_name);
            if (stat(filePath, &st) == 0){
                if (S_ISDIR(st.st_mode)){
                    // It's a directory
                    (*dirs)++;
                    long long int subDirSize = traverseDirectory(filePath, level + 1, files, dirs);
                    totalSize += subDirSize;
                }
                else{
                    // It's a file
                    (*files)++;
                    long long int fileSize = calculateFileSize(filePath);
                    totalSize += fileSize;
                }
            }
        }
    }
    closedir(dir);
    return totalSize;
}

int main(){
    char path[200];
    printf("Enter the directory path: ");
    scanf("%s", path);
    long long int files = 0, dirs = 0;
    long long int totalSize = traverseDirectory(path, 0, &files, &dirs);
    printf("\nTotal Files: %lld", files);
    printf("\nTotal Directories: %lld", dirs);
    printf("\nTotal Disk Space Used: %lld bytes", totalSize);
    return 0;
}