//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to count words, sentences, and characters in a text
void process_text(FILE *file, int *word_count, int *sentence_count, int *char_count) {
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        *char_count += strlen(line);
        
        // Count words by space and punctuation
        for (int i = 0; line[i] != '\0'; i++) {
            if (isspace(line[i]) || ispunct(line[i])) {
                if (i > 0 && !isspace(line[i - 1]) && !ispunct(line[i - 1])) {
                    (*word_count)++;
                }
            }
            if (line[i] == '.' || line[i] == '!' || line[i] == '?') {
                (*sentence_count)++;
            }
        }

        // If the last segment of the line is a word
        if (line[strlen(line) - 1] != ' ' && line[strlen(line) - 1] != '\n') {
            (*word_count)++;
        }
    }
}

// Function to display statistics
void display_statistics(int word_count, int sentence_count, int char_count) {
    printf("\n--- Text Processing Statistics ---\n");
    printf("Total words: %d\n", word_count);
    printf("Total sentences: %d\n", sentence_count);
    printf("Total characters: %d\n", char_count);
    
    double average_words_per_sentence = (sentence_count > 0) ? (double)word_count / sentence_count : 0.0;
    printf("Average words per sentence: %.2f\n", average_words_per_sentence);
}

int main(int argc, char *argv[]) {
    // Check for input file
    if (argc < 2) {
        fprintf(stderr, "Error: Please provide a text file to process.\n");
        return EXIT_FAILURE;
    }
    
    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s.\n", argv[1]);
        return EXIT_FAILURE;
    }

    int word_count = 0;
    int sentence_count = 0;
    int char_count = 0;

    // Process the text in the file
    process_text(file, &word_count, &sentence_count, &char_count);

    // Close the file
    fclose(file);
    
    // Display the results
    display_statistics(word_count, sentence_count, char_count);

    return EXIT_SUCCESS;
}