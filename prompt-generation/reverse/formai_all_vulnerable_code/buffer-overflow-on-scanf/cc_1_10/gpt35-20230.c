//FormAI DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_FOLDERS 10 // Maximum number of folders in the file system
#define MAX_FILES   20 // Maximum number of files in each folder

// Structure for a file
struct File {
    char name[20];
    int size;
};

// Structure for a folder
struct Folder {
    char name[20];
    struct File files[MAX_FILES];
    int num_files;
};

// Structure for the file system
struct FileSystem {
    struct Folder folders[MAX_FOLDERS];
    int num_folders;
};

// Function to create a new folder
void createFolder(struct FileSystem *fs) {
    if (fs->num_folders >= MAX_FOLDERS) {
        printf("Error: Maximum number of folders reached\n");
        return;
    }
    struct Folder newFolder;
    printf("Enter name for the new folder: ");
    scanf("%s", newFolder.name);
    newFolder.num_files = 0;
    fs->folders[fs->num_folders++] = newFolder;
    printf("Folder '%s' created successfully\n", newFolder.name);
}

// Function to create a new file in a folder
void createFile(struct FileSystem *fs) {
    if (fs->num_folders == 0) {
        printf("Error: No folder exists\n");
        return;
    }
    char folderName[20];
    printf("Enter folder name to create file in: ");
    scanf("%s", folderName);
    int folderIndex = -1;
    for (int i=0; i<fs->num_folders; i++) {
        if (strcmp(fs->folders[i].name, folderName) == 0) {
            folderIndex = i;
            break;
        }
    }
    if (folderIndex == -1) {
        printf("Error: Folder '%s' not found\n", folderName);
        return;
    }
    if (fs->folders[folderIndex].num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached for folder '%s'\n", folderName);
        return;
    }
    struct File newFile;
    printf("Enter name for the new file: ");
    scanf("%s", newFile.name);
    printf("Enter size for the new file: ");
    scanf("%d", &newFile.size);
    fs->folders[folderIndex].files[fs->folders[folderIndex].num_files++] = newFile;
    printf("File '%s' created successfully in folder '%s'\n", newFile.name, folderName);
}

// Function to list all folders and files in the file system
void listFileSystem(struct FileSystem *fs) {
    printf("File System\n");
    printf("-----------\n");
    for (int i=0; i<fs->num_folders; i++) {
        printf("Folder: %s\n", fs->folders[i].name);
        for (int j=0; j<fs->folders[i].num_files; j++) {
            printf("  File: %s (%d bytes)\n", fs->folders[i].files[j].name, fs->folders[i].files[j].size);
        }
    }
}

int main() {
    struct FileSystem fs; // Create a new file system
    fs.num_folders = 0;
    int choice;
    while (1) { // Main menu
        printf("\n1. Create folder\n");
        printf("2. Create file\n");
        printf("3. List file system\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createFolder(&fs);
                break;
            case 2:
                createFile(&fs);
                break;
            case 3:
                listFileSystem(&fs);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}