//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define FILENAME_SIZE 50
#define FILE_CONTENT_SIZE 256

typedef struct {
    char name[FILENAME_SIZE];
    char content[FILE_CONTENT_SIZE];
} File;

typedef struct {
    File files[MAX_FILES];
    int fileCount;
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->fileCount = 0;
}

void createFile(FileSystem *fs) {
    if (fs->fileCount >= MAX_FILES) {
        printf("🎉 Oops! You can't create more files! The memory is full! 🎉\n");
        return;
    }

    File newFile;
    printf("🌟 Enter the filename (max %d characters): ", FILENAME_SIZE - 1);
    scanf("%s", newFile.name);
    printf("📝 Now write some content for your file (max %d characters): ", FILE_CONTENT_SIZE - 1);
    getchar(); // Consume the newline left by previous scanf
    fgets(newFile.content, FILE_CONTENT_SIZE, stdin);

    fs->files[fs->fileCount++] = newFile;
    printf("🎉 Hooray! File '%s' has been created! 🎉\n", newFile.name);
}

void readFile(const FileSystem *fs) {
    char filename[FILENAME_SIZE];
    printf("🔍 Enter the filename you want to read: ");
    scanf("%s", filename);

    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("📄 Content of '%s':\n%s", fs->files[i].name, fs->files[i].content);
            return;
        }
    }
    
    printf("😢 Sorry! File '%s' does not exist! Please try again! 😢\n", filename);
}

void deleteFile(FileSystem *fs) {
    char filename[FILENAME_SIZE];
    printf("❌ Enter the filename you want to delete: ");
    scanf("%s", filename);

    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            for (int j = i; j < fs->fileCount - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->fileCount--;
            printf("🎉 File '%s' has been deleted! 🎉\n", filename);
            return;
        }
    }
    
    printf("😢 Sorry! File '%s' does not exist! Please try again! 😢\n", filename);
}

void displayFiles(const FileSystem *fs) {
    if (fs->fileCount == 0) {
        printf("🌈 There are currently no files in the system! 🌈\n");
        return;
    }

    printf("📂 Here are the files in your cheerful file system: 📂\n");
    for (int i = 0; i < fs->fileCount; i++) {
        printf("  - %s\n", fs->files[i].name);
    }
}

int main() {
    FileSystem fs;
    initFileSystem(&fs);
    int choice;

    do {
        printf("\n✨ Welcome to the Cheerful File System! ✨\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Delete File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
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
                displayFiles(&fs);
                break;
            case 5:
                printf("🌟 Thank you for using the Cheerful File System! Goodbye! 🌟\n");
                break;
            default:
                printf("⚠️ Invalid choice! Please select a valid option! ⚠️\n");
        }
    } while (choice != 5);

    return 0;
}