//FormAI DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 20
#define MAX_FILESIZE 100

struct file {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILESIZE];
    int size;
};

struct file_system {
    struct file files[MAX_FILES];
    int num_files;
};

// function prototypes
void print_menu();
void add_file(struct file_system *fs);
void delete_file(struct file_system *fs);
void display_files(struct file_system *fs);

int main() {
    struct file_system fs = {0};
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_file(&fs);
                break;
            case 2:
                delete_file(&fs);
                break;
            case 3:
                display_files(&fs);
                break;
            case 4:
                printf("Exiting file system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void print_menu() {
    printf("File System Menu\n");
    printf("-----------------\n");
    printf("1. Add file\n");
    printf("2. Delete file\n");
    printf("3. Display files\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void add_file(struct file_system *fs) {
    if (fs->num_files >= MAX_FILES) {
        printf("Error: maximum number of files reached.\n");
        return;
    }

    struct file new_file;
    printf("Enter filename (max %d characters): ", MAX_FILENAME_LENGTH);
    scanf("%s", new_file.filename);

    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, new_file.filename) == 0) {
            printf("Error: filename already exists.\n");
            return;
        }
    }

    printf("Enter file content (max %d characters): ", MAX_FILESIZE);
    scanf("%s", new_file.content);

    new_file.size = strlen(new_file.content);

    fs->files[fs->num_files] = new_file;
    fs->num_files++;

    printf("File added successfully.\n");
}

void delete_file(struct file_system *fs) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to delete: ");
    scanf("%s", filename);

    int found = 0;

    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            // found the file to delete
            found = 1;
            for (int j = i; j < fs->num_files - 1; j++) {
                fs->files[j] = fs->files[j+1];
            }
            fs->num_files--;
            printf("File deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Error: file not found.\n");
    }
}

void display_files(struct file_system *fs) {
    if (fs->num_files == 0) {
        printf("No files to display.\n");
        return;
    }

    printf("Filename\t\tSize\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < fs->num_files; i++) {
        printf("%s\t\t%d\n", fs->files[i].filename, fs->files[i].size);
    }
}