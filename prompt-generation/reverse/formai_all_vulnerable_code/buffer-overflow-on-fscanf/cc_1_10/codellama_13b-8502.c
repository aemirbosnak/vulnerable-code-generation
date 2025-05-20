//Code Llama-13B DATASET v1.0 Category: Word Count Tool ; Style: automated
/*
 * Word Count Tool in C
 * Automated
 *
 * Usage: ./word_count <input_file> <output_file>
 *
 * Example: ./word_count input.txt output.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    // Check if input file and output file are provided
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open input file and output file
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    // Check if input file and output file are valid
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Initialize variables
    char word[MAX_WORD_LENGTH];
    int word_count = 0;

    // Read words from input file and count them
    while (fscanf(input_file, "%s", word) != EOF) {
        word_count++;
    }

    // Write the word count to the output file
    fprintf(output_file, "%d\n", word_count);

    // Close input file and output file
    fclose(input_file);
    fclose(output_file);

    return 0;
}