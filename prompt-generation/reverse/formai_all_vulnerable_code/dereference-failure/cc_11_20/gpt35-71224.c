//FormAI DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    char *infile;
    char *outfile;
    size_t infile_length;
    size_t outfile_length;
    unsigned char *buffer = malloc(BLOCK_SIZE);
    int block_count = 0;
    int block_found = 0;
    FILE *input_fp;
    FILE *output_fp;

    if (argc != 3) {
        printf("Usage: %s [infile] [outfile]\n", argv[0]);
        return 1;
    }

    infile = argv[1];
    outfile = argv[2];

    infile_length = strlen(infile);
    outfile_length = strlen(outfile);

    if ((infile_length < 4 || strcasecmp(infile + infile_length - 4, ".bin") != 0) ||
        (outfile_length < 4 || strcasecmp(outfile + outfile_length - 4, ".bin") != 0)) {
        printf("Input and output files must have the .bin extension!\n");
        return 2;
    }

    input_fp = fopen(infile, "r");
    output_fp = fopen(outfile, "w");

    if (input_fp == NULL) {
        printf("Error opening input file %s\n", infile);
        return 3;
    }

    if (output_fp == NULL) {
        printf("Error opening output file %s\n", outfile);
        return 4;
    }

    printf("Searching for readable blocks...\n");

    while (!feof(input_fp)) {
        size_t bytes_read = fread(buffer, sizeof(char), BLOCK_SIZE, input_fp);

        block_count++;

        if (bytes_read == BLOCK_SIZE) {
            // Check for readable block
            if (buffer[0] == 0x01 || buffer[0] == 0x02) {
                block_found++;

                // Write block to output file
                fwrite(buffer, sizeof(char), BLOCK_SIZE, output_fp);
            }
        }
    }

    fclose(input_fp);
    fclose(output_fp);
    free(buffer);

    if (block_found > 0) {
        printf("Recovered %d block%s from %d total blocks.\n", block_found, block_found > 1 ? "s" : "", block_count);
    } else {
        printf("No readable blocks found in %d blocks.\n", block_count);
    }

    return 0;
}