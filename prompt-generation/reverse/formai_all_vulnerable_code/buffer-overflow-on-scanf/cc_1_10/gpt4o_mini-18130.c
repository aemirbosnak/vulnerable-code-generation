//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 30

typedef struct {
    char name[FILENAME_LENGTH];
    int size;
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void initializeFileSystem(FileSystem *fs) {
    fs->file_count = 0;
}

void createFile(FileSystem *fs, const char *name, int size) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Cannot create more files, limit reached!\n");
        return;
    }
    strcpy(fs->files[fs->file_count].name, name);
    fs->files[fs->file_count].size = size;
    fs->file_count++;
    printf("File '%s' of size %d created successfully.\n", name, size);
}

void deleteFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->file_count--;
            printf("File '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found!\n", name);
}

void listFiles(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("No files in the system.\n");
        return;
    }
    printf("Files in the system:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("Name: %s, Size: %d\n", fs->files[i].name, fs->files[i].size);
    }
}

void searchFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("File '%s' found. Size: %d\n", name, fs->files[i].size);
            return;
        }
    }
    printf("Error: File '%s' not found!\n", name);
}

void menu() {
    printf("\nFile System Simulation\n");
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
    char filename[FILENAME_LENGTH];
    int size;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter file size: ");
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
                searchFile(&fs, filename);
                break;

            case 5:
                printf("Exiting the file system simulation.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again!\n");
        }
    }

    return 0;
}