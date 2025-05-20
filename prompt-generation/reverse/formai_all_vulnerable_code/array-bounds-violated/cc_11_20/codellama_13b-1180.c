//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: calm
// File system simulation example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define NUM_BLOCKS 1000

typedef struct {
    char name[256];
    int size;
    int blocks[NUM_BLOCKS];
} File;

int main() {
    File file;
    char command;
    int block_num;
    int block_size;

    while (1) {
        printf("File system simulation program\n");
        printf("---------------------------\n");
        printf("Enter a command (c, w, r, e, d): ");
        scanf("%c", &command);

        switch (command) {
            case 'c':
                printf("Creating new file...\n");
                printf("Enter file name: ");
                scanf("%s", file.name);
                printf("Enter file size: ");
                scanf("%d", &file.size);
                for (int i = 0; i < NUM_BLOCKS; i++) {
                    file.blocks[i] = -1;
                }
                printf("File created successfully!\n");
                break;
            case 'w':
                printf("Writing to file...\n");
                printf("Enter block number: ");
                scanf("%d", &block_num);
                printf("Enter block size: ");
                scanf("%d", &block_size);
                if (block_num < NUM_BLOCKS) {
                    file.blocks[block_num] = block_size;
                    printf("Block written successfully!\n");
                } else {
                    printf("Block number out of range!\n");
                }
                break;
            case 'r':
                printf("Reading from file...\n");
                printf("Enter block number: ");
                scanf("%d", &block_num);
                if (block_num < NUM_BLOCKS) {
                    block_size = file.blocks[block_num];
                    if (block_size != -1) {
                        printf("Block read successfully!\n");
                    } else {
                        printf("Block number out of range!\n");
                    }
                } else {
                    printf("Block number out of range!\n");
                }
                break;
            case 'e':
                printf("Erasing file...\n");
                file.size = 0;
                for (int i = 0; i < NUM_BLOCKS; i++) {
                    file.blocks[i] = -1;
                }
                printf("File erased successfully!\n");
                break;
            case 'd':
                printf("Deleting file...\n");
                printf("Enter file name: ");
                scanf("%s", file.name);
                if (strcmp(file.name, file.name) == 0) {
                    file.size = 0;
                    for (int i = 0; i < NUM_BLOCKS; i++) {
                        file.blocks[i] = -1;
                    }
                    printf("File deleted successfully!\n");
                } else {
                    printf("File not found!\n");
                }
                break;
            default:
                printf("Invalid command!\n");
                break;
        }

        printf("\n");
    }

    return 0;
}