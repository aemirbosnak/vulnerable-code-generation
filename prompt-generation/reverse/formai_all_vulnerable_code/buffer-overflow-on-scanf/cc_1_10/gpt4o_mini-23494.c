//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_SIZE 50
#define CONTENT_SIZE 256

typedef struct {
    char name[FILENAME_SIZE];
    char content[CONTENT_SIZE];
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->file_count = 0;
    printf("🎉 Welcome to the Happy File System! 🎉\n\n");
}

void createFile(FileSystem *fs) {
    if (fs->file_count >= MAX_FILES) {
        printf("📂 Sorry, the file system is full!\n");
        return;
    }

    File new_file;
    printf("Enter the name of the new file: ");
    scanf("%s", new_file.name);
    printf("Enter the content of the file: ");
    scanf(" %[^\n]", new_file.content); // Read string with spaces

    fs->files[fs->file_count] = new_file;
    fs->file_count++;
    printf("🎉 File '%s' created successfully! 🎉\n", new_file.name);
}

void listFiles(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("📁 No files found in the system! 📁\n");
        return;
    }

    printf("📁 Listing all files:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("%d: %s\n", i + 1, fs->files[i].name);
    }
}

void readFile(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("📁 No files to read! 📁\n");
        return;
    }

    char filename[FILENAME_SIZE];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("📜 Content of '%s': %s\n", fs->files[i].name, fs->files[i].content);
            return;
        }
    }
    printf("❌ File '%s' not found! ❌\n", filename);
}

void deleteFile(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("📁 No files to delete! 📁\n");
        return;
    }

    char filename[FILENAME_SIZE];
    printf("Enter the name of the file to delete: ");
    scanf("%s", filename);

    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->file_count--;
            printf("🎉 File '%s' deleted successfully! 🎉\n", filename);
            return;
        }
    }
    printf("❌ File '%s' not found! ❌\n", filename);
}

void displayMenu() {
    printf("\n📝 Happy File System Menu:\n");
    printf("1. Create a file\n");
    printf("2. List files\n");
    printf("3. Read a file\n");
    printf("4. Delete a file\n");
    printf("5. Exit\n");
}

int main() {
    FileSystem fs;
    initFileSystem(&fs);
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(&fs);
                break;
            case 2:
                listFiles(&fs);
                break;
            case 3:
                readFile(&fs);
                break;
            case 4:
                deleteFile(&fs);
                break;
            case 5:
                printf("🎉 Thank you for using Happy File System! Goodbye! 🎉\n");
                break;
            default:
                printf("❌ Invalid choice! Please try again. ❌\n");
        }
    } while (choice != 5);

    return 0;
}