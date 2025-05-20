//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50
#define FILE_CONTENT_LENGTH 256

typedef struct {
    char name[FILENAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];
    int is_active;
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void initialize_file_system(FileSystem *fs) {
    fs->file_count = 0;
}

int create_file(FileSystem *fs, const char *name, const char *content) {
    if (fs->file_count >= MAX_FILES) {
        printf("Cyber Cache Overloaded! Unable to create new file: %s\n", name);
        return -1;
    }
    
    strcpy(fs->files[fs->file_count].name, name);
    strncpy(fs->files[fs->file_count].content, content, FILE_CONTENT_LENGTH);
    fs->files[fs->file_count].is_active = 1;
    fs->file_count++;
    
    printf("File '%s' created in the Neon Database with a cool callback:\n%s\n", name, content);
    return 0;
}

void read_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0 && fs->files[i].is_active) {
            printf("Reading %s from the Neon Database...\nContent:\n%s\n", name, fs->files[i].content);
            return;
        }
    }
    printf("File '%s' not found in the black market of data!\n", name);
}

int delete_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0 && fs->files[i].is_active) {
            fs->files[i].is_active = 0; // Mark the file as deleted
            printf("File '%s' has been erased from existence...\n", name);
            return 0;
        }
    }
    printf("File '%s' couldn't be found on the data grid.\n", name);
    return -1;
}

void list_files(FileSystem *fs) {
    printf("Listing all active files in the Cyber Vault:\n");
    for (int i = 0; i < fs->file_count; i++) {
        if (fs->files[i].is_active) {
            printf("- %s\n", fs->files[i].name);
        }
    }
}

int main() {
    FileSystem fs;
    initialize_file_system(&fs);
    
    char command[10], filename[FILENAME_LENGTH], content[FILE_CONTENT_LENGTH];

    while (1) {
        printf("\nEnter command (create/read/delete/list/exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "create") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            printf("Enter file content: ");
            getchar(); // Clear the newline from the buffer.
            fgets(content, FILE_CONTENT_LENGTH, stdin);
            content[strcspn(content, "\n")] = 0; // Remove newline.
            create_file(&fs, filename, content);
        } else if (strcmp(command, "read") == 0) {
            printf("Enter filename to read: ");
            scanf("%s", filename);
            read_file(&fs, filename);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter filename to delete: ");
            scanf("%s", filename);
            delete_file(&fs, filename);
        } else if (strcmp(command, "list") == 0) {
            list_files(&fs);
        } else if (strcmp(command, "exit") == 0) {
            printf("Shutting down the Neon Database...\n");
            break;
        } else {
            printf("Unknown command! Try again, data hacker.\n");
        }
    }

    return 0;
}