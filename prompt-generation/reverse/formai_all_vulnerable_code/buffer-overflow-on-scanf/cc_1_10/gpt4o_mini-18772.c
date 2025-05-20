//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50

typedef struct {
    char name[FILENAME_LENGTH];
    int size; // size in bytes
} File;

typedef struct {
    File files[MAX_FILES];
    int fileCount;
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->fileCount = 0;
}

void createFile(FileSystem *fs, const char *name, int size) {
    if (fs->fileCount >= MAX_FILES) {
        printf("Error: File system is full!\n");
        return;
    }
    strcpy(fs->files[fs->fileCount].name, name);
    fs->files[fs->fileCount].size = size;
    fs->fileCount++;
    printf("File '%s' created with size %d bytes.\n", name, size);
}

void listFiles(const FileSystem *fs) {
    if (fs->fileCount == 0) {
        printf("No files in the system.\n");
        return;
    }
    printf("Files in the system:\n");
    for (int i = 0; i < fs->fileCount; i++) {
        printf("File %d: %s (Size: %d bytes)\n", i + 1, fs->files[i].name, fs->files[i].size);
    }
}

void deleteFile(FileSystem *fs, const char *name) {
    int found = -1;
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Error: File '%s' not found!\n", name);
        return;
    }
    
    // Shift files left to remove the deleted file
    for (int i = found; i < fs->fileCount - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->fileCount--;
    printf("File '%s' deleted successfully.\n", name);
}

void searchFile(const FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("File '%s' found with size %d bytes.\n", name, fs->files[i].size);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

void displayMenu() {
    printf("\nFile System Menu:\n");
    printf("1. Create File\n");
    printf("2. List Files\n");
    printf("3. Delete File\n");
    printf("4. Search File\n");
    printf("5. Exit\n");
}

int main() {
    FileSystem fs;
    initFileSystem(&fs);
    
    int choice, size;
    char name[FILENAME_LENGTH];
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", name);
                printf("Enter file size (in bytes): ");
                scanf("%d", &size);
                createFile(&fs, name, size);
                break;

            case 2:
                listFiles(&fs);
                break;

            case 3:
                printf("Enter filename to delete: ");
                scanf("%s", name);
                deleteFile(&fs, name);
                break;

            case 4:
                printf("Enter filename to search: ");
                scanf("%s", name);
                searchFile(&fs, name);
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}