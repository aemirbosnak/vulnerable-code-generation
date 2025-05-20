//FormAI DATASET v1.0 Category: File system simulation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining constants for the maximum number of files and the size of the file name
#define MAX_NUM_FILES 100
#define FILE_NAME_SIZE 20

// Defining the file structure to hold information about each file
struct File {
    char name[FILE_NAME_SIZE];
    int size;
};

// Defining the file system structure to hold information about all the files
struct FileSystem {
    struct File files[MAX_NUM_FILES];
    int num_files;
};

// Function to add a new file to the file system
void addFile(struct FileSystem* fs, char name[], int size) {
    if(fs->num_files == MAX_NUM_FILES) { // Check if the maximum number of files have been reached
        printf("Error: Maximum number of files reached!\n");
        return;
    }
    strcpy(fs->files[fs->num_files].name, name);
    fs->files[fs->num_files].size = size;
    fs->num_files++;
    printf("File added successfully!\n");
}

// Function to remove a file from the file system
void removeFile(struct FileSystem* fs, char name[]) {
    int i, index = -1;
    for(i = 0; i < fs->num_files; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) { // Check if the file exists or not
        printf("Error: File not found!\n");
        return;
    }
    for(i = index; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->num_files--;
    printf("File removed successfully!\n");
}

int main() {
    struct FileSystem fs;
    fs.num_files = 0;
    int choice, size;
    char name[FILE_NAME_SIZE];
    do {
        printf("Choose an option:\n");
        printf("1. Add file\n");
        printf("2. Remove file\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size: ");
                scanf("%d", &size);
                addFile(&fs, name, size);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", name);
                removeFile(&fs, name);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);
    return 0;
}