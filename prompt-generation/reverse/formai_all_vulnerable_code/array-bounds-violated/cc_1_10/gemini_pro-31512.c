//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct {
    char name[256];        // File name
    int size;            // File size
    int block_start;    // Starting block number
} File;

// Block structure
typedef struct {
    int size;            // Block size
    char data[512];        // Block data
} Block;

// File system simulation
int main() {
    // Initialize file system
    File files[1024];          // File table
    Block blocks[1024];         // Block table
    int num_files = 0;         // Number of files
    int num_blocks = 0;        // Number of blocks
    int free_blocks[1024];      // Free block list
    int num_free_blocks = 1024; // Number of free blocks

    // Create a new file
    printf("Creating a new file: myfile.txt\n");
    strcpy(files[num_files].name, "myfile.txt");
    files[num_files].size = 512;
    files[num_files].block_start = num_blocks;

    // Allocate blocks for the file
    for (int i = 0; i < files[num_files].size / 512; ++i) {
        blocks[num_blocks].size = 512;
        free_blocks[num_free_blocks] = num_blocks;
        ++num_blocks;
        --num_free_blocks;
    }

    // Write data to the file
    printf("Writing data to the file...\n");
    for (int i = 0; i < files[num_files].size / 512; ++i) {
        sprintf(blocks[files[num_files].block_start + i].data, "Block #%d", i + 1);
    }

    // Read data from the file
    printf("Reading data from the file...\n");
    for (int i = 0; i < files[num_files].size / 512; ++i) {
        printf("%s\n", blocks[files[num_files].block_start + i].data);
    }

    // Delete the file
    printf("Deleting the file...\n");
    for (int i = 0; i < files[num_files].size / 512; ++i) {
        free_blocks[num_free_blocks] = files[num_files].block_start + i;
        ++num_free_blocks;
    }
    num_files--;

    return 0;
}