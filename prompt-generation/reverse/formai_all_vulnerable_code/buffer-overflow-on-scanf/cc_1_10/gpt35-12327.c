//FormAI DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50
#define MAX_FILE_COUNT 50

// struct to hold file information
typedef struct File {
    char filename[MAX_FILENAME_LEN];
    int size;
} File;

// struct to simulate file system
typedef struct FileSystem {
    int used_space;
    int remaining_space;
    File files[MAX_FILE_COUNT];
    int num_files;
} FileSystem;

// function to create a new file
void create_file(FileSystem* fs, char* filename, int size) {
    if (fs->num_files == MAX_FILE_COUNT) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    if (fs->remaining_space < size) {
        printf("Error: Not enough space to create file.\n");
        return;
    }
    // create new file
    File new_file;
    strcpy(new_file.filename, filename);
    new_file.size = size;
    
    // add file to file system
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    fs->used_space += size;
    fs->remaining_space -= size;
    printf("File %s created successfully.\n", filename);
}

// function to delete a file
void delete_file(FileSystem* fs, char* filename) {
    int file_index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: File %s not found.\n", filename);
        return;
    }
    fs->used_space -= fs->files[file_index].size;
    fs->remaining_space += fs->files[file_index].size;
    for (int i = file_index; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->num_files--;
    printf("File %s deleted successfully.\n", filename);
}

// function to print current file system state
void print_file_system(FileSystem* fs) {
    printf("\nFileSystem\n");
    printf("Used space: %d\n", fs->used_space);
    printf("Remaining space: %d\n", fs->remaining_space);
    printf("Number of files: %d\n", fs->num_files);
    if (fs->num_files == 0) {
        printf("No files found.\n");
        return;
    }
    printf("Files:\n");
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s - %d bytes\n", fs->files[i].filename, fs->files[i].size);
    }
}

int main() {
    FileSystem fs;
    fs.used_space = 0;
    fs.remaining_space = 1000; // 1MB
    fs.num_files = 0;

    char command[50];
    char arg1[MAX_FILENAME_LEN];
    char arg2[10];

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            scanf("%s", arg1);
            scanf("%s", arg2);
            int size = atoi(arg2);
            create_file(&fs, arg1, size);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", arg1);
            delete_file(&fs, arg1);
        } else if (strcmp(command, "print") == 0) {
            print_file_system(&fs);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}