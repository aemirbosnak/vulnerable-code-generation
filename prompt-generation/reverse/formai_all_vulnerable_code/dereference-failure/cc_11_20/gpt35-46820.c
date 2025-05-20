//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if input file is provided
    if (argc < 2) {
        fprintf(stderr, "Error: no input file provided\n");
        exit(1);
    }
    
    // Open input file
    FILE *infile = fopen(argv[1], "rb");
    if (infile == NULL) {
        fprintf(stderr, "Error: could not open input file\n");
        exit(1);
    }
    
    // Allocate memory for input buffer
    fseek(infile, 0, SEEK_END);
    long input_size = ftell(infile);
    fseek(infile, 0, SEEK_SET);
    char *input_buffer = malloc(input_size);
    if (input_buffer == NULL) {
        fprintf(stderr, "Error: could not allocate memory for input buffer\n");
        exit(1);
    }
    
    // Read input file into buffer
    fread(input_buffer, sizeof(char), input_size, infile);
    fclose(infile);
    
    // Allocate memory for output buffer
    long output_size = input_size;
    char *output_buffer = malloc(output_size);
    if (output_buffer == NULL) {
        fprintf(stderr, "Error: could not allocate memory for output buffer\n");
        exit(1);
    }
    
    // Compress input buffer using Turing's compression algorithm
    char last_char = 0;
    int repeat_count = 0;
    long output_index = 0;
    for (long i = 0; i < input_size; i++) {
        char current_char = input_buffer[i];
        if (i == 0) {
            // First character in input buffer
            last_char = current_char;
            repeat_count = 1;
        } else if (current_char == last_char) {
            // Found a repeating character
            repeat_count++;
        } else {
            // Found a non-repeating character
            if (repeat_count > 2) {
                // Compress repeating characters as a number followed by the character
                output_index += sprintf(&output_buffer[output_index], "%d%c", repeat_count, last_char);
            } else {
                // Copy non-repeating character to output buffer
                for (int j = 0; j < repeat_count; j++) {
                    output_buffer[output_index] = last_char;
                    output_index++;
                }
            }
            // Update last character and repeat count
            last_char = current_char;
            repeat_count = 1;
        }
    }
    // Handle the final run of repeating characters
    if (repeat_count > 2) {
        output_index += sprintf(&output_buffer[output_index], "%d%c", repeat_count, last_char);
    } else {
        for (int j = 0; j < repeat_count; j++) {
            output_buffer[output_index] = last_char;
            output_index++;
        }
    }
    // Update output size to actual size used
    output_size = output_index;
    
    // Open output file
    char output_filename[256];
    strcpy(output_filename, argv[1]);
    strcat(output_filename, ".compressed");
    FILE *outfile = fopen(output_filename, "wb");
    if (outfile == NULL) {
        fprintf(stderr, "Error: could not open output file\n");
        exit(1);
    }
    
    // Write compressed data to output file
    fwrite(output_buffer, sizeof(char), output_size, outfile);
    fclose(outfile);
    
    // Free memory
    free(input_buffer);
    free(output_buffer);
    
    return 0;
}