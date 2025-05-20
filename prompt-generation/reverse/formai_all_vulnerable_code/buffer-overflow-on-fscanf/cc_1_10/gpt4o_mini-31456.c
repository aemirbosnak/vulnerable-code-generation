//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_WORDS 10000

// Structure to hold word information
typedef struct {
    char *word;
    int count;
} WordCount;

// Function prototypes
int is_word_character(char c);
WordCount* process_file(const char *filename, int *total_words);
int compare_words(const void *a, const void *b);
void print_word_count(WordCount *words, int unique_words);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    int total_words = 0;

    // Get the filename from the user
    printf("Enter the filename to process: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading filename.\n");
        return EXIT_FAILURE;
    }

    // Remove the trailing newline character if present
    filename[strcspn(filename, "\n")] = 0;

    // Process the file and get word counts
    WordCount *word_counts = process_file(filename, &total_words);
    if (word_counts == NULL) {
        fprintf(stderr, "Error processing file.\n");
        return EXIT_FAILURE;
    }

    // Sort the words based on their counts
    qsort(word_counts, total_words, sizeof(WordCount), compare_words);

    // Print the results
    print_word_count(word_counts, total_words);

    // Free allocated memory
    for (int i = 0; i < total_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    return EXIT_SUCCESS;
}

// Function to check if a character is part of a word
int is_word_character(char c) {
    return isalnum(c) || c == '\'';
}

// Function to process the file
WordCount* process_file(const char *filename, int *total_words) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return NULL;
    }

    WordCount *word_counts = malloc(MAX_WORDS * sizeof(WordCount));
    if (!word_counts) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    char buffer[256];
    int word_index = 0;

    while (fscanf(file, "%s", buffer) != EOF) {
        int length = strlen(buffer);
        char word[length + 1];
        int j = 0;

        // Filter out non-word characters
        for (int i = 0; i < length; i++) {
            if (is_word_character(buffer[i])) {
                word[j++] = tolower(buffer[i]); // convert to lower case
            }
        }
        word[j] = '\0';

        // Check if the word is empty after filtering
        if (j == 0) {
            continue;
        }

        // Check if the word already exists
        int found = 0;
        for (int i = 0; i < word_index; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }

        // If not found, add the word to the list
        if (!found) {
            if (word_index >= MAX_WORDS) {
                fprintf(stderr, "Too many unique words. Limit reached at %d.\n", MAX_WORDS);
                break;
            }
            word_counts[word_index].word = strdup(word);
            word_counts[word_index].count = 1;
            word_index++;
        }
    }

    fclose(file);
    *total_words = word_index;
    return word_counts;
}

// Comparison function for qsort
int compare_words(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return word2->count - word1->count; // Descending order
}

// Function to print the word counts
void print_word_count(WordCount *words, int unique_words) {
    printf("\nWord Count Summary:\n");
    printf("--------------------\n");
    for (int i = 0; i < unique_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
    printf("--------------------\n");
}