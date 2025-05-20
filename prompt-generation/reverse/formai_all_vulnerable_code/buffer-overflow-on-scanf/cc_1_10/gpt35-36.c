//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define BLOCK_SIZE 4096

/* Define structures for file and block */
typedef struct {
    char *name;                  // File name
    int size;                    // File size
    int block_nums;              // Number of blocks of this file
    int block_indices[MAX_FILES];// List of starting block indices for this file
} File;

typedef struct {
    char data[BLOCK_SIZE];        // Data stored in this block
    int next_block_index;         // Index of next block
} Block;

/* Define global variables */
File files[MAX_FILES];            // List of all files in filesystem
Block blocks[MAX_FILES];          // List of all blocks in filesystem
int free_block_index = 0;         // Current index of the first free block
int num_files = 0;                // Number of files in filesystem

/* Create a new file */
void create_file(char *name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    File new_file;
    new_file.name = name;
    new_file.size = size;
    new_file.block_nums = 0;
    memset(new_file.block_indices, -1, sizeof(new_file.block_indices));

    int blocks_needed = size / BLOCK_SIZE + 1;
    int i;
    for (i = 0; i < blocks_needed; i++) {
        if (free_block_index >= MAX_FILES) {
            printf("Error: Not enough space in filesystem.\n");
            break;
        }
        new_file.block_indices[i] = free_block_index++;
        blocks[new_file.block_indices[i]].next_block_index = -1;
        new_file.block_nums++;
    }
    files[num_files++] = new_file;

    printf("File created: %s\n", name);
}

/* Delete an existing file */
void delete_file(char *name) {
    int i, j;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            for (j = 0; j < files[i].block_nums; j++) {
                blocks[files[i].block_indices[j]].next_block_index = -1;
            }
            free_block_index -= files[i].block_nums;
            memcpy(files + i, files + i + 1, (num_files - i - 1) * sizeof(File));
            num_files--;
            printf("File deleted: %s\n", name);
            return;
        }
    }
    printf("Error: Cannot find file.\n");
}

/* Write data to a file */
void write_file(char *name, char *data, int size) {
    int i, j;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if (size > files[i].size) {
                printf("Error: Not enough space in file.\n");
                return;
            }
            int bytes_written = 0;
            int block_index = files[i].block_indices[0];
            while (block_index != -1 && bytes_written < size) {
                memcpy(blocks[block_index].data, data + bytes_written, BLOCK_SIZE);
                bytes_written += BLOCK_SIZE;
                block_index = blocks[block_index].next_block_index;
            }
            printf("Data written to file: %s\n", name);
            return;
        }
    }
    printf("Error: Cannot find file.\n");
}

/* Read data from a file */
void read_file(char *name, char *buffer) {
    int i, j;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int bytes_read = 0;
            int block_index = files[i].block_indices[0];
            while (block_index != -1 && bytes_read < files[i].size) {
                memcpy(buffer + bytes_read, blocks[block_index].data, BLOCK_SIZE);
                bytes_read += BLOCK_SIZE;
                block_index = blocks[block_index].next_block_index;
            }
            printf("Data read from file: %s\n", name);
            return;
        }
    }
    printf("Error: Cannot find file.\n");
}

/* Main function */
int main() {
    int option;
    char name[100];
    char data[BLOCK_SIZE];
    int size;

    while (1) {
        printf("\n  Filesystem Menu\n");
        printf("--------------------\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Write Data to File\n");
        printf("4. Read Data from File\n");
        printf("5. Exit\n");

        printf("\nEnter an option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file size: ");
            scanf("%d", &size);
            create_file(name, size);
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
            break;
        case 3:
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter data to write: ");
            scanf(" %[^\n]s", data);
            write_file(name, data, strlen(data));
            break;
        case 4:
            printf("Enter file name: ");
            scanf("%s", name);
            char buffer[MAX_FILES * BLOCK_SIZE];
            read_file(name, buffer);
            printf("Data: %s\n", buffer);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}