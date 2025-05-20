//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: immersive
/*
 * File System Simulation Program
 *
 * This program simulates a file system with the following features:
 * 1. Directory creation and deletion
 * 2. File creation and deletion
 * 3. File read and write
 * 4. Directory listing
 *
 * This program is designed to be used as a sample code for C programming.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIR_NAME_LEN 32
#define MAX_FILE_NAME_LEN 32
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    char contents[MAX_FILE_SIZE];
} File;

typedef struct {
    char name[MAX_DIR_NAME_LEN];
    File* files[MAX_DIR_NAME_LEN];
} Directory;

Directory* create_directory(char* name) {
    Directory* dir = (Directory*)malloc(sizeof(Directory));
    strcpy(dir->name, name);
    return dir;
}

File* create_file(char* name) {
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    return file;
}

void delete_directory(Directory* dir) {
    free(dir);
}

void delete_file(File* file) {
    free(file);
}

void read_file(File* file) {
    printf("File contents: %s\n", file->contents);
}

void write_file(File* file, char* contents) {
    strcpy(file->contents, contents);
}

void list_directory(Directory* dir) {
    printf("Directory: %s\n", dir->name);
    for (int i = 0; i < MAX_DIR_NAME_LEN; i++) {
        if (dir->files[i] != NULL) {
            printf("  File: %s\n", dir->files[i]->name);
        }
    }
}

int main() {
    Directory* root = create_directory("root");
    Directory* dir1 = create_directory("dir1");
    Directory* dir2 = create_directory("dir2");
    File* file1 = create_file("file1");
    File* file2 = create_file("file2");

    write_file(file1, "This is the contents of file1.");
    write_file(file2, "This is the contents of file2.");

    root->files[0] = dir1;
    root->files[1] = dir2;
    root->files[2] = file1;
    root->files[3] = file2;

    dir1->files[0] = file1;
    dir2->files[0] = file2;

    list_directory(root);

    delete_directory(dir1);
    delete_directory(dir2);
    delete_file(file1);
    delete_file(file2);

    return 0;
}