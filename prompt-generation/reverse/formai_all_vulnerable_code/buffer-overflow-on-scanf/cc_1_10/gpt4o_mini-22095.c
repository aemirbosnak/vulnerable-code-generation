//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50
#define DATA_LENGTH 256

typedef struct {
    char name[FILENAME_LENGTH];
    char data[DATA_LENGTH];
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void initialize_file_system(FileSystem *fs) {
    fs->file_count = 0;
}

int create_file(FileSystem *fs, const char *name, const char *data) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return -1;
    }
    strncpy(fs->files[fs->file_count].name, name, FILENAME_LENGTH);
    strncpy(fs->files[fs->file_count].data, data, DATA_LENGTH);
    fs->file_count++;
    printf("File '%s' created successfully.\n", name);
    return 0;
}

int read_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Reading file '%s': %s\n", name, fs->files[i].data);
            return 0;
        }
    }
    printf("Error: File '%s' not found.\n", name);
    return -1;
}

int delete_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->file_count--;
            printf("File '%s' deleted successfully.\n", name);
            return 0;
        }
    }
    printf("Error: File '%s' not found.\n", name);
    return -1;
}

void list_files(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("No files in the system.\n");
        return;
    }
    printf("Files in the system:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("- %s\n", fs->files[i].name);
    }
}

void free_file_system(FileSystem *fs) {
    // Freeing up resources (not necessary here as we're using static arrays) 
    // but keeping this function can aid expansion in the future.
}

int main() {
    FileSystem fs;
    initialize_file_system(&fs);

    int choice;
    char filename[FILENAME_LENGTH];
    char data[DATA_LENGTH];

    do {
        printf("\nFile System Menu:\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Delete File\n");
        printf("4. List Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline after integer input

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                printf("Enter file data: ");
                fgets(data, DATA_LENGTH, stdin);
                data[strcspn(data, "\n")] = 0;  // Remove newline
                create_file(&fs, filename, data);
                break;
            case 2:
                printf("Enter filename to read: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                read_file(&fs, filename);
                break;
            case 3:
                printf("Enter filename to delete: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                delete_file(&fs, filename);
                break;
            case 4:
                list_files(&fs);
                break;
            case 5:
                printf("Exiting the file system simulation.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    free_file_system(&fs);
    
    return 0;
}