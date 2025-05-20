//FormAI DATASET v1.0 Category: Word Count Tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50 // Maximum word length
#define MAX_NUM_WORDS 500 // Maximum number of unique words
#define INPUT_FILE "input.txt" // Input file name
#define OUTPUT_FILE "output.txt" // Output file name

int main() {
    FILE *input_file = fopen(INPUT_FILE, "r"); // Open input file for read
    if (input_file == NULL) {
        printf("Cannot open input file %s!\n", INPUT_FILE);
        return 1;
    }

    FILE *output_file = fopen(OUTPUT_FILE, "w"); // Open output file for write
    if (output_file == NULL) {
        printf("Cannot open output file %s!\n", OUTPUT_FILE);
        return 1;
    }

    int num_words = 0; // Number of words counted
    char words[MAX_NUM_WORDS][MAX_WORD_LEN]; // Array to hold unique words
    int word_count[MAX_NUM_WORDS]; // Array to hold word counts

    char word[MAX_WORD_LEN]; // Buffer to hold each word read from file

    // Read each word from file, count it, and store it in appropriate arrays
    while (fscanf(input_file, "%s", word) != EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]); // Convert word to lowercase
        }

        // Check if word is already counted
        int j;
        int found = 0;
        for (j = 0; j < num_words; j++) {
            if (strcmp(words[j], word) == 0) {
                word_count[j]++;
                found = 1;
                break;
            }
        }

        // If word is not already counted, add it to arrays
        if (!found) {
            strcpy(words[num_words], word);
            word_count[num_words] = 1;
            num_words++;
        }
    }

    // Print and write to file each word and its count
    int k;
    for (k = 0; k < num_words; k++) {
        printf("%s: %d\n", words[k], word_count[k]);
        fprintf(output_file, "%s: %d\n", words[k], word_count[k]);
    }

    fclose(input_file); // Close input file
    fclose(output_file); // Close output file
    return 0;
}