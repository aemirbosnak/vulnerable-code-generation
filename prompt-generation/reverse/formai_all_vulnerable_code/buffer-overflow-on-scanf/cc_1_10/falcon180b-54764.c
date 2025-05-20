//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} File;

void create_file(File* file, char* name, char* content, int size) {
    strcpy(file->name, name);
    strcpy(file->content, content);
    file->size = size;
}

void delete_file(File* file) {
    memset(file, 0, sizeof(File));
}

void list_files(File* files, int count) {
    printf("List of files:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    // Initialize file system with some files
    File files[3] = {{"file1.txt", "Hello world!", 13},
                     {"file2.txt", "This is a test.", 16},
                     {"file3.txt", "The quick brown fox jumps over the lazy dog.", 43}};
    int file_count = 3;

    // List all files
    list_files(files, file_count);

    // Create a new file
    File new_file;
    printf("Enter file name: ");
    scanf("%s", new_file.name);
    printf("Enter file content: ");
    scanf("%s", new_file.content);
    new_file.size = strlen(new_file.content);
    files[file_count] = new_file;
    file_count++;

    // List all files again
    list_files(files, file_count);

    // Delete a file
    printf("Enter file name to delete: ");
    scanf("%s", new_file.name);
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, new_file.name) == 0) {
            delete_file(&files[i]);
            break;
        }
    }

    // List all files again
    list_files(files, file_count);

    return 0;
}