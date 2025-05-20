//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000
#define INPUT_BUFFER 1024

// Function prototypes
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dict_size);
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size);
void to_lowercase(char *word);
void spell_check(const char *filename, char dictionary[][MAX_WORD_LENGTH], int dict_size);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <input_text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = 0;
    load_dictionary(argv[1], dictionary, &dict_size);
    spell_check(argv[2], dictionary, dict_size);

    return 0;
}

// Load dictionary words from a file
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dict_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(1);
    }

    while (fscanf(file, "%s", dictionary[*dict_size]) != EOF) {
        to_lowercase(dictionary[*dict_size]);
        (*dict_size)++;
        if (*dict_size >= DICTIONARY_SIZE) {
            printf("Dictionary size limit reached\n");
            break;
        }
    }
    fclose(file);
}

// Convert a word to lowercase
void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Check if a word exists in the dictionary
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Perform spell check on the input file
void spell_check(const char *filename, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open input text file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int total_words = 0;
    int misspelled_words = 0;

    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        total_words++;

        // Remove punctuation from the word
        char cleaned_word[MAX_WORD_LENGTH];
        int idx = 0;
        for (int i = 0; word[i]; i++) {
            if (isalpha(word[i])) {
                cleaned_word[idx++] = word[i];
            }
        }
        cleaned_word[idx] = '\0';

        // Check if the cleaned word is in the dictionary
        if (!is_word_in_dictionary(cleaned_word, dictionary, dict_size)) {
            printf("Misspelled: %s\n", cleaned_word);
            misspelled_words++;
        }
    }

    fclose(file);
    
    // Print statistics
    printf("Total words checked: %d\n", total_words);
    printf("Total misspelled words: %d\n", misspelled_words);
    printf("Percentage of misspelled words: %.2f%%\n", 
           (total_words > 0) ? (100.0 * misspelled_words / total_words) : 0.0);
}