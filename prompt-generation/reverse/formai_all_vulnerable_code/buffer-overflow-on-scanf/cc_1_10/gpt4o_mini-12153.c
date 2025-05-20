//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size; // size in bytes
} File;

typedef struct {
    File files[MAX_FILES];
    int fileCount;
} FileSystem;

void initializeFileSystem(FileSystem *fs) {
    fs->fileCount = 0;
}

void createFile(FileSystem *fs) {
    if (fs->fileCount >= MAX_FILES) {
        printf("File system is full. Cannot create new file.\n");
        return;
    }
    
    char filename[MAX_FILENAME_LENGTH];
    int size;

    printf("Enter filename (max %d characters): ", MAX_FILENAME_LENGTH - 1);
    scanf("%s", filename);

    printf("Enter file size (in bytes): ");
    scanf("%d", &size);
    
    // Check for duplicate file names
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("Error: File with the name '%s' already exists.\n", filename);
            return;
        }
    }

    strcpy(fs->files[fs->fileCount].name, filename);
    fs->files[fs->fileCount].size = size;
    fs->fileCount++;

    printf("File '%s' created with size %d bytes.\n", filename, size);
}

void deleteFile(FileSystem *fs) {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter the filename to delete: ");
    scanf("%s", filename);
    
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            // Found the file, shift subsequent files left
            for (int j = i; j < fs->fileCount - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->fileCount--;
            printf("File '%s' deleted successfully.\n", filename);
            return;
        }
    }

    printf("Error: File '%s' not found.\n", filename);
}

void listFiles(const FileSystem *fs) {
    if (fs->fileCount == 0) {
        printf("No files in the file system.\n");
        return;
    }

    printf("List of files:\n");
    for (int i = 0; i < fs->fileCount; i++) {
        printf("Filename: %s, Size: %d bytes\n", fs->files[i].name, fs->files[i].size);
    }
}

void showMenu() {
    printf("\n--- Simple File System Menu ---\n");
    printf("1. Create File\n");
    printf("2. Delete File\n");
    printf("3. List Files\n");
    printf("4. Exit\n");
}

int main() {
    FileSystem fs;
    initializeFileSystem(&fs);
    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(&fs);
                break;
            case 2:
                deleteFile(&fs);
                break;
            case 3:
                listFiles(&fs);
                break;
            case 4:
                printf("Exiting the file system simulation.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}