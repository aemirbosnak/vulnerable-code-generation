//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
/*
 * Word Frequency Counter
 *
 * This program counts the frequency of each word in a given text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char *word;
    int word_length;
    int word_count = 0;
    int word_frequency[MAX_WORD_LENGTH];
    int i;

    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Read the input file and count the frequency of each word
    while (fscanf(fp, "%s", word) != EOF) {
        word_length = strlen(word);
        if (word_length < MAX_WORD_LENGTH) {
            word_frequency[word_length]++;
            word_count++;
        }
    }

    // Print the frequency of each word
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word_frequency[i] != 0) {
            printf("%d\t%d\n", i, word_frequency[i]);
        }
    }

    // Close the input file
    fclose(fp);

    return 0;
}