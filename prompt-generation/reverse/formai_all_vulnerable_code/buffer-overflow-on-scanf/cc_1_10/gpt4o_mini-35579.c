//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10  // Default maximum files
#define MAX_FILENAME_LEN 20
#define MAX_FILESIZE 100

typedef struct {
    char name[MAX_FILENAME_LEN];
    char content[MAX_FILESIZE];
    int size;
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} FileSystem;

void init_file_system(FileSystem *fs) {
    fs->count = 0;
}

int create_file(FileSystem *fs, const char *name, const char *content) {
    if (fs->count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return -1;
    }
    
    strcpy(fs->files[fs->count].name, name);
    strncpy(fs->files[fs->count].content, content, MAX_FILESIZE);
    fs->files[fs->count].size = strlen(content);
    fs->count++;
    return 0;
}

void read_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Contents of file '%s': %s\n", name, fs->files[i].content);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

int delete_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            for (int j = i; j < fs->count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->count--;
            printf("File '%s' deleted successfully.\n", name);
            return 0;
        }
    }
    printf("Error: File '%s' not found.\n", name);
    return -1;
}

void list_files(FileSystem *fs) {
    if (fs->count == 0) {
        printf("No files in the system.\n");
        return;
    }
    printf("Files in the system:\n");
    for (int i = 0; i < fs->count; i++) {
        printf(" - %s (Size: %d)\n", fs->files[i].name, fs->files[i].size);
    }
}

int main(int argc, char *argv[]) {
    FileSystem fs;
    init_file_system(&fs);

    int choice, fileSize;
    char filename[MAX_FILENAME_LEN];
    char fileContent[MAX_FILESIZE];

    while (1) {
        printf("\nFile System Simulation\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Delete File\n");
        printf("4. List Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, MAX_FILENAME_LEN, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline

                printf("Enter file content: ");
                fgets(fileContent, MAX_FILESIZE, stdin);
                fileContent[strcspn(fileContent, "\n")] = 0;  // Remove newline

                create_file(&fs, filename, fileContent);
                break;

            case 2:
                printf("Enter filename to read: ");
                fgets(filename, MAX_FILENAME_LEN, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline

                read_file(&fs, filename);
                break;

            case 3:
                printf("Enter filename to delete: ");
                fgets(filename, MAX_FILENAME_LEN, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline

                delete_file(&fs, filename);
                break;

            case 4:
                list_files(&fs);
                break;

            case 5:
                printf("Exiting the file system simulation.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}