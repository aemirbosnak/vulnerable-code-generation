//FormAI DATASET v1.0 Category: File system simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 20
#define BLOCK_SIZE 1024
#define MAX_BLOCKS 1024

typedef struct file {
    char name[MAX_FILENAME];
    int size;
    int block_count;
    int blocks[MAX_BLOCKS];
} file;

int main() {
    file files[MAX_BLOCKS];
    int free_blocks[MAX_BLOCKS] = {0};
    int total_size = MAX_BLOCKS * BLOCK_SIZE;
    int current_size = 0;

    char input[50];
    printf("Welcome to the file system simulation!\n");

    while (1) {
        printf("\nEnter 'create' to create a new file\n");
        printf("Enter 'delete' to delete a file\n");
        printf("Enter 'list' to list all files\n");
        printf("Enter 'exit' to exit the program\n");

        scanf("%s", input);

        if (strcmp(input, "create") == 0) {
            char name[MAX_FILENAME];
            int size;
            printf("\nEnter a file name (max %d characters): ", MAX_FILENAME);
            scanf("%s", name);
            printf("Enter file size (bytes): ");
            scanf("%d", &size);

            if (size > (total_size - current_size)) {
                printf("Error: Not enough space to create file\n");
            } else {
                // Allocate blocks for file
                int block_count = (size + (BLOCK_SIZE - 1)) / BLOCK_SIZE;
                int blocks[block_count];
                int i = 0;
                for (i = 0; i < block_count; i++) {
                    // Find free block
                    int j;
                    for (j = 0; j < MAX_BLOCKS; j++) {
                        if (free_blocks[j] == 0) {
                            // Use this block
                            free_blocks[j] = 1;
                            blocks[i] = j;
                            current_size += BLOCK_SIZE;
                            break;
                        }
                    }
                }

                // Save file information
                int index = -1;
                for (i = 0; i < MAX_BLOCKS; i++) {
                    if (files[i].name[0] == '\0') {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Error: Maximum file count exceeded\n");
                } else {
                    strcpy(files[index].name, name);
                    files[index].size = size;
                    files[index].block_count = block_count;
                    for (i = 0; i < block_count; i++) {
                        files[index].blocks[i] = blocks[i];
                    }

                    printf("File created successfully\n");
                }
            }
        } else if (strcmp(input, "delete") == 0) {
            char name[MAX_FILENAME];
            printf("\nEnter the name of the file to delete: ");
            scanf("%s", name);

            int i = 0;
            int found = 0;
            for (i = 0; i < MAX_BLOCKS && !found; i++) {
                if (strcmp(files[i].name, name) == 0) {
                    found = 1;

                    // Free blocks
                    int j = 0;
                    for (j = 0; j < files[i].block_count; j++) {
                        free_blocks[files[i].blocks[j]] = 0;
                        current_size -= BLOCK_SIZE;
                    }

                    // Clear file information
                    files[i].name[0] = '\0';
                    files[i].size = 0;
                    files[i].block_count = 0;
                    for (j = 0; j < MAX_BLOCKS; j++) {
                        files[i].blocks[j] = -1;
                    }

                    printf("File deleted successfully\n");
                }
            }

            if (!found) {
                printf("Error: File not found\n");
            }
        } else if (strcmp(input, "list") == 0) {
            printf("\n%-20s%-10s%-16s\n", "Name", "Size", "Block Count");
            int i = 0;
            for (i = 0; i < MAX_BLOCKS; i++) {
                if (files[i].name[0] != '\0') {
                    printf("%-20s%-10d%-16d\n", files[i].name, files[i].size, files[i].block_count);
                }
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}