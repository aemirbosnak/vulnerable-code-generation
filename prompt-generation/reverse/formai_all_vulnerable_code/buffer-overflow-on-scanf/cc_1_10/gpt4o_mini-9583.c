//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define FILE_NAME_LEN 50
#define CONTENT_LEN 200

typedef struct {
    char name[FILE_NAME_LEN];
    char content[CONTENT_LEN];
    time_t creation_time;
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void initializeFileSystem(FileSystem *fs) {
    fs->file_count = 0;
}

int createFile(FileSystem *fs, const char *name, const char *content) {
    if (fs->file_count >= MAX_FILES) {
        printf("The wasteland of our past holds no more memory.\n");
        return -1;
    }
    strncpy(fs->files[fs->file_count].name, name, FILE_NAME_LEN);
    strncpy(fs->files[fs->file_count].content, content, CONTENT_LEN);
    fs->files[fs->file_count].creation_time = time(NULL);
    fs->file_count++;
    printf("File '%s' created amid the ashes.\n", name);
    return 0;
}

void listFiles(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("The remnants of memory are barren.\n");
        return;
    }
    printf("Files in the desolation:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("%s (Created: %s)\n", fs->files[i].name, ctime(&fs->files[i].creation_time));
    }
}

void readFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Reading file '%s':\n%s\n", name, fs->files[i].content);
            return;
        }
    }
    printf("The winds whisper no information about '%s'.\n", name);
}

void deleteFile(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->file_count--;
            printf("The file '%s' has been erased from existence.\n", name);
            return;
        }
    }
    printf("No memory remains of '%s' to obliterate.\n", name);
}

int main() {
    FileSystem fs;
    initializeFileSystem(&fs);
    
    int choice;
    char name[FILE_NAME_LEN];
    char content[CONTENT_LEN];

    while (1) {
        printf("\n--- Post-Apocalyptic File System Simulation ---\n");
        printf("1. Create File\n");
        printf("2. List Files\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                fgets(name, FILE_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character

                printf("Enter file content: ");
                fgets(content, CONTENT_LEN, stdin);
                content[strcspn(content, "\n")] = 0; // Remove newline character

                createFile(&fs, name, content);
                break;
            case 2:
                listFiles(&fs);
                break;
            case 3:
                printf("Enter file name to read: ");
                fgets(name, FILE_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                readFile(&fs, name);
                break;
            case 4:
                printf("Enter file name to delete: ");
                fgets(name, FILE_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                deleteFile(&fs, name);
                break;
            case 5:
                printf("Exiting the remnants of our digital wasteland...\n");
                exit(0);
            default:
                printf("A shadowy error haunts your choice. Try again.\n");
                break;
        }
    }

    return 0;
}