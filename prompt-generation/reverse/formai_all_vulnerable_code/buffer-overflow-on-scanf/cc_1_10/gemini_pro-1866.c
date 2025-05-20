//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: expert-level
// File Backup System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

// Function to compare two files
int compareFiles(FILE *f1, FILE *f2) {
    int ch1, ch2;
    do {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
        if (ch1 != ch2)
            return 0;
    } while (ch1 != EOF && ch2 != EOF);
    return 1;
}

// Function to copy a file
void copyFile(const char *source, const char *destination) {
    FILE *f1, *f2;
    f1 = fopen(source, "r");
    f2 = fopen(destination, "w");
    char ch;
    while ((ch = fgetc(f1)) != EOF) {
        fputc(ch, f2);
    }
    fclose(f1);
    fclose(f2);
}

// Function to delete a file
void deleteFile(const char *path) {
    remove(path);
}

// Function to create a directory
void createDirectory(const char *path) {
    mkdir(path, 0777);
}

// Function to get the current time
void getCurrentTime(char *buffer) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);
}

// Main function
int main() {
    // Source directory
    char sourceDir[100];
    printf("Enter the source directory: ");
    scanf("%s", sourceDir);

    // Destination directory
    char destinationDir[100];
    printf("Enter the destination directory: ");
    scanf("%s", destinationDir);

    // Create the destination directory if it doesn't exist
    createDirectory(destinationDir);

    // Open the source directory
    DIR *d = opendir(sourceDir);
    if (d == NULL) {
        printf("Error opening source directory\n");
        return 1;
    }

    // Iterate over the files in the source directory
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        // Ignore hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the file paths
        char sourcePath[100];
        sprintf(sourcePath, "%s/%s", sourceDir, entry->d_name);
        char destinationPath[100];
        sprintf(destinationPath, "%s/%s", destinationDir, entry->d_name);

        // Check if the destination file exists
        FILE *f1 = fopen(destinationPath, "r");
        if (f1 != NULL) {
            // Compare the files
            FILE *f2 = fopen(sourcePath, "r");
            int same = compareFiles(f1, f2);
            fclose(f1);
            fclose(f2);

            // If the files are the same, delete the destination file
            if (same) {
                printf("File %s is the same. Deleting the destination file.\n", entry->d_name);
                deleteFile(destinationPath);
            } else {
                // Get the current time
                char time[50];
                getCurrentTime(time);

                // Create a backup file with the current time
                sprintf(destinationPath, "%s/%s.%s", destinationDir, entry->d_name, time);
                printf("File %s is different. Creating a backup file: %s\n", entry->d_name, destinationPath);
                copyFile(sourcePath, destinationPath);
            }
        } else {
            printf("File %s is not found in the destination directory. Copying the file.\n", entry->d_name);
            copyFile(sourcePath, destinationPath);
        }
    }

    // Close the source directory
    closedir(d);

    return 0;
}