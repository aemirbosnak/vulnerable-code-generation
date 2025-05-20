//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50
#define BUFFER_SIZE 1024

typedef struct {
    char name[FILENAME_LENGTH];
    int size;
    char *data;
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} FileSystem;

// Function prototypes
void init_file_system(FileSystem *fs);
void create_file(FileSystem *fs, const char *name, const char *content);
void list_files(FileSystem *fs);
void recover_file(FileSystem *fs, const char *name);
void cleanup_file_system(FileSystem *fs);
void display_menu();

int main() {
    FileSystem fs;
    init_file_system(&fs);
    char input[FILENAME_LENGTH];
    char content[BUFFER_SIZE];
    
    display_menu();
    int choice;
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline
        
        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                fgets(input, FILENAME_LENGTH, stdin);
                strtok(input, "\n"); // remove newline
                printf("Enter file content: ");
                fgets(content, BUFFER_SIZE, stdin);
                strtok(content, "\n"); // remove newline
                create_file(&fs, input, content);
                break;
            case 2:
                list_files(&fs);
                break;
            case 3:
                printf("Enter filename to recover: ");
                fgets(input, FILENAME_LENGTH, stdin);
                strtok(input, "\n"); // remove newline
                recover_file(&fs, input);
                break;
            case 4:
                cleanup_file_system(&fs);
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void init_file_system(FileSystem *fs) {
    fs->count = 0;
}

void create_file(FileSystem *fs, const char *name, const char *content) {
    if (fs->count >= MAX_FILES) {
        printf("File system full! Cannot create more files.\n");
        return;
    }
    
    File *file = &fs->files[fs->count];
    strcpy(file->name, name);
    file->size = strlen(content);
    file->data = (char *)malloc(file->size + 1);
    
    if (file->data != NULL) {
        strcpy(file->data, content);
        fs->count++;
        printf("File '%s' created successfully.\n", name);
    } else {
        printf("Memory allocation failed!\n");
    }
}

void list_files(FileSystem *fs) {
    if (fs->count == 0) {
        printf("No files in the system.\n");
        return;
    }
    
    printf("Listing files:\n");
    for (int i = 0; i < fs->count; i++) {
        printf("- %s (Size: %d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

void recover_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Recovering file: %s\n", fs->files[i].name);
            printf("File content: %s\n", fs->files[i].data);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

void cleanup_file_system(FileSystem *fs) {
    for (int i = 0; i < fs->count; i++) {
        free(fs->files[i].data);
    }
}

void display_menu() {
    printf("=== Simple Data Recovery Tool ===\n");
    printf("1. Create File\n");
    printf("2. List Files\n");
    printf("3. Recover File\n");
    printf("4. Exit\n");
}