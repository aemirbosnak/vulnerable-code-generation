//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILENAME_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size; // Size in bytes
    int isOpen; // Open or closed state
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->count = 0;
}

void createFile(FileSystem *fs, const char *filename, int size) {
    if (fs->count >= MAX_FILES) {
        printf("!!! ERROR: Maximum file limit reached. Can't create more files!\n");
        return;
    }
    
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            printf("!!! ERROR: File %s already exists!\n", filename);
            return;
        }
    }
    
    strcpy(fs->files[fs->count].filename, filename);
    fs->files[fs->count].size = size;
    fs->files[fs->count].isOpen = 0;
    fs->count++;
    
    printf("!!! Success: File %s created with size %d bytes.\n", filename, size);
}

void deleteFile(FileSystem *fs, const char *filename) {
    int found = 0;
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            found = 1;
            printf("!!! Warning: Deleting file %s...\n", filename);
            fs->files[i] = fs->files[fs->count - 1]; // Move last file into this slot
            fs->count--;
            break;
        }
    }

    if (!found) {
        printf("!!! ERROR: File %s not found!\n", filename);
    }
}

void openFile(FileSystem *fs, const char *filename) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            if (fs->files[i].isOpen) {
                printf("!!! ERROR: File %s is already open!\n", filename);
                return;
            }
            fs->files[i].isOpen = 1;
            printf("!!! Success: File %s opened.\n", filename);
            return;
        }
    }
    printf("!!! ERROR: File %s not found!\n", filename);
}

void closeFile(FileSystem *fs, const char *filename) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            if (!fs->files[i].isOpen) {
                printf("!!! ERROR: File %s is not open!\n", filename);
                return;
            }
            fs->files[i].isOpen = 0;
            printf("!!! Success: File %s closed.\n", filename);
            return;
        }
    }
    printf("!!! ERROR: File %s not found!\n", filename);
}

void listFiles(const FileSystem *fs) {
    if (fs->count == 0) {
        printf("!!! There are no files in the file system!\n");
        return;
    }
    printf("!!! Files in the file system:\n");
    for (int i = 0; i < fs->count; i++) {
        printf("- %s (%d bytes) %s\n", fs->files[i].filename, fs->files[i].size, fs->files[i].isOpen ? "[OPEN]" : "[CLOSED]");
    }
}

int main() {
    FileSystem fs;
    char command[100], filename[MAX_FILENAME_LENGTH];
    int size;

    initFileSystem(&fs);
    
    printf("!!! Welcome to the File System Simulation!\n");
    
    while (1) {
        printf(">>> Enter a command (create, delete, open, close, list, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "create") == 0) {
            printf("!!! Enter filename: ");
            scanf("%s", filename);
            printf("!!! Enter file size (in bytes): ");
            scanf("%d", &size);
            createFile(&fs, filename, size);
        }
        else if (strcmp(command, "delete") == 0) {
            printf("!!! Enter filename to delete: ");
            scanf("%s", filename);
            deleteFile(&fs, filename);
        }
        else if (strcmp(command, "open") == 0) {
            printf("!!! Enter filename to open: ");
            scanf("%s", filename);
            openFile(&fs, filename);
        }
        else if (strcmp(command, "close") == 0) {
            printf("!!! Enter filename to close: ");
            scanf("%s", filename);
            closeFile(&fs, filename);
        }
        else if (strcmp(command, "list") == 0) {
            listFiles(&fs);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("!!! Exiting the File System Simulation. Goodbye!\n");
            break;
        }
        else {
            printf("!!! ERROR: Unknown command: %s!\n", command);
        }
    }
    
    return 0;
}