//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILE_NAME_LENGTH 50

typedef struct {
    char name[FILE_NAME_LENGTH];
    int isUsed;
} File;

typedef struct {
    File files[MAX_FILES];
    int fileCount;
} Directory;

void displayMenu() {
    printf("\n===== Virtual File System =====\n");
    printf("1. Create File\n");
    printf("2. Delete File\n");
    printf("3. List Files\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("Enter your choice: ");
}

void createFile(Directory *directory) {
    if (directory->fileCount >= MAX_FILES) {
        printf("Error: Directory is full! Cannot create more files.\n");
        return;
    }
    
    char fileName[FILE_NAME_LENGTH];
    printf("Enter the file name (max %d characters): ", FILE_NAME_LENGTH - 1);
    scanf("%s", fileName);

    // Check if file already exists
    for (int i = 0; i < directory->fileCount; i++) {
        if (strcmp(directory->files[i].name, fileName) == 0) {
            printf("Error: File '%s' already exists!\n", fileName);
            return;
        }
    }

    // Create a new file
    strncpy(directory->files[directory->fileCount].name, fileName, FILE_NAME_LENGTH);
    directory->files[directory->fileCount].isUsed = 1;
    directory->fileCount++;
    printf("File '%s' created successfully!\n", fileName);
}

void deleteFile(Directory *directory) {
    if (directory->fileCount == 0) {
        printf("Error: No files to delete!\n");
        return;
    }

    char fileName[FILE_NAME_LENGTH];
    printf("Enter the file name to delete: ");
    scanf("%s", fileName);

    for (int i = 0; i < directory->fileCount; i++) {
        if (strcmp(directory->files[i].name, fileName) == 0) {
            // Delete the file by shifting files left
            for (int j = i; j < directory->fileCount - 1; j++) {
                directory->files[j] = directory->files[j + 1];
            }
            directory->fileCount--;
            printf("File '%s' deleted successfully!\n", fileName);
            return;
        }
    }
    printf("Error: File '%s' not found!\n", fileName);
}

void listFiles(Directory *directory) {
    if (directory->fileCount == 0) {
        printf("No files found in the directory!\n");
        return;
    }

    printf("\nList of Files:\n");
    for (int i = 0; i < directory->fileCount; i++) {
        printf("- %s\n", directory->files[i].name);
    }
}

int main() {
    Directory directory = { .fileCount = 0 };
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(&directory);
                break;
            case 2:
                deleteFile(&directory);
                break;
            case 3:
                listFiles(&directory);
                break;
            case 4:
                printf("Exiting the Virtual File System. Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}