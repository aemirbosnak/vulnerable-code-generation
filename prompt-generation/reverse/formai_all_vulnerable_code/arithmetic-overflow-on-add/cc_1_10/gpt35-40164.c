//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10 // maximum number of files in the file system
#define MAX_NAME_LENGTH 20 // maximum length of file names
#define BLOCK_SIZE 64 // size of each block in the file system
#define BLOCKS_PER_FILE 3 // number of blocks each file occupies

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start_block; // block number of the first block occupied by the file
    int length; // number of blocks occupied by the file
} file;

// initialization function for the file system
void init_file_system(char* file_system, int size) {
    memset(file_system, 0, size); // set all bytes in file system to zero
}

// function to create a new file in the file system
int create_file(char* file_system, file* files, char* name) {
    // find the first free block in the file system
    int free_block = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].length == 0) {
            free_block = i * BLOCKS_PER_FILE;
            break;
        }
    }
    if (free_block == -1) {
        return -1; // no free blocks left
    }
    // check if file with same name already exists
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return -2; // file with same name already exists
        }
    }
    // assign blocks to the new file
    for (int i = 0; i < BLOCKS_PER_FILE; i++) {
        file_system[free_block + i] = 1; // mark block as occupied
    }
    // add file to list of files
    strcpy(files[free_block / BLOCKS_PER_FILE].name, name);
    files[free_block / BLOCKS_PER_FILE].start_block = free_block;
    files[free_block / BLOCKS_PER_FILE].length = BLOCKS_PER_FILE;
    return 0; // file created successfully
}

// function to delete a file from the file system
int delete_file(char* file_system, file* files, char* name) {
    // find file with matching name
    int file_index = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        return -1; // file not found
    }
    // free blocks occupied by the file
    for (int i = 0; i < BLOCKS_PER_FILE; i++) {
        file_system[files[file_index].start_block + i] = 0; // mark block as free
    }
    // remove file from list of files
    memset(&files[file_index], 0, sizeof(file));
    return 0; // file deleted successfully
}

int main() {
    char file_system[MAX_FILES * BLOCKS_PER_FILE * BLOCK_SIZE]; // array to hold file system data
    file files[MAX_FILES]; // array to hold file metadata
    init_file_system(file_system, sizeof(file_system));
    create_file(file_system, files, "test.txt");
    create_file(file_system, files, "example.c");
    create_file(file_system, files, "data.bin");
    delete_file(file_system, files, "example.c");
    return 0;
}