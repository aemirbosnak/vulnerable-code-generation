//FormAI DATASET v1.0 Category: File Synchronizer ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void syncFolder(char *source, char *destination) {
    DIR *sourceDir = opendir(source);
    if (sourceDir == NULL) {
        perror("Error opening source directory\n");
        exit(EXIT_FAILURE);
    }
    DIR *destinationDir = opendir(destination);
    if (destinationDir == NULL) {
        perror("Error opening destination directory\n");
        exit(EXIT_FAILURE);
    }
    struct dirent *sourceEntry, *destinationEntry;
    while ((sourceEntry = readdir(sourceDir)) != NULL) {
        char sourcePath[100], destinationPath[100];
        if (strcmp(sourceEntry->d_name, ".") == 0 || strcmp(sourceEntry->d_name, "..") == 0) {
            continue;
        }
        strcpy(sourcePath, source);
        strcat(sourcePath, "/");
        strcat(sourcePath, sourceEntry->d_name);
        int isFile = 0;
        struct stat s;
        stat(sourcePath, &s);
        if (S_ISREG(s.st_mode)) {
            isFile = 1;
        }
        destinationEntry = readdir(destinationDir);
        while (destinationEntry != NULL) {
            if (strcmp(destinationEntry->d_name, ".") == 0 || strcmp(destinationEntry->d_name, "..") == 0) {
                destinationEntry = readdir(destinationDir);
                continue;
            }
            strcpy(destinationPath, destination);
            strcat(destinationPath, "/");
            strcat(destinationPath, destinationEntry->d_name);
            struct stat s1;
            stat(destinationPath, &s1);
            if (!isFile && S_ISDIR(s1.st_mode) && strcmp(sourceEntry->d_name, destinationEntry->d_name) == 0) {
                syncFolder(sourcePath, destinationPath);
                break;
            } else if (isFile && S_ISREG(s1.st_mode) && strcmp(sourceEntry->d_name, destinationEntry->d_name) == 0) {
                FILE *sourceFile = fopen(sourcePath, "r");
                FILE *destinationFile = fopen(destinationPath, "r");
                if (sourceFile == NULL) {
                    perror("Error opening source file\n");
                    exit(EXIT_FAILURE);
                }
                if (destinationFile == NULL) {
                    destinationFile = fopen(destinationPath, "w");
                    fprintf(destinationFile, "%s", "");
                    fclose(destinationFile);
                    destinationFile = fopen(destinationPath, "r+");
                }
                fseek(destinationFile, 0L, SEEK_END);
                long int destinationSize = ftell(destinationFile);
                fseek(destinationFile, 0L, SEEK_SET);
                long int sourceSize = s.st_size;
                char *sourceData = malloc(sourceSize);
                fread(sourceData, 1, sourceSize, sourceFile);
                char *destinationData = malloc(destinationSize);
                fread(destinationData, 1, destinationSize, destinationFile);
                if (strcmp(sourceData, destinationData) != 0) {
                    fseek(destinationFile, 0L, SEEK_SET);
                    fwrite(sourceData, 1, sourceSize, destinationFile);
                    printf("File %s updated.\n", destinationPath);
                }
                fclose(sourceFile);
                fclose(destinationFile);
                break;
            }
            destinationEntry = readdir(destinationDir);
        }
        if (destinationEntry == NULL) {
            strcpy(destinationPath, destination);
            strcat(destinationPath, "/");
            strcat(destinationPath, sourceEntry->d_name);
            if (isFile) {
                FILE *destinationFile = fopen(destinationPath, "w");
                FILE *sourceFile = fopen(sourcePath, "r");
                if (sourceFile == NULL) {
                    perror("Error opening source file\n");
                    exit(EXIT_FAILURE);
                }
                long int sourceSize = s.st_size;
                char *sourceData = malloc(sourceSize);
                fread(sourceData, 1, sourceSize, sourceFile);
                fwrite(sourceData, 1, sourceSize, destinationFile);
                printf("File %s added.\n", destinationPath);
                fclose(sourceFile);
                fclose(destinationFile);
            } else {
                mkdir(destinationPath, 0777);
                syncFolder(sourcePath, destinationPath);
            }
        }
    }
    closedir(sourceDir);
    closedir(destinationDir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid number of arguments.\nUsage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    syncFolder(argv[1], argv[2]);
    return 0;
}