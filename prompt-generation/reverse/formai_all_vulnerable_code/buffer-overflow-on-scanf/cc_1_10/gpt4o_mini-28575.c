//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 50
#define MEMORY_SIZE 1024  // in KB

typedef struct {
    char name[MAX_NAME_LENGTH];
    int size;  // size of the file in KB
    int start_block;  // starting block in file system
} File;

typedef struct {
    int total_size;  // total size of the file system
    int used_size;   // used size in the file system
    File *files[MAX_FILES];  // array of files
    int file_count;  // number of files in the system
} FileSystem;

// Function prototypes
FileSystem *initialize_fs(int size);
int create_file(FileSystem *fs, const char *name, int size);
void delete_file(FileSystem *fs, const char *name);
void list_files(FileSystem *fs);
void cleanup(FileSystem *fs);

int main() {
    FileSystem *fs = initialize_fs(MEMORY_SIZE);
    if (fs == NULL) {
        fprintf(stderr, "Failed to initialize file system.\n");
        return EXIT_FAILURE;
    }

    int choice;
    char name[MAX_NAME_LENGTH];
    int size;

    do {
        printf("\n--- File System Menu ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. List Files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size (KB): ");
                scanf("%d", &size);
                create_file(fs, name, size);
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", name);
                delete_file(fs, name);
                break;
            case 3:
                list_files(fs);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    cleanup(fs);
    return EXIT_SUCCESS;
}

FileSystem *initialize_fs(int size) {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    if (fs != NULL) {
        fs->total_size = size;
        fs->used_size = 0;
        fs->file_count = 0;
        memset(fs->files, 0, sizeof(fs->files));
    }
    return fs;
}

int create_file(FileSystem *fs, const char *name, int size) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return -1;
    }
    if (fs->used_size + size > fs->total_size) {
        printf("Error: Not enough space to create file %s of size %d KB.\n", name, size);
        return -1;
    }

    File *new_file = (File *)malloc(sizeof(File));
    if (new_file == NULL) {
        printf("Error: Failed to allocate memory for file.\n");
        return -1;
    }

    strncpy(new_file->name, name, MAX_NAME_LENGTH);
    new_file->size = size;
    new_file->start_block = fs->used_size;  // Using used_size as block allocation
    fs->files[fs->file_count++] = new_file;
    fs->used_size += size;

    printf("File %s of size %d KB created successfully.\n", name, size);
    return 0;
}

void delete_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            fs->used_size -= fs->files[i]->size;

            printf("File %s deleted successfully.\n", name);
            free(fs->files[i]);

            // Shift remaining files
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->files[fs->file_count - 1] = NULL;
            fs->file_count--;

            return;
        }
    }
    printf("Error: File %s not found.\n", name);
}

void list_files(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("No files in the system.\n");
        return;
    }

    printf("Files in the system:\n");
    printf("%-20s %-10s %-10s\n", "File Name", "Size (KB)", "Start Block");
    for (int i = 0; i < fs->file_count; i++) {
        printf("%-20s %-10d %-10d\n", fs->files[i]->name, fs->files[i]->size, fs->files[i]->start_block);
    }
}

void cleanup(FileSystem *fs) {
    for (int i = 0; i < fs->file_count; i++) {
        free(fs->files[i]);
    }
    free(fs);
}