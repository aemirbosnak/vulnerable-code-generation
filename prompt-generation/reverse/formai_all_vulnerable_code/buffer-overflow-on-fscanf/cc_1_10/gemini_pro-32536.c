//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words to count
#define MAX_WORDS 1000

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the structure of a word count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count;

// Define the comparison function for sorting the word counts
int compare_word_counts(const void *a, const void *b) {
    const word_count *word_count_a = (const word_count *)a;
    const word_count *word_count_b = (const word_count *)b;

    return strcmp(word_count_a->word, word_count_b->word);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a filename
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create an array of word counts
    word_count word_counts[MAX_WORDS];
    int num_words = 0;

    // Read the file and count the words
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if (!found) {
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;

            // Check if the array is full
            if (num_words == MAX_WORDS) {
                printf("Warning: The array of word counts is full. Some words may not have been counted.\n");
                break;
            }
        }
    }

    // Close the file
    fclose(file);

    // Sort the word counts
    qsort(word_counts, num_words, sizeof(word_count), compare_word_counts);

    // Print the word counts
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return EXIT_SUCCESS;
}