//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
/*
 * Word Frequency Counter
 *
 * A program to count the frequency of words in a given text.
 * The program takes a file name as input and prints the word frequency.
 * The program is written in a portable style, so it can be compiled and run on different platforms.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to count the frequency of words in a given text
void count_word_frequency(const char *file_name) {
    // Open the file
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    // Read the file and count the frequency of words
    char word[256];
    int word_count = 0;
    int word_frequency[256];
    while (fscanf(fp, "%s", word) != EOF) {
        int word_length = strlen(word);
        if (word_length > 0 && word_length < 256) {
            word_count++;
            word_frequency[word_length]++;
        }
    }

    // Print the frequency of each word
    for (int i = 0; i < 256; i++) {
        if (word_frequency[i] > 0) {
            printf("%d\t%d\n", i, word_frequency[i]);
        }
    }

    // Close the file
    fclose(fp);
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Call the function to count the word frequency
    count_word_frequency(argv[1]);

    return 0;
}