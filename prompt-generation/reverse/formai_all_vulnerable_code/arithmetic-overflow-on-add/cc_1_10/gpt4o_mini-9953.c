//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILES 10
#define FILENAME_SIZE 50
#define CONTENT_SIZE 256

typedef struct {
    char name[FILENAME_SIZE];
    char content[CONTENT_SIZE];
    time_t created_at;
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void init_filesystem(FileSystem *fs) {
    fs->file_count = 0;
    printf("Welcome to the Quantum File System (QFS)!\n");
}

void create_file(FileSystem *fs) {
    if (fs->file_count >= MAX_FILES) {
        printf("Maximum files limit reached!\n");
        return;
    }
    File *new_file = &fs->files[fs->file_count];
    printf("Enter file name: ");
    scanf("%s", new_file->name);
    printf("Enter file content: ");
    getchar(); // consume newline character
    fgets(new_file->content, CONTENT_SIZE, stdin);
    new_file->content[strcspn(new_file->content, "\n")] = '\0'; // remove newline
    new_file->created_at = time(NULL);
    fs->file_count++;
    printf("File '%s' created successfully!\n", new_file->name);
}

void read_file(FileSystem *fs) {
    char filename[FILENAME_SIZE];
    printf("Enter file name to read: ");
    scanf("%s", filename);

    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("File Name: %s\n", fs->files[i].name);
            printf("Content: %s\n", fs->files[i].content);
            printf("Created At: %s", ctime(&fs->files[i].created_at));
            return;
        }
    }
    printf("File '%s' not found!\n", filename);
}

void delete_file(FileSystem *fs) {
    char filename[FILENAME_SIZE];
    printf("Enter file name to delete: ");
    scanf("%s", filename);
    
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1]; // shift files left
            }
            fs->file_count--;
            printf("File '%s' deleted successfully!\n", filename);
            return;
        }
    }
    printf("File '%s' not found!\n", filename);
}

void list_files(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("No files in the system!\n");
        return;
    }
    printf("Listing all files:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("%d. %s (Created at: %s)", i + 1, fs->files[i].name, ctime(&fs->files[i].created_at));
    }
}

void quantum_mode(FileSystem *fs) {
    printf("Entering Quantum Mode... It's all about the possibilities!\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("Would you like to read the content of file: %s? (y/n)\n", fs->files[i].name);
        char response;
        scanf(" %c", &response);
        if (response == 'y') {
            printf("Reading file: %s\n", fs->files[i].name);
            printf("Content: %s\n", fs->files[i].content);
        } else {
            printf("Skipping file: %s\n", fs->files[i].name);
        }
    }
}

int main() {
    FileSystem fs;
    init_filesystem(&fs);
    
    int choice;
    do {
        printf("\n--- Quantum File System Menu ---\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Delete File\n");
        printf("4. List Files\n");
        printf("5. Quantum Mode\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_file(&fs); break;
            case 2: read_file(&fs); break;
            case 3: delete_file(&fs); break;
            case 4: list_files(&fs); break;
            case 5: quantum_mode(&fs); break;
            case 6: printf("Exiting Quantum File System. Until we meet again...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}