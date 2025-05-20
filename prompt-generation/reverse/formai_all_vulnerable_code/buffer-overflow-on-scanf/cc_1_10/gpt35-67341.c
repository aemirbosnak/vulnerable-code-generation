//FormAI DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to compare directories
int compareDirs(char *sourceDir, char *targetDir) {

    // Open both directories
    DIR *source = opendir(sourceDir);
    DIR *target = opendir(targetDir);

    // Error handling
    if (source == NULL || target == NULL) {
        return -1;
    }

    // Loop through all files in source
    struct dirent *entry;
    while ((entry = readdir(source)) != NULL) {

        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if file exists in target
        char sourceFile[256];
        char targetFile[256];
        sprintf(sourceFile, "%s/%s", sourceDir, entry->d_name);
        sprintf(targetFile, "%s/%s", targetDir, entry->d_name);

        struct stat sourceStats;
        struct stat targetStats;
        if (stat(sourceFile, &sourceStats) != 0) {
            continue;
        }

        if (stat(targetFile, &targetStats) != 0) {
            return 1;
        }

        // Check if source file is newer than target file
        if (sourceStats.st_mtime > targetStats.st_mtime) {
            return 1;
        }
        
        // Check if entry is a directory
        if (entry->d_type == DT_DIR) {
            // Recursively check the subdirectory
            if (compareDirs(sourceFile, targetFile) == 1) {
                return 1;
            }
        }

    }

    // Close both directories
    closedir(source);
    closedir(target);

    return 0;
}

// Function to synchronize directories
void syncDirs(char *sourceDir, char *targetDir) {

    // Open both directories
    DIR *source = opendir(sourceDir);
    DIR *target = opendir(targetDir);

    // Error handling
    if (source == NULL || target == NULL) {
        return;
    }

    // Loop through all files in source
    struct dirent *entry;
    while ((entry = readdir(source)) != NULL) {

        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if file exists in target
        char sourceFile[256];
        char targetFile[256];
        sprintf(sourceFile, "%s/%s", sourceDir, entry->d_name);
        sprintf(targetFile, "%s/%s", targetDir, entry->d_name);

        struct stat sourceStats;
        struct stat targetStats;
        if (stat(sourceFile, &sourceStats) != 0) {
            continue;
        }

        if (stat(targetFile, &targetStats) != 0) {
            // File doesn't exist in target - copy it over
            FILE *sourcePtr = fopen(sourceFile, "r");
            FILE *targetPtr = fopen(targetFile, "w");

            char ch;
            while ((ch = fgetc(sourcePtr)) != EOF) {
                fputc(ch, targetPtr);
            }

            fclose(sourcePtr);
            fclose(targetPtr);

        } else {
            // File already exists in target - check if it's newer
            if (sourceStats.st_mtime > targetStats.st_mtime) {
                // Overwrite target file with source file
                FILE *sourcePtr = fopen(sourceFile, "r");
                FILE *targetPtr = fopen(targetFile, "w");

                char ch;
                while ((ch = fgetc(sourcePtr)) != EOF) {
                    fputc(ch, targetPtr);
                }

                fclose(sourcePtr);
                fclose(targetPtr);
            }
        }
        
        // Check if entry is a directory
        if (entry->d_type == DT_DIR) {
            // Recursively synchronize the subdirectory
            syncDirs(sourceFile, targetFile);
        }
    }

    // Close both directories
    closedir(source);
    closedir(target);
}

int main() {
    char sourceDir[256];
    char targetDir[256];

    // Prompt user for source and target directory paths
    printf("Enter source directory: ");
    scanf("%s", sourceDir);
    printf("Enter target directory: ");
    scanf("%s", targetDir);

    // Check if directories are different - sync if necessary
    if (compareDirs(sourceDir, targetDir) == 1) {
        printf("Synchronizing directories...\n");
        syncDirs(sourceDir, targetDir);
        printf("Done.\n");
    } else {
        printf("Directories are already synchronized.\n");
    }

    return 0;
}