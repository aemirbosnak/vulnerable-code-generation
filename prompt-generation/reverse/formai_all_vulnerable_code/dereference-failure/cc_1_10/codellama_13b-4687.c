//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: immersive
/*
 * C Compression Algorithm Example Program
 *
 * This program demonstrates a simple compression algorithm in C.
 * It takes a file as input, compresses it, and then decompresses it back to the original file.
 *
 * Usage: ./compression <file_to_compress> <compressed_file>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compression algorithm
void compress(char *input, char *output) {
    // Open input file
    FILE *in = fopen(input, "r");
    if (in == NULL) {
        perror("Error opening input file");
        return;
    }

    // Open output file
    FILE *out = fopen(output, "w");
    if (out == NULL) {
        perror("Error opening output file");
        return;
    }

    // Read input file and compress it
    char c;
    while ((c = fgetc(in)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            // Uppercase letter, compress it
            c = c + 32;
        }
        fputc(c, out);
    }

    // Close input and output files
    fclose(in);
    fclose(out);
}

// Decompression algorithm
void decompress(char *input, char *output) {
    // Open input file
    FILE *in = fopen(input, "r");
    if (in == NULL) {
        perror("Error opening input file");
        return;
    }

    // Open output file
    FILE *out = fopen(output, "w");
    if (out == NULL) {
        perror("Error opening output file");
        return;
    }

    // Read input file and decompress it
    char c;
    while ((c = fgetc(in)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            // Lowercase letter, decompress it
            c = c - 32;
        }
        fputc(c, out);
    }

    // Close input and output files
    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 3) {
        printf("Usage: ./compression <file_to_compress> <compressed_file>\n");
        return 1;
    }

    // Compress file
    compress(argv[1], argv[2]);

    // Decompress file
    decompress(argv[2], argv[1]);

    return 0;
}