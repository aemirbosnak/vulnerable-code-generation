//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50

typedef struct File {
    char name[FILENAME_LENGTH];
    int size; // in bytes
} File;

typedef struct FileSystem {
    File files[MAX_FILES];
    int fileCount;
} FileSystem;

void initializeFileSystem(FileSystem* fs) {
    fs->fileCount = 0;
}

int createFile(FileSystem* fs, const char* filename, int size) {
    if (fs->fileCount >= MAX_FILES) {
        printf("Error: File system is full.\n");
        return -1;
    }
    strncpy(fs->files[fs->fileCount].name, filename, FILENAME_LENGTH);
    fs->files[fs->fileCount].size = size;
    fs->fileCount++;
    return 0;
}

int deleteFile(FileSystem* fs, const char* filename) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            for (int j = i; j < fs->fileCount - 1; j++) {
                fs->files[j] = fs->files[j + 1]; // shift files left
            }
            fs->fileCount--;
            return 0;
        }
    }
    printf("Error: File '%s' not found.\n", filename);
    return -1;
}

void displayFiles(const FileSystem* fs) {
    if (fs->fileCount == 0) {
        printf("File system is empty.\n");
        return;
    }
    printf("Files in the file system:\n");
    for (int i = 0; i < fs->fileCount; i++) {
        printf("  %s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

void menu() {
    printf("File System Menu:\n");
    printf("1. Create a file\n");
    printf("2. Delete a file\n");
    printf("3. Display files\n");
    printf("4. Exit\n");
}

int main() {
    FileSystem fs;
    initializeFileSystem(&fs);
    int choice;
    char filename[FILENAME_LENGTH];
    int size;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter file size in bytes: ");
                scanf("%d", &size);
                if (createFile(&fs, filename, size) == 0) {
                    printf("File '%s' created successfully.\n", filename);
                }
                break;

            case 2:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                if (deleteFile(&fs, filename) == 0) {
                    printf("File '%s' deleted successfully.\n", filename);
                }
                break;

            case 3:
                displayFiles(&fs);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}