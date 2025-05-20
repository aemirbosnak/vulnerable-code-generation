//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: light-weight
/*
 * File system simulation example program in a light-weight style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a file
struct file {
    char name[32];
    int size;
    char data[1024];
};

// Structure to represent a directory
struct directory {
    char name[32];
    struct file *files[1024];
};

// Function to create a new file
struct file *create_file(char *name, int size) {
    struct file *file = (struct file *)malloc(sizeof(struct file));
    if (file == NULL) {
        return NULL;
    }
    strcpy(file->name, name);
    file->size = size;
    return file;
}

// Function to create a new directory
struct directory *create_directory(char *name) {
    struct directory *dir = (struct directory *)malloc(sizeof(struct directory));
    if (dir == NULL) {
        return NULL;
    }
    strcpy(dir->name, name);
    return dir;
}

// Function to add a file to a directory
int add_file_to_directory(struct directory *dir, struct file *file) {
    int i;
    for (i = 0; i < 1024; i++) {
        if (dir->files[i] == NULL) {
            dir->files[i] = file;
            return 1;
        }
    }
    return 0;
}

// Function to delete a file from a directory
int delete_file_from_directory(struct directory *dir, struct file *file) {
    int i;
    for (i = 0; i < 1024; i++) {
        if (dir->files[i] == file) {
            dir->files[i] = NULL;
            return 1;
        }
    }
    return 0;
}

// Function to list all files in a directory
void list_files(struct directory *dir) {
    int i;
    for (i = 0; i < 1024; i++) {
        if (dir->files[i] != NULL) {
            printf("File: %s\n", dir->files[i]->name);
        }
    }
}

// Function to simulate a file system
void simulate_file_system() {
    struct directory *root = create_directory("root");
    struct directory *dir1 = create_directory("dir1");
    struct directory *dir2 = create_directory("dir2");
    struct file *file1 = create_file("file1", 1024);
    struct file *file2 = create_file("file2", 2048);
    struct file *file3 = create_file("file3", 4096);
    add_file_to_directory(root, file1);
    add_file_to_directory(root, file2);
    add_file_to_directory(root, file3);
    add_file_to_directory(dir1, file1);
    add_file_to_directory(dir2, file2);
    add_file_to_directory(dir2, file3);
    delete_file_from_directory(dir2, file2);
    list_files(root);
    list_files(dir1);
    list_files(dir2);
}

int main() {
    srand(time(NULL));
    simulate_file_system();
    return 0;
}