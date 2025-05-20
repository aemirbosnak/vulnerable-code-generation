//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 256

typedef struct File {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    struct File *next;
} File;

typedef struct FileSystem {
    File *head;
    int file_count;
} FileSystem;

// Function prototypes
void initialize_file_system(FileSystem *fs);
void create_file(FileSystem *fs, const char *filename, const char *content);
void read_file(FileSystem *fs, const char *filename);
void delete_file(FileSystem *fs, const char *filename);
void list_files(FileSystem *fs);
void cleanup(FileSystem *fs);

// Main function
int main() {
    FileSystem fs;
    initialize_file_system(&fs);

    int choice;
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];

    while (1) {
        printf("File System Simulation\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Delete File\n");
        printf("4. List Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline character

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                strtok(filename, "\n"); // remove trailing newline

                printf("Enter content: ");
                fgets(content, sizeof(content), stdin);
                strtok(content, "\n"); // remove trailing newline

                create_file(&fs, filename, content);
                break;

            case 2:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                strtok(filename, "\n"); // remove trailing newline

                read_file(&fs, filename);
                break;

            case 3:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                strtok(filename, "\n"); // remove trailing newline

                delete_file(&fs, filename);
                break;

            case 4:
                list_files(&fs);
                break;

            case 5:
                cleanup(&fs);
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Function implementations
void initialize_file_system(FileSystem *fs) {
    fs->head = NULL;
    fs->file_count = 0;
}

void create_file(FileSystem *fs, const char *filename, const char *content) {
    if (fs->file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return;
    }

    File *new_file = (File *)malloc(sizeof(File));
    if (!new_file) {
        printf("Error: Unable to allocate memory for a new file.\n");
        return;
    }
    strcpy(new_file->name, filename);
    strcpy(new_file->content, content);
    new_file->next = fs->head;
    fs->head = new_file;
    fs->file_count++;

    printf("File '%s' created successfully.\n", filename);
}

void read_file(FileSystem *fs, const char *filename) {
    File *current = fs->head;

    while (current != NULL) {
        if (strcmp(current->name, filename) == 0) {
            printf("Content of file '%s':\n%s\n", filename, current->content);
            return;
        }
        current = current->next;
    }

    printf("Error: File '%s' not found.\n", filename);
}

void delete_file(FileSystem *fs, const char *filename) {
    File *current = fs->head;
    File *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, filename) == 0) {
            if (previous == NULL) { // File is the head
                fs->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            fs->file_count--;
            printf("File '%s' deleted successfully.\n", filename);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: File '%s' not found.\n", filename);
}

void list_files(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("No files in the system.\n");
        return;
    }

    File *current = fs->head;
    printf("Listing files:\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

void cleanup(FileSystem *fs) {
    File *current = fs->head;
    File *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    fs->head = NULL;
    fs->file_count = 0;
}