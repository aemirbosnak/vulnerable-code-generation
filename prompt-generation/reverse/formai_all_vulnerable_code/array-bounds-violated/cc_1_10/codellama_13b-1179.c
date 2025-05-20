//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: relaxed
/*
 * A unique C Compression algorithm example program in a relaxed style.
 * This program compresses a given file by removing redundant characters
 * and replacing them with a single character.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Create a buffer for reading the file
    char buffer[BUFFER_SIZE];

    // Create a hash table for storing the unique characters
    char unique_chars[256];
    memset(unique_chars, 0, 256);

    // Read the file and populate the hash table
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (unique_chars[buffer[i]] == 0) {
                unique_chars[buffer[i]] = 1;
            }
        }
    }

    // Close the input file
    fclose(fp);

    // Open the output file
    FILE *ofp = fopen("compressed.txt", "w");
    if (ofp == NULL) {
        fprintf(stderr, "Unable to open output file\n");
        return 1;
    }

    // Read the file again and compress it
    fp = fopen(argv[1], "r");
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (unique_chars[buffer[i]] == 1) {
                fprintf(ofp, "%c", buffer[i]);
            }
        }
    }

    // Close the output file
    fclose(ofp);

    return 0;
}