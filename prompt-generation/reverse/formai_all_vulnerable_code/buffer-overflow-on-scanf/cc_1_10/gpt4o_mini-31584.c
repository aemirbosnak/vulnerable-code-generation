//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size; // in bytes
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void initialize_file_system(FileSystem *fs) {
    fs->file_count = 0;
}

int create_file(FileSystem *fs, const char *filename, int size) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached\n");
        return -1;
    }
    if (size <= 0) {
        printf("Error: File size must be greater than zero\n");
        return -1;
    }
    
    strncpy(fs->files[fs->file_count].name, filename, MAX_FILENAME_LENGTH);
    fs->files[fs->file_count].size = size;
    fs->file_count++;
    printf("File '%s' created, size: %d bytes\n", filename, size);
    return 0;
}

void list_files(const FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("No files in the system\n");
        return;
    }
    printf("Files in the system:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf(" - %s: %d bytes\n", fs->files[i].name, fs->files[i].size);
    }
}

File* find_file(FileSystem *fs, const char *filename) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            return &fs->files[i];
        }
    }
    return NULL;
}

int delete_file(FileSystem *fs, const char *filename) {
    File *file = find_file(fs, filename);
    if (file == NULL) {
        printf("Error: File '%s' not found\n", filename);
        return -1;
    }
    
    int index = file - fs->files; // Calculate index of the file
    for (int i = index; i < fs->file_count - 1; i++) {
        fs->files[i] = fs->files[i + 1]; // Shift files left
    }
    fs->file_count--;
    printf("File '%s' deleted\n", filename);
    return 0;
}

void free_file_system(FileSystem *fs) {
    // Currently no dynamic memory allocation, but implementation for the future
}

int main() {
    FileSystem fs;
    initialize_file_system(&fs);
    
    int choice, size;
    char filename[MAX_FILENAME_LENGTH];

    while (1) {
        printf("\nFile System Menu:\n");
        printf("1. Create File\n");
        printf("2. List Files\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter file size (in bytes): ");
                scanf("%d", &size);
                create_file(&fs, filename, size);
                break;
            case 2:
                list_files(&fs);
                break;
            case 3:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                delete_file(&fs, filename);
                break;
            case 4:
                free_file_system(&fs);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}