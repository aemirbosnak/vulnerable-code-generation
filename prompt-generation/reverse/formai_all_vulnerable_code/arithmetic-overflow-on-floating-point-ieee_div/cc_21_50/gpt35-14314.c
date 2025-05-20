//FormAI DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_CODE_LEN 12              // Maximum bit length of a code
#define MAX_TABLE_SIZE (1 << 12)     // Maximum size of the lookup table
#define MAX_INPUT_SIZE (1 << 19)     // Maximum size of input buffer
#define MAX_OUTPUT_SIZE (1 << 20)    // Maximum size of output buffer

int main(int argc, char *argv[]) {
    uint16_t lookup[MAX_TABLE_SIZE][2];
    uint8_t input_buffer[MAX_INPUT_SIZE];
    uint8_t output_buffer[MAX_OUTPUT_SIZE];
    uint8_t code_buffer[17];
    uint32_t input_size, output_size, table_size;
    int i, j, bit_pos, code_len;
    FILE *input_file, *output_file;

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open input and output files
    input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Error: could not open input file\n");
        return 2;
    }
    output_file = fopen(argv[2], "wb");
    if (!output_file) {
        fclose(input_file);
        fprintf(stderr, "Error: could not open output file\n");
        return 3;
    }

    // Read input file to buffer
    input_size = fread(input_buffer, 1, MAX_INPUT_SIZE, input_file);
    if (input_size == MAX_INPUT_SIZE) {
        fprintf(stderr, "Warning: input file exceeded maximum size\n");
    }

    // Initialize lookup table
    table_size = 0;
    memset(lookup, 0, sizeof(lookup));

    // Build lookup table
    for (i = 0; i < input_size; i++) {
        // Check if code is in table
        for (j = 0; j < table_size; j++) {
            if (lookup[j][1] == input_buffer[i]) {
                break;
            }
        }
        // If code is not in table, add new code
        if (j == table_size) {
            if (table_size == MAX_TABLE_SIZE) {
                fprintf(stderr, "Error: lookup table full\n");
                fclose(input_file);
                fclose(output_file);
                return 4;
            }
            lookup[table_size][0] = table_size;
            lookup[table_size][1] = input_buffer[i];
            table_size++;
        }
    }

    // Write table size to output file
    fwrite(&table_size, sizeof(uint32_t), 1, output_file);

    // Write lookup table to output file
    for (i = 0; i < table_size; i++) {
        fwrite(&lookup[i][0], sizeof(uint16_t), 1, output_file);
        fwrite(&lookup[i][1], sizeof(uint8_t), 1, output_file);
    }

    // Perform compression on input buffer
    bit_pos = 0;
    code_buffer[0] = 0;
    code_len = 1;
    for (i = 0; i < input_size; i++) {
        // Get code for input byte
        for (j = 0; j < table_size; j++) {
            if (lookup[j][1] == input_buffer[i]) {
                break;
            }
        }
        // Write code bits to output buffer
        if (code_len + MAX_CODE_LEN > 16) {
            // Write bytes to output buffer
            output_buffer[output_size++] = code_buffer[0];
            for (j = 1; j < code_len / 8; j++) {
                output_buffer[output_size++] = code_buffer[j];
            }
            // Shift remaining bits to beginning of code buffer
            code_len = code_len % 8;
            if (code_len > 0) {
                code_buffer[0] = code_buffer[8 - code_len];
            }
            for (j = 1; j < 8 - code_len; j++) {
                code_buffer[j] = 0;
            }
            bit_pos = code_len;
        }
        // Append code bits to code buffer
        for (j = MAX_CODE_LEN - 1; j >= 0; j--) {
            code_buffer[bit_pos / 8] |= ((j == lookup[j][0]) ? 1 : 0) << (bit_pos % 8);
            bit_pos++;
            code_len++;
        }
    }
    // Write remaining bits to output buffer
    if (code_len > 1) {
        output_buffer[output_size++] = code_buffer[0];
        for (j = 1; j < code_len / 8; j++) {
            output_buffer[output_size++] = code_buffer[j];
        }
    }

    // Write output buffer to output file
    fwrite(output_buffer, 1, output_size, output_file);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    // Print compression ratio
    printf("Compression ratio: %.2f%%\n", 100.0 * output_size / input_size);

    return 0;
}