//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 10000
#define MAX_NUM_FILES 100

// File structure
typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    char file_data[MAX_FILE_SIZE];
    int file_size;
} file_t;

// Directory structure
typedef struct {
    char dir_name[MAX_FILE_NAME_LENGTH];
    int num_files;
    file_t *files[MAX_NUM_FILES];
} dir_t;

// Create a new directory
dir_t *create_dir(char *dir_name) {
    dir_t *new_dir = (dir_t *)malloc(sizeof(dir_t));
    strcpy(new_dir->dir_name, dir_name);
    new_dir->num_files = 0;
    for (int i = 0; i < MAX_NUM_FILES; i++) {
        new_dir->files[i] = NULL;
    }
    return new_dir;
}

// Create a new file
void create_file(dir_t *dir, char *file_name, char *file_data, int file_size) {
    file_t *new_file = (file_t *)malloc(sizeof(file_t));
    strcpy(new_file->filename, file_name);
    strcpy(new_file->file_data, file_data);
    new_file->file_size = file_size;
    dir->files[dir->num_files++] = new_file;
}

// List files in a directory
void list_files(dir_t *dir) {
    printf("Directory: %s\n", dir->dir_name);
    printf("Number of files: %d\n", dir->num_files);
    for (int i = 0; i < dir->num_files; i++) {
        printf("File %d:\n", i+1);
        printf("Filename: %s\n", dir->files[i]->filename);
        printf("File Size: %d bytes\n\n", dir->files[i]->file_size);
    }
}

// Main function
int main() {
    // Create a new directory
    dir_t *root_dir = create_dir("root");

    // Create a new file
    create_file(root_dir, "file1.txt", "Hello World!", 12);

    // List files in the directory
    list_files(root_dir);

    return 0;
}