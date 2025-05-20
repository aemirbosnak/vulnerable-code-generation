//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function to process the file and count words
void count_words_in_file(const char *filename, WordCount *word_counts, int *total_words, int *unique_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WORD_LENGTH];
    *total_words = 0;
    *unique_words = 0;
    
    while (fscanf(file, "%s", buffer) != EOF) {
        // Convert to lowercase for consistency
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        // Skip non-word characters
        if (!isalpha(buffer[0])) continue;
        
        // Check if word is already counted
        int found = 0;
        for (int i = 0; i < *unique_words; i++) {
            if (strcmp(word_counts[i].word, buffer) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }
        
        // New word encountered
        if (!found) {
            strcpy(word_counts[*unique_words].word, buffer);
            word_counts[*unique_words].count = 1;
            (*unique_words)++;
        }

        (*total_words)++;
    }

    fclose(file);
}

// Function to display word counts
void display_word_counts(const WordCount *word_counts, int unique_words) {
    printf("\nUnique Word Count: %d\n", unique_words);
    printf("Word Counts:\n");
    printf("%-20s %s\n", "Word", "Count");
    printf("------------------------\n");
    for (int i = 0; i < unique_words; i++) {
        printf("%-20s %d\n", word_counts[i].word, word_counts[i].count);
    }
}

// Function to write word counts to a file
void write_word_counts_to_file(const char *output_file, const WordCount *word_counts, int unique_words) {
    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open output file %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Unique Word Count: %d\n", unique_words);
    fprintf(file, "Word Counts:\n");
    fprintf(file, "%-20s %s\n", "Word", "Count");
    fprintf(file, "------------------------\n");
    for (int i = 0; i < unique_words; i++) {
        fprintf(file, "%-20s %d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file> [output_file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = (argc > 2) ? argv[2] : "word_counts.txt";

    WordCount word_counts[MAX_WORDS];
    int total_words = 0;
    int unique_words = 0;

    count_words_in_file(input_file, word_counts, &total_words, &unique_words);
    display_word_counts(word_counts, unique_words);
    write_word_counts_to_file(output_file, word_counts, unique_words);

    printf("Word counts written to %s\n", output_file);
    
    return EXIT_SUCCESS;
}