//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dir_path = argv[1];

    char *command = (char *)malloc((15 + strlen(dir_path)) * sizeof(char));
    sprintf(command, "du -sb %s", dir_path);

    FILE *fp = popen(command, "r");

    if (fp == NULL) {
        printf("Error: Failed to execute du command\n");
        exit(EXIT_FAILURE);
    }

    char output[256];
    if (fgets(output, sizeof(output), fp) == NULL) {
        printf("No output from command\n");
        exit(EXIT_FAILURE);
    }

    int total_size = atoi(strtok(output, "\t"));

    printf("Total size: %d bytes\n", total_size);

    int blocks_needed = (total_size / BLOCK_SIZE) + ((total_size % BLOCK_SIZE) ? 1 : 0);

    int *block_map = (int *)calloc(blocks_needed, sizeof(int));

    rewind(fp);

    while (fgets(output, sizeof(output), fp) != NULL) {
        char *size_str = strtok(output, "\t");
        int size = atoi(size_str);
        char *path = strtok(NULL, "\n");

        int blocks_used = (size / BLOCK_SIZE) + ((size % BLOCK_SIZE) ? 1 : 0);

        for (int i = 0; i < blocks_needed && blocks_used > 0; i++) {
            if (block_map[i] == 0) {
                blocks_used--;
                block_map[i] = size;
            }
        }

        printf("%s\n", path);
    }

    int free_blocks = 0;
    for (int i = 0; i < blocks_needed; i++) {
        if (block_map[i] == 0) {
            free_blocks++;
        }
    }

    printf("Free space: %d bytes\n", free_blocks * BLOCK_SIZE);

    pclose(fp);
    free(command);
    free(block_map);

    return 0;
}