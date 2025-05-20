//FormAI DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_blocks, block_size;
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);
    printf("Enter the block size: ");
    scanf("%d", &block_size);

    char *fs = (char*) malloc(num_blocks * block_size * sizeof(char));

    while(1) {
        char command[100];
        printf("\nEnter a command (create/read/write/delete/exit): ");
        scanf("%s", command);

        if(strcmp(command, "create") == 0) {
            char file_name[100];
            printf("Enter the file name: ");
            scanf("%s", file_name);

            int file_size, blocks_needed;
            printf("Enter the file size: ");
            scanf("%d", &file_size);

            if(file_size % block_size == 0) {
                blocks_needed = file_size / block_size;
            } else {
                blocks_needed = file_size / block_size + 1;
            }

            int free_blocks = 0;
            for(int i = 0; i < num_blocks; i++) {
                if(fs[i] == '\0') {
                    free_blocks++;
                    if(free_blocks == blocks_needed) {
                        int starting_block = i - blocks_needed + 1;
                        for(int j = starting_block; j <= i; j++) {
                            fs[j] = '1';
                        }
                        printf("File \"%s\" created. Starting block: %d\n", file_name, starting_block);
                        break;
                    }
                } else {
                    free_blocks = 0;
                }
            }
        } else if(strcmp(command, "read") == 0) {
            char file_name[100];
            printf("Enter the file name: ");
            scanf("%s", file_name);

            int starting_block;
            printf("Enter the starting block: ");
            scanf("%d", &starting_block);

            int block_read = 1;
            int total_read = block_size;
            printf("%c", fs[starting_block]);
            while(block_read < block_size && total_read < block_size && fs[starting_block + block_read] != '\0') {
                printf("%c", fs[starting_block + block_read]);
                block_read++;
                total_read++;
            }
        } else if(strcmp(command, "write") == 0) {
            char file_name[100];
            printf("Enter the file name: ");
            scanf("%s", file_name);

            int starting_block;
            printf("Enter the starting block: ");
            scanf("%d", &starting_block);

            getchar();
            char input = getchar();
            fs[starting_block] = input;

        } else if(strcmp(command, "delete") == 0) {
            char file_name[100];
            printf("Enter the file name: ");
            scanf("%s", file_name);

            int starting_block;
            printf("Enter the starting block: ");
            scanf("%d", &starting_block);

            while(fs[starting_block] != '\0') {
                fs[starting_block] = '\0';
                starting_block++;
            }
            printf("File \"%s\" deleted.\n", file_name);

        } else if(strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            return 0;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}