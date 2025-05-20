//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILENAME_LENGTH 256
#define STORAGE_FILE "deleted_files.txt"
#define BUFFER_SIZE 1024

void displayMenu() {
    printf("Data Recovery Tool\n");
    printf("===================\n");
    printf("1. Discover Deleted Files\n");
    printf("2. Recover a File\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void discoverDeletedFiles() {
    FILE *file = fopen(STORAGE_FILE, "r");
    if (file == NULL) {
        printf("Failed to open storage file.\n");
        return;
    }

    char filename[MAX_FILENAME_LENGTH];
    printf("\nDeleted Files:\n");
    while (fgets(filename, sizeof(filename), file)) {
        // Remove newline character
        filename[strcspn(filename, "\n")] = 0;
        printf("- %s\n", filename);
    }
    fclose(file);
}

void recoverFile() {
    char filename[MAX_FILENAME_LENGTH];
    char destination[MAX_FILENAME_LENGTH];
    printf("Enter the filename to recover: ");
    scanf("%s", filename);
    printf("Enter the recovery destination directory: ");
    scanf("%s", destination);

    // Construct the path
    char sourcePath[MAX_FILENAME_LENGTH + BUFFER_SIZE];
    snprintf(sourcePath, sizeof(sourcePath), "%s/%s", ".", filename);

    // Open the storage file to check if the file exists
    FILE *storageFile = fopen(STORAGE_FILE, "r");
    if (storageFile == NULL) {
        printf("Failed to access storage file!\n");
        return;
    }

    char storedFilename[MAX_FILENAME_LENGTH];
    int fileFound = 0;
    while (fgets(storedFilename, sizeof(storedFilename), storageFile)) {
        storedFilename[strcspn(storedFilename, "\n")] = 0; // Remove newline
        if (strcmp(storedFilename, filename) == 0) {
            fileFound = 1; // File marked as deleted found
            break;
        }
    }
    fclose(storageFile);

    if (fileFound) {
        // Simulate copy operation
        char newPath[MAX_FILENAME_LENGTH + BUFFER_SIZE];
        snprintf(newPath, sizeof(newPath), "%s/%s", destination, filename);
        FILE *srcFile = fopen(sourcePath, "r");
        FILE *destFile = fopen(newPath, "w");

        if (srcFile == NULL || destFile == NULL) {
            printf("Error in file operation! Could not recover the file.\n");
            return;
        }

        char buffer[BUFFER_SIZE];
        while (fgets(buffer, sizeof(buffer), srcFile) != NULL) {
            fputs(buffer, destFile);
        }

        fclose(srcFile);
        fclose(destFile);
        printf("File '%s' recovered successfully to '%s'.\n", filename, destination);
    } else {
        printf("File '%s' not found in storage!\n", filename);
    }
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                discoverDeletedFiles();
                break;
            case 2:
                recoverFile();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}