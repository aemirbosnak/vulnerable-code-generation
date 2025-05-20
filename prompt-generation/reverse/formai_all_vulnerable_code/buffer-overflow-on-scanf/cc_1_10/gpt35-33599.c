//FormAI DATASET v1.0 Category: File Synchronizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void syncFiles(char* srcPath, char* destPath) {
    DIR* dir = opendir(srcPath);
    if (dir == NULL) {
        printf("Error opening source directory.\n");
        return;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char srcFilePath[1000], destFilePath[1000];
        sprintf(srcFilePath, "%s/%s", srcPath, entry->d_name);
        sprintf(destFilePath, "%s/%s", destPath, entry->d_name);
        
        struct stat srcFileStat, destFileStat;
        stat(srcFilePath, &srcFileStat);
        stat(destFilePath, &destFileStat);
        
        if (S_ISDIR(srcFileStat.st_mode)) {
            if (!S_ISDIR(destFileStat.st_mode)) {
                mkdir(destFilePath, srcFileStat.st_mode);
            }
            syncFiles(srcFilePath, destFilePath);
        } else if (S_ISREG(srcFileStat.st_mode)) {
            if (!S_ISREG(destFileStat.st_mode)) {
                FILE* destFile = fopen(destFilePath, "wb");
                fclose(destFile);
            }
            
            if (srcFileStat.st_mtime > destFileStat.st_mtime) {
                FILE* srcFile = fopen(srcFilePath, "rb");
                FILE* destFile = fopen(destFilePath, "wb");
                
                char buffer[1024];
                size_t len;
                while ((len = fread(buffer, 1, sizeof(buffer), srcFile))) {
                    fwrite(buffer, 1, len, destFile);
                }
                
                fclose(srcFile);
                fclose(destFile);
            }
        }
    }
    
    closedir(dir);
}

int main() {
    char srcPath[1000], destPath[1000];
    printf("Enter source directory path: ");
    scanf("%s", srcPath);
    printf("Enter destination directory path: ");
    scanf("%s", destPath);
    
    syncFiles(srcPath, destPath);
    
    printf("File synchronization complete.\n");
    
    return 0;
}