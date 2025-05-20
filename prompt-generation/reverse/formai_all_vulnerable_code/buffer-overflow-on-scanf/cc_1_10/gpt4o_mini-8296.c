//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50
#define BLOCK_SIZE 1024

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size; // in bytes
    int blocks; // how many blocks the file occupies
} File;

typedef struct {
    File *files[MAX_FILES];
    int file_count;
} FileSystem;

FileSystem *init_file_system() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    fs->file_count = 0;
    return fs;
}

void create_file(FileSystem *fs, const char *filename, int size) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return;
    }

    File *new_file = (File *)malloc(sizeof(File));
    strncpy(new_file->filename, filename, MAX_FILENAME_LENGTH);
    new_file->size = size;
    new_file->blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE; // Calculate number of blocks

    fs->files[fs->file_count++] = new_file;
    printf("File '%s' created with size %d bytes occupying %d blocks.\n", filename, size, new_file->blocks);
}

void delete_file(FileSystem *fs, const char *filename) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->filename, filename) == 0) {
            free(fs->files[i]);
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->file_count--;
            printf("File '%s' deleted successfully.\n", filename);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", filename);
}

void display_files(FileSystem *fs) {
    printf("\n--- Files in the File System ---\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("File Name: %s, Size: %d bytes, Blocks: %d\n",
               fs->files[i]->filename, fs->files[i]->size, fs->files[i]->blocks);
    }
    printf("---------------------------------\n");
}

void free_file_system(FileSystem *fs) {
    for (int i = 0; i < fs->file_count; i++) {
        free(fs->files[i]);
    }
    free(fs);
}

int main() {
    FileSystem *fs = init_file_system();
    int choice;
    char filename[MAX_FILENAME_LENGTH];
    int size;

    while (1) {
        printf("\nFile System Simulation\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Display Files\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter size (in bytes): ");
                scanf("%d", &size);
                create_file(fs, filename, size);
                break;
            case 2:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                delete_file(fs, filename);
                break;
            case 3:
                display_files(fs);
                break;
            case 4:
                free_file_system(fs);
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}