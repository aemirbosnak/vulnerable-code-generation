//FormAI DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void syncFiles(char *srcPrefix, char *destPrefix);

int main() {
    char srcPrefix[100], destPrefix[100];
    printf("Enter source directory prefix: ");
    scanf("%s", srcPrefix);
    printf("Enter destination directory prefix: ");
    scanf("%s", destPrefix);
    syncFiles(srcPrefix, destPrefix);
    printf("File synchronization complete!\n");
    return 0;
}

void syncFiles(char *srcPrefix, char *destPrefix) {
    DIR *srcDir, *destDir;
    char srcPath[200], destPath[200];
    struct dirent *d;
    struct stat srcStat, destStat;
    srcDir = opendir(srcPrefix);
    destDir = opendir(destPrefix);
    while ((d = readdir(srcDir)) != NULL) {
        if (d->d_name[0] != '.') {
            sprintf(srcPath, "%s/%s", srcPrefix, d->d_name);
            stat(srcPath, &srcStat);
            if (S_ISDIR(srcStat.st_mode)) { // if directory
                sprintf(destPath, "%s/%s", destPrefix, d->d_name);
                if (stat(destPath, &destStat) != 0) { // if directory doesn't exist
                    mkdir(destPath, 0700); // create directory
                }
                syncFiles(srcPath, destPath); // sync directory
            } else { // if file
                sprintf(destPath, "%s/%s", destPrefix, d->d_name);
                if (stat(destPath, &destStat) != 0 || srcStat.st_mtime > destStat.st_mtime) { // if file doesn't exist or source file is newer
                    FILE *srcFile, *destFile;
                    srcFile = fopen(srcPath, "r");
                    destFile = fopen(destPath, "w");
                    char c;
                    while ((c = fgetc(srcFile)) != EOF) { // copy file contents
                        fputc(c, destFile);
                    }
                    fclose(srcFile);
                    fclose(destFile);
                }
            }
        }
    }
    closedir(srcDir);
    closedir(destDir);
}