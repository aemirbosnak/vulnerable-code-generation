//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 50
#define MAX_CONTENT 256

typedef struct {
    char name[MAX_FILENAME];
    char content[MAX_CONTENT];
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} FileSystem;

// Function to initialize the file system
void initFileSystem(FileSystem *fs) {
    fs->count = 0;
}

// Function to create a new file
void createFile(FileSystem *fs) {
    if (fs->count >= MAX_FILES) {
        printf("Surprise! You can't create more files. Max limit reached!\n");
        return;
    }

    File newFile;
    printf("Enter file name: ");
    scanf("%s", newFile.name);
    printf("Enter file content: ");
    getchar();  // To consume newline character after filename
    scanf("%[^\n]", newFile.content);
    fs->files[fs->count++] = newFile;
    printf("File '%s' created successfully!\n", newFile.name);
}

// Function to read a file's content
void readFile(FileSystem *fs) {
    char filename[MAX_FILENAME];
    printf("Enter file name to read: ");
    scanf("%s", filename);
    
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("Surprise! File '%s' Content:\n%s\n", filename, fs->files[i].content);
            return;
        }
    }
    printf("Oops! File '%s' not found!\n", filename);
}

// Function to delete a file
void deleteFile(FileSystem *fs) {
    char filename[MAX_FILENAME];
    printf("Enter file name to delete: ");
    scanf("%s", filename);
    
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            // Shift files to fill the gap
            for (int j = i; j < fs->count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->count--;
            printf("Surprise! File '%s' deleted successfully!\n", filename);
            return;
        }
    }
    printf("Oops! File '%s' not found to delete!\n", filename);
}

// Function to list all files
void listFiles(FileSystem *fs) {
    if (fs->count == 0) {
        printf("Surprise! No files to display.\n");
        return;
    }
    printf("Listing all files:\n");
    for (int i = 0; i < fs->count; i++) {
        printf("File %d: %s\n", i + 1, fs->files[i].name);
    }
}

// Function to display menu options
void displayMenu() {
    printf("\n---- Surprise File System Menu ----\n");
    printf("1. Create File\n");
    printf("2. Read File\n");
    printf("3. Delete File\n");
    printf("4. List Files\n");
    printf("5. Exit\n");
    printf("----------------------------------\n");
}

// Main function
int main() {
    FileSystem fs;
    initFileSystem(&fs);
    int choice;

    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(&fs);
                break;
            case 2:
                readFile(&fs);
                break;
            case 3:
                deleteFile(&fs);
                break;
            case 4:
                listFiles(&fs);
                break;
            case 5:
                printf("Exiting the surprise file system! Goodbye!\n");
                break;
            default:
                printf("Oops! Invalid choice. Please try again!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}