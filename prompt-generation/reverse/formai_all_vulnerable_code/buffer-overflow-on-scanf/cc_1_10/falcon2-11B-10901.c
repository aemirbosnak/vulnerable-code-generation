//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char sourcePath[100], destPath[100];
    DIR *dir;
    struct dirent *entry;

    printf("Enter the source path: ");
    scanf("%s", sourcePath);
    printf("Enter the destination path: ");
    scanf("%s", destPath);

    dir = opendir(sourcePath);
    if (dir == NULL) {
        perror("Failed to open source directory");
        return 1;
    }

    while ((entry = readdir(dir))!= NULL) {
        char fileName[100];
        struct stat fileInfo;

        snprintf(fileName, sizeof(fileName), "%s/%s", sourcePath, entry->d_name);
        stat(fileName, &fileInfo);

        if (S_ISREG(fileInfo.st_mode)) {
            char destFileName[100];
            snprintf(destFileName, sizeof(destFileName), "%s/%s", destPath, entry->d_name);
            FILE *srcFile, *destFile;

            srcFile = fopen(fileName, "rb");
            destFile = fopen(destFileName, "wb");
            if (srcFile == NULL || destFile == NULL) {
                perror("Failed to open file for reading or writing");
                continue;
            }

            if (fread(destFile, 1, fileInfo.st_size, srcFile)!= fileInfo.st_size) {
                perror("Failed to read file");
                fclose(srcFile);
                fclose(destFile);
            }
            fclose(srcFile);
            fclose(destFile);
        }
    }
    closedir(dir);

    return 0;
}