//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int size;
    int is_open;
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void initialize_file_system(FileSystem *fs) {
    fs->file_count = 0;
}

int create_file(FileSystem *fs, const char *name, int size) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return -1;
    }
    if (strlen(name) >= MAX_NAME_LENGTH) {
        printf("Error: File name too long.\n");
        return -1;
    }

    strcpy(fs->files[fs->file_count].name, name);
    fs->files[fs->file_count].size = size;
    fs->files[fs->file_count].is_open = 0;
    fs->file_count++;
    printf("File '%s' created successfully.\n", name);
    return 0;
}

int open_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            if (fs->files[i].is_open) {
                printf("File '%s' is already open.\n", name);
                return -1;
            }
            fs->files[i].is_open = 1;
            printf("File '%s' opened successfully.\n", name);
            return 0;
        }
    }
    printf("Error: File '%s' not found.\n", name);
    return -1;
}

int close_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            if (!fs->files[i].is_open) {
                printf("File '%s' is not open.\n", name);
                return -1;
            }
            fs->files[i].is_open = 0;
            printf("File '%s' closed successfully.\n", name);
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
    printf("List of files:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("Name: %s, Size: %d bytes, Status: %s\n",
               fs->files[i].name,
               fs->files[i].size,
               fs->files[i].is_open ? "Open" : "Closed");
    }
}

int delete_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            if (fs->files[i].is_open) {
                printf("Error: Cannot delete an open file. Please close '%s' first.\n", name);
                return -1;
            }
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

int main() {
    FileSystem fs;
    initialize_file_system(&fs);
    
    int choice;
    char filename[MAX_NAME_LENGTH];
    int size;

    while (1) {
        printf("\nSimple File System Menu\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Close File\n");
        printf("4. List Files\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                printf("Enter filename to open: ");
                scanf("%s", filename);
                open_file(&fs, filename);
                break;
            case 3:
                printf("Enter filename to close: ");
                scanf("%s", filename);
                close_file(&fs, filename);
                break;
            case 4:
                list_files(&fs);
                break;
            case 5:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                delete_file(&fs, filename);
                break;
            case 6:
                printf("Exiting the file system simulation. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}