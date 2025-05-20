//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int isDirectory;
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} Directory;

Directory root;

void initFileSystem() {
    root.count = 0;
}

void listFiles(Directory *dir) {
    if (dir->count == 0) {
        printf("No files or directories to display.\n");
        return;
    }
    printf("Files and directories:\n");
    for (int i = 0; i < dir->count; i++) {
        printf("%s %s\n", dir->files[i].isDirectory ? "[DIR]" : "[FILE]", dir->files[i].name);
    }
}

int createFile(Directory *dir, const char *name) {
    if (dir->count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return -1;
    }
    strcpy(dir->files[dir->count].name, name);
    dir->files[dir->count].isDirectory = 0; // 0 for file
    dir->count++;
    printf("File '%s' created successfully.\n", name);
    return 0;
}

int createDirectory(Directory *dir, const char *name) {
    if (dir->count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return -1;
    }
    strcpy(dir->files[dir->count].name, name);
    dir->files[dir->count].isDirectory = 1; // 1 for directory
    dir->count++;
    printf("Directory '%s' created successfully.\n", name);
    return 0;
}

int deleteFileOrDirectory(Directory *dir, const char *name) {
    for (int i = 0; i < dir->count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            for (int j = i; j < dir->count - 1; j++) {
                dir->files[j] = dir->files[j + 1];
            }
            dir->count--;
            printf("Deleted '%s' successfully.\n", name);
            return 0;
        }
    }
    printf("Error: '%s' not found.\n", name);
    return -1;
}

int main() {
    initFileSystem();
    
    int choice;
    char name[NAME_LENGTH];
    
    while (1) {
        printf("\nFile System Simulation\n");
        printf("1. List Files\n");
        printf("2. Create File\n");
        printf("3. Create Directory\n");
        printf("4. Delete File/Directory\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice) {
            case 1:
                listFiles(&root);
                break;
            case 2:
                printf("Enter file name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                createFile(&root, name);
                break;
            case 3:
                printf("Enter directory name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                createDirectory(&root, name);
                break;
            case 4:
                printf("Enter file/directory name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                deleteFileOrDirectory(&root, name);
                break;
            case 5:
                printf("Exiting the file system simulation.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}