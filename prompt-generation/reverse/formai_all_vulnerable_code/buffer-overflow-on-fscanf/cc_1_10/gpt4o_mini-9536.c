//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function declarations
int add_word(WordFrequency *freqs, int *num_words, const char *word);
void to_lowercase(char *str);
void strip_newline(char *str);
void print_word_frequencies(WordFrequency *freqs, int num_words);
void free_memory(WordFrequency *freqs);

int main() {
    FILE *file;
    char filename[100];
    char word[MAX_WORD_LENGTH];
    WordFrequency freqs[MAX_WORDS];
    int num_words = 0;

    printf("Enter the filename to read from: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return 1;
    }

    // Read words from the file
    while (fscanf(file, "%s", word) == 1) {
        strip_newline(word);  // Strip newlines if present
        to_lowercase(word);   // Convert to lowercase
        add_word(freqs, &num_words, word);
    }

    fclose(file);

    // Print the word frequencies
    print_word_frequencies(freqs, num_words);
    free_memory(freqs);

    return 0;
}

// Function to add a word to the frequency list
int add_word(WordFrequency *freqs, int *num_words, const char *word) {
    for (int i = 0; i < *num_words; i++) {
        if (strcmp(freqs[i].word, word) == 0) {
            freqs[i].count++;
            return *num_words; // No need to add a new word
        }
    }
    
    // Add a new word
    strcpy(freqs[*num_words].word, word);
    freqs[*num_words].count = 1;
    (*num_words)++;
    
    return *num_words;
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to strip newline characters from a string
void strip_newline(char *str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

// Function to print the array of word frequencies
void print_word_frequencies(WordFrequency *freqs, int num_words) {
    printf("\nWord Frequency Count:\n");
    printf("----------------------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", freqs[i].word, freqs[i].count);
    }
}

// Function to free dynamically allocated memory (if any)
void free_memory(WordFrequency *freqs) {
    // In this case, we don't have dynamically allocated memory to free,
    // but if we did, we would do it here.
}