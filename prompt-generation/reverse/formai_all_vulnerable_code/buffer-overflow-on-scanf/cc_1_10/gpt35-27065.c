//FormAI DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

// Function to check if a file or directory exists
int checkExists(char *path)
{
    if (access(path, F_OK) == 0) {
        return 1;
    }
    return 0;
}

// Function to recursively copy files and directories
void copy(char *src, char *dest)
{
    DIR *d;
    struct dirent *dir;
    char srcPath[1000], destPath[1000];
    strcpy(srcPath, src);
    strcpy(destPath, dest);
    d = opendir(srcPath);
    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;
        strcat(srcPath, "/");
        strcat(srcPath, dir->d_name);
        strcat(destPath, "/");
        strcat(destPath, dir->d_name);
        if (dir->d_type == DT_DIR) {
            if (!checkExists(destPath)) {
                mkdir(destPath, 0777);
            }
            copy(srcPath, destPath);
        } else {
            FILE *fp1, *fp2;
            char c;
            fp1 = fopen(srcPath, "r");
            fp2 = fopen(destPath, "w");
            while ((c = fgetc(fp1)) != EOF) {
                fputc(c, fp2);
            }
            fclose(fp1);
            fclose(fp2);
        }
        strcpy(srcPath, src);
        strcpy(destPath, dest);
    }
    closedir(d);
}

int main(void)
{
    char src[1000], dest[1000];
    printf("Enter Source directory path: ");
    scanf("%s", src);
    printf("Enter Destination directory path: ");
    scanf("%s", dest);

    if (!checkExists(src)) {
        printf("Source directory does not exist!\n");
        return 0;
    }

    if (!checkExists(dest)) {
        mkdir(dest, 0777);
    }

    copy(src, dest);

    printf("Files synchronized successfully!\n");
    return 0;
}