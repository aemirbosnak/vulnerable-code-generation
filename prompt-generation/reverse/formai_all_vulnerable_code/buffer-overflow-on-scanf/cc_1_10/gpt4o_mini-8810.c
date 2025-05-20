//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 255

typedef struct {
    char name[FILENAME_LENGTH];
    int size;  // Size in KB
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} FileSystem;

void initializeFileSystem(FileSystem *fs) {
    fs->count = 0;
}

int createFile(FileSystem *fs, const char *name, int size) {
    if (fs->count >= MAX_FILES) {
        printf("File system full, cannot create new file.\n");
        return -1;
    }
    strncpy(fs->files[fs->count].name, name, FILENAME_LENGTH);
    fs->files[fs->count].size = size;
    fs->count++;
    printf("File '%s' created successfully.\n", name);
    return 0;
}

int deleteFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            for (int j = i; j < fs->count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->count--;
            printf("File '%s' deleted successfully.\n", name);
            return 0;
        }
    }
    printf("File '%s' not found.\n", name);
    return -1;
}

void listFiles(const FileSystem *fs) {
    printf("\nList of files in the file system:\n");
    if (fs->count == 0) {
        printf("No files found.\n");
        return;
    }
    for (int i = 0; i < fs->count; i++) {
        printf("File: %s, Size: %d KB\n", fs->files[i].name, fs->files[i].size);
    }
}

File* searchFile(const FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            return (File *)&fs->files[i];
        }
    }
    return NULL;
}

void getFileDetails(const File *file) {
    printf("Details of file:\n");
    printf("Name: %s\n", file->name);
    printf("Size: %d KB\n", file->size);
}

void menu() {
    printf("\nFile System Menu:\n");
    printf("1. Create File\n");
    printf("2. Delete File\n");
    printf("3. List Files\n");
    printf("4. Search File\n");
    printf("5. Exit\n");
}

int main() {
    FileSystem fs;
    initializeFileSystem(&fs);
    int choice;
    
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        
        char filename[FILENAME_LENGTH];
        int size;

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter file size (in KB): ");
                scanf("%d", &size);
                createFile(&fs, filename, size);
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", filename);
                deleteFile(&fs, filename);
                break;
            case 3:
                listFiles(&fs);
                break;
            case 4:
                printf("Enter file name to search: ");
                scanf("%s", filename);
                File *file = searchFile(&fs, filename);
                if (file) {
                    getFileDetails(file);
                } else {
                    printf("File '%s' not found.\n", filename);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                break;
        }
    } while (choice != 5);

    return 0;
}