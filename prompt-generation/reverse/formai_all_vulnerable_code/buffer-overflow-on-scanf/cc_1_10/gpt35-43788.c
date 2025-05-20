//FormAI DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    unsigned char data[BLOCK_SIZE];
} Block;

// Function to read a block from a file
Block read_block(FILE *file) {
    Block block;
    fread(block.data, BLOCK_SIZE, 1, file);
    return block;
}

// Function to write a block to a file
void write_block(FILE *file, Block block) {
    fwrite(block.data, BLOCK_SIZE, 1, file);
}

// Function to recover data from a damaged file
void recover_data(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found!\n");
        return;
    }

    FILE *output_file = fopen("recovered_data.txt", "wb");
    if (output_file == NULL) {
        printf("Error: Failed to create output file!\n");
        fclose(file);
        return;
    }

    int block_count = 0;
    while (1) {
        Block block = read_block(file);
        if (feof(file)) {
            break;
        }

        // Check if block is corrupted
        int i, sum = 0;
        for (i = 0; i < BLOCK_SIZE; i++) {
            sum += block.data[i];
        }
        if (sum != 0) {
            // If block is corrupted, skip it
            printf("Block %d is corrupted. Skipping...\n", block_count);
            block_count++;
            continue;
        }

        // Write block to output file
        write_block(output_file, block);

        block_count++;
    }

    fclose(file);
    fclose(output_file);
}

int main() {
    char filename[100];
    printf("Enter the filename to recover data from: ");
    scanf("%s", filename);

    printf("Recovering data...\n");
    recover_data(filename);
    printf("Data recovered successfully!\n");

    return 0;
}