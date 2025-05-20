//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define FILE_NAME_LENGTH 20

typedef struct {
    char* name;
    int size;
} File;

typedef struct {
    File files[MAX_FILES];
    int totalFiles;
    int usedSpace;
} FileSystem;

// helper functions
void printFile(File file) {
    printf("%s (%d KB)\n", file.name, file.size);
}

void printFileSystem(FileSystem fs) {
    printf("--- File System ---\n");
    printf("Total files: %d\n", fs.totalFiles);
    printf("Used space: %d KB\n", fs.usedSpace);
    printf("Files:\n");
    for (int i=0; i<fs.totalFiles; i++) {
        printFile(fs.files[i]);
    }
}

int isFileExists(FileSystem fs, char* fileName) {
    for (int i=0; i<fs.totalFiles; i++) {
        if (strcmp(fs.files[i].name, fileName) == 0) {
            return 1;
        }
    }
    return 0;
}

void addFile(FileSystem *fs, char* fileName, int fileSize) {
    if (fs->totalFiles == MAX_FILES) {
        printf("Error: File limit reached!\n");
        return;
    }

    if (isFileExists(*fs, fileName)) {
        printf("Error: File with name '%s' already exists!\n", fileName);
        return;
    }

    File newFile;
    newFile.name = fileName;
    newFile.size = fileSize;
    fs->files[fs->totalFiles] = newFile;
    fs->totalFiles++;
    fs->usedSpace += fileSize;

    printf("File added successfully!\n");
}

void deleteFile(FileSystem *fs, char* fileName) {
    int index = -1;
    for (int i=0; i<fs->totalFiles; i++) {
        if (strcmp(fs->files[i].name, fileName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: File with name '%s' not found!\n", fileName);
        return;
    }

    fs->usedSpace -= fs->files[index].size;
    for (int i=index; i<fs->totalFiles-1; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->totalFiles--;

    printf("File deleted successfully!\n");
}

void formatFileSystem(FileSystem *fs) {
    fs->totalFiles = 0;
    fs->usedSpace = 0;
    printf("File system formatted successfully!\n");
}

void runSimulator() {
    FileSystem fs;
    fs.totalFiles = 0;
    fs.usedSpace = 0;

    int choice;
    while (1) {
        printf("\n");
        printf("1. Add file\n");
        printf("2. Delete file\n");
        printf("3. Format file system\n");
        printf("4. Print file system status\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                char file_name[FILE_NAME_LENGTH];
                scanf("%s", file_name);
                printf("Enter file size (KB): ");
                int file_size;
                scanf("%d", &file_size);
                addFile(&fs, file_name, file_size);
                break;
            case 2:
                printf("Enter file name: ");
                char delete_file_name[FILE_NAME_LENGTH];
                scanf("%s", delete_file_name);
                deleteFile(&fs, delete_file_name);
                break;
            case 3:
                formatFileSystem(&fs);
                break;
            case 4:
                printFileSystem(fs);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

int main() {
    runSimulator();
    return 0;
}