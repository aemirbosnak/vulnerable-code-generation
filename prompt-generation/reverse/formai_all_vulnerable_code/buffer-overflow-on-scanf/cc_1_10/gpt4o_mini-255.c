//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 100
#define MAX_FILENAME 50

typedef struct {
    char name[MAX_FILENAME];
    bool isDir;
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} Directory;

void initializeDirectory(Directory *dir) {
    dir->count = 0;
}

bool addFile(Directory *dir, const char *name, bool isDir) {
    if (dir->count >= MAX_FILES) {
        printf("Directory is full! Unable to add %s.\n", name);
        return false;
    }
    strcpy(dir->files[dir->count].name, name);
    dir->files[dir->count].isDir = isDir;
    dir->count++;
    return true;
}

void listFiles(Directory *dir) {
    if (dir->count == 0) {
        printf("Directory is empty!\n");
        return;
    }
    printf("Contents of Directory:\n");
    for (int i = 0; i < dir->count; i++) {
        printf("%s [%s]\n", dir->files[i].name, dir->files[i].isDir ? "DIR" : "FILE");
    }
    printf("\n");
}

bool fileExists(Directory *dir, const char *name) {
    for (int i = 0; i < dir->count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

void createFile(Directory *dir) {
    char name[MAX_FILENAME];
    printf("Enter the name of the file to create: ");
    scanf("%s", name);
    
    if (fileExists(dir, name)) {
        printf("File %s already exists!\n", name);
        return;
    }
    
    addFile(dir, name, false);
    printf("File %s created successfully!\n", name);
}

void createDirectory(Directory *dir) {
    char name[MAX_FILENAME];
    printf("Enter the name of the directory to create: ");
    scanf("%s", name);
    
    if (fileExists(dir, name)) {
        printf("Directory %s already exists!\n", name);
        return;
    }

    addFile(dir, name, true);
    printf("Directory %s created successfully!\n", name);
}

void searchFile(Directory *dir) {
    char name[MAX_FILENAME];
    printf("Enter the name of the file or directory to search: ");
    scanf("%s", name);
    
    if (fileExists(dir, name)) {
        printf("%s found in the current directory!\n", name);
    } else {
        printf("%s not found in the current directory!\n", name);
    }
}

void simulateFileExplorer() {
    Directory dir;
    initializeDirectory(&dir);
    int choice;

    do {
        printf("=== Bizarre File Explorer ===\n");
        printf("1. List Files\n");
        printf("2. Create File\n");
        printf("3. Create Directory\n");
        printf("4. Search File/Directory\n");
        printf("5. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listFiles(&dir);
                break;
            case 2:
                createFile(&dir);
                break;
            case 3:
                createDirectory(&dir);
                break;
            case 4:
                searchFile(&dir);
                break;
            case 5:
                printf("Exiting the Bizarre File Explorer. Farewell!\n");
                break;
            default:
                printf("Invalid selection! Please choose again.\n");
        }
        printf("\n");
    } while (choice != 5);
}

int main() {
    simulateFileExplorer();
    return 0;
}