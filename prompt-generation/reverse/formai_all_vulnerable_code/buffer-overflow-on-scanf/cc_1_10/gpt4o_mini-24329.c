//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50
#define FILE_CONTENT_LENGTH 256

typedef struct {
    char name[FILENAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];
    int size;
} File;

typedef struct {
    File* files[MAX_FILES];
    int fileCount;
} FileSystem;

FileSystem* createFileSystem() {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->fileCount = 0;
    return fs;
}

void deleteFileSystem(FileSystem* fs) {
    for (int i = 0; i < fs->fileCount; i++) {
        free(fs->files[i]);
    }
    free(fs);
}

File* createFile(const char* name, const char* content) {
    File* file = (File*)malloc(sizeof(File));
    strncpy(file->name, name, FILENAME_LENGTH);
    strncpy(file->content, content, FILE_CONTENT_LENGTH);
    file->size = strlen(content);
    return file;
}

void addFile(FileSystem* fs, File* file) {
    if (fs->fileCount < MAX_FILES) {
        fs->files[fs->fileCount++] = file;
    } else {
        printf("Error: File system is full!\n");
    }
}

void listFiles(FileSystem* fs) {
    printf("Files in the system:\n");
    for (int i = 0; i < fs->fileCount; i++) {
        printf("File Name: %s, Size: %d bytes\n", fs->files[i]->name, fs->files[i]->size);
    }
}

File* getFile(FileSystem* fs, const char* name) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            return fs->files[i];
        }
    }
    return NULL;
}

void deleteFile(FileSystem* fs, const char* name) {
    int found = 0;
    for (int i = 0; i < fs->fileCount; i++) {
        if (found) {
            fs->files[i - 1] = fs->files[i];
        } else if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);
            found = 1;
        }
    }
    if (found) {
        fs->fileCount--;
        printf("File '%s' deleted successfully.\n", name);
    } else {
        printf("File '%s' not found!\n", name);
    }
}

void displayFileContent(File* file) {
    if (file != NULL) {
        printf("Content of file '%s':\n%s\n", file->name, file->content);
    } else {
        printf("File not found!\n");
    }
}

int main() {
    FileSystem* fs = createFileSystem();
    int choice;
    char filename[FILENAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];

    while (1) {
        printf("\n---- Simple File System ----\n");
        printf("1. Create File\n");
        printf("2. List Files\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove trailing newline
                printf("Enter file content: ");
                fgets(content, FILE_CONTENT_LENGTH, stdin);
                content[strcspn(content, "\n")] = 0; // Remove trailing newline
                addFile(fs, createFile(filename, content));
                break;
            case 2:
                listFiles(fs);
                break;
            case 3:
                printf("Enter file name to read: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0;
                displayFileContent(getFile(fs, filename));
                break;
            case 4:
                printf("Enter file name to delete: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0;
                deleteFile(fs, filename);
                break;
            case 5:
                deleteFileSystem(fs);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}