//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define FILE_NAME_LENGTH 20
#define BUFFER_SIZE 256

typedef struct {
    char name[FILE_NAME_LENGTH];
    char content[BUFFER_SIZE];
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->count = 0;
}

int createFile(FileSystem *fs, const char *name) {
    if (fs->count >= MAX_FILES) {
        printf("Error: Maximum file limit reached!\n");
        return -1;
    }
    
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Error: File '%s' already exists!\n", name);
            return -1;
        }
    }

    strncpy(fs->files[fs->count].name, name, FILE_NAME_LENGTH);
    fs->files[fs->count].content[0] = '\0'; // Initialize content as empty
    fs->count++;
    printf("File '%s' created successfully!\n", name);
    return 0;
}

void listFiles(FileSystem *fs) {
    if (fs->count == 0) {
        printf("No files in the system.\n");
    } else {
        printf("List of files:\n");
        for (int i = 0; i < fs->count; i++) {
            printf("- %s\n", fs->files[i].name);
        }
    }
}

void readFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Contents of '%s':\n%s\n", name, fs->files[i].content);
            return;
        }
    }
    printf("Error: File '%s' not found!\n", name);
}

void deleteFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            // Shift files down to fill the gap
            for (int j = i; j < fs->count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->count--;
            printf("File '%s' deleted successfully!\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found!\n", name);
}

void editFile(FileSystem *fs, const char *name, const char *newContent) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            strncpy(fs->files[i].content, newContent, BUFFER_SIZE);
            printf("File '%s' updated successfully!\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found!\n", name);
}

int main() {
    FileSystem fs;
    initFileSystem(&fs);
    int choice;
    char name[FILE_NAME_LENGTH], content[BUFFER_SIZE];

    do {
        printf("\n=== Simple File System ===\n");
        printf("1. Create File\n");
        printf("2. List Files\n");
        printf("3. Read File\n");
        printf("4. Edit File\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                fgets(name, FILE_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                createFile(&fs, name);
                break;

            case 2:
                listFiles(&fs);
                break;

            case 3:
                printf("Enter file name to read: ");
                fgets(name, FILE_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                readFile(&fs, name);
                break;

            case 4:
                printf("Enter file name to edit: ");
                fgets(name, FILE_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter new content: ");
                fgets(content, BUFFER_SIZE, stdin);
                content[strcspn(content, "\n")] = '\0';
                editFile(&fs, name, content);
                break;

            case 5:
                printf("Enter file name to delete: ");
                fgets(name, FILE_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteFile(&fs, name);
                break;

            case 6:
                printf("Exiting the file system. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}