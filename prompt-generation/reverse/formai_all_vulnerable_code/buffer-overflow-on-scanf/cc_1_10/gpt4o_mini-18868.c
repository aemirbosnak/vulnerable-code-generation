//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size; // Size in KB
} File;

typedef struct {
    File files[MAX_FILES];
    int fileCount;
} FileSystem;

void initializeFileSystem(FileSystem *fs) {
    fs->fileCount = 0;
    printf("✨ Happy File System Initialized! ✨\n");
}

void createFile(FileSystem *fs, const char *filename, int size) {
    if (fs->fileCount >= MAX_FILES) {
        printf("❌ Can't create file. File system is full!\n");
        return;
    }
    strcpy(fs->files[fs->fileCount].name, filename);
    fs->files[fs->fileCount].size = size;
    fs->fileCount++;
    printf("📄 File '%s' of size %d KB created successfully! 🎉\n", filename, size);
}

void deleteFile(FileSystem *fs, const char *filename) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("🗑️ File '%s' deleted successfully! Bye bye! 👋\n", filename);
            for (int j = i; j < fs->fileCount - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->fileCount--;
            return;
        }
    }
    printf("❗ File '%s' not found! 😢\n", filename);
}

void listFiles(FileSystem *fs) {
    if (fs->fileCount == 0) {
        printf("📂 No files in the system. Create some happy files! 😊\n");
        return;
    }
    printf("📁 Current files in the file system:\n");
    for (int i = 0; i < fs->fileCount; i++) {
        printf(" - %s (%d KB)\n", fs->files[i].name, fs->files[i].size);
    }
}

void findFile(FileSystem *fs, const char *filename) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("🔍 Found file '%s' with size %d KB! 🎊\n", filename, fs->files[i].size);
            return;
        }
    }
    printf("❗ File '%s' not found! Try again! 🤔\n", filename);
}

int main() {
    FileSystem fs;
    initializeFileSystem(&fs);
    
    int choice;
    char filename[MAX_FILENAME_LENGTH];
    int size;

    while (1) {
        printf("\n🌟 Happy File System Menu 🌟\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. List Files\n");
        printf("4. Find File\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter size (in KB): ");
                scanf("%d", &size);
                createFile(&fs, filename, size);
                break;
            case 2:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                deleteFile(&fs, filename);
                break;
            case 3:
                listFiles(&fs);
                break;
            case 4:
                printf("Enter filename to find: ");
                scanf("%s", filename);
                findFile(&fs, filename);
                break;
            case 5:
                printf("🎈 Thank you for using the Happy File System! Goodbye! 👋\n");
                exit(0);
            default:
                printf("❗ Invalid option! Please choose a number between 1 and 5. ☀️\n");
        }
    }

    return 0;
}