//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
void add_word(WordCount word_counts[], int *word_count, const char *word);
void print_word_counts(const WordCount word_counts[], int word_count);
int compare(const void *a, const void *b);

// Main function
int main() {
    FILE *file;
    WordCount word_counts[MAX_WORDS];
    int word_count = 0;
    char word[MAX_WORD_LENGTH];
    
    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read words from the file
    while (fscanf(file, "%s", word) == 1) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        // Remove punctuation from the word
        char cleaned_word[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isalpha(word[i]) || word[i] == '\'') {
                cleaned_word[j++] = word[i];
            }
        }
        cleaned_word[j] = '\0';
        
        // Add the cleaned word to the count
        add_word(word_counts, &word_count, cleaned_word);
    }

    fclose(file);

    // Sort the word counts
    qsort(word_counts, word_count, sizeof(WordCount), compare);

    // Print word counts
    print_word_counts(word_counts, word_count);

    return EXIT_SUCCESS;
}

// Function to add a word to the word count array
void add_word(WordCount word_counts[], int *word_count, const char *word) {
    for (int i = 0; i < *word_count; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }
    
    // If the word is new, add it to the list
    strcpy(word_counts[*word_count].word, word);
    word_counts[*word_count].count = 1;
    (*word_count)++;
}

// Function to print the word counts
void print_word_counts(const WordCount word_counts[], int word_count) {
    printf("Word Frequency Count:\n");
    printf("----------------------\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    WordCount *word_count_a = (WordCount *)a;
    WordCount *word_count_b = (WordCount *)b;
    return word_count_b->count - word_count_a->count;  // Sort in descending order
}