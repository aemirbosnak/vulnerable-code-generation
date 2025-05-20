//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 50
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int size; // size in bytes
} File;

typedef struct {
    File files[MAX_FILES];
    int count; // current number of files
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->count = 0;
}

bool addFile(FileSystem *fs, const char *name, int size) {
    if (fs->count >= MAX_FILES) {
        printf("Shock! File System Full, can't add more files!\n");
        return false;
    }
    if (size <= 0) {
        printf("ಠ_ಠ Invalid file size for file '%s'. Can't add this file!\n", name);
        return false;
    }

    strcpy(fs->files[fs->count].name, name);
    fs->files[fs->count].size = size;
    fs->count++;
    printf("Whoa! File '%s' added with size %d bytes!\n", name, size);
    return true;
}

void listFiles(const FileSystem *fs) {
    if (fs->count == 0) {
        printf("Whoa! No files in the system!\n");
        return;
    }
    printf("Files List:\n");
    for (int i = 0; i < fs->count; i++) {
        printf(" %d. %s (%d bytes)\n", i + 1, fs->files[i].name, fs->files[i].size);
    }
}

bool deleteFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Shock! Deleting file '%s'...\n", fs->files[i].name);
            for (int j = i; j < fs->count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->count--;
            printf("File '%s' deleted successfully! 🎉\n", name);
            return true;
        }
    }
    printf("Oops! File '%s' not found!\n", name);
    return false;
}

int calculateTotalSize(const FileSystem *fs) {
    int totalSize = 0;
    for (int i = 0; i < fs->count; i++) {
        totalSize += fs->files[i].size;
    }
    return totalSize;
}

void showMenu() {
    printf("\n--------------------\n");
    printf("Shock File System Menu:\n");
    printf("1. Add File\n");
    printf("2. List Files\n");
    printf("3. Delete File\n");
    printf("4. Show Total Size\n");
    printf("5. Exit\n");
    printf("--------------------\n");
}

int main() {
    FileSystem fs;
    initFileSystem(&fs);

    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: {
                char name[NAME_LENGTH];
                int size;

                printf("Enter file name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter file size in bytes: ");
                scanf("%d", &size);

                addFile(&fs, name, size);
                break;
            }
            case 2:
                listFiles(&fs);
                break;
            case 3: {
                char name[NAME_LENGTH];
                printf("Enter file name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                deleteFile(&fs, name);
                break;
            }
            case 4:
                printf("Total size of files: %d bytes\n", calculateTotalSize(&fs));
                break;
            case 5:
                printf("Exiting Shock File System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Choose again!\n");
        }
    } while (choice != 5);

    return 0;
}