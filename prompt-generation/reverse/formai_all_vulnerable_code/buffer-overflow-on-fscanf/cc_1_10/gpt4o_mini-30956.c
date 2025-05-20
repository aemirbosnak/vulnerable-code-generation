//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 10000

// Function to load words from a dictionary file into an array
int load_dictionary(const char *filename, char dictionary[MAX_WORDS][MAX_WORD_LEN]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF && count < MAX_WORDS) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to compare a word with a dictionary to check for spelling
int is_word_in_dictionary(const char *word, char dictionary[MAX_WORDS][MAX_WORD_LEN], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to suggest corrections by finding similar words based on length
void suggest_corrections(const char *word, char dictionary[MAX_WORDS][MAX_WORD_LEN], int dict_size) {
    printf("Suggestions for '%s':\n", word);
    for (int i = 0; i < dict_size; i++) {
        if (strlen(word) == strlen(dictionary[i])) {
            printf(" - %s\n", dictionary[i]);
        }
    }
}

// Function to perform spell checking on an input text
void spell_check(const char *input_text, char dictionary[MAX_WORDS][MAX_WORD_LEN], int dict_size) {
    // Buffer to hold individual words
    char word[MAX_WORD_LEN];
    const char *ptr = input_text;
    int index = 0;

    printf("Checking the following text:\n%s\n\n", input_text);
    printf("Misspelled words:\n");

    while (*ptr) {
        if (isalnum(*ptr)) { // Check if the character is alphanumeric
            word[index++] = *ptr;
        } else {
            if (index > 0) { // We have a complete word
                word[index] = '\0'; // Null-terminate the string
                if (!is_word_in_dictionary(word, dictionary, dict_size)) {
                    printf(" - %s\n", word);
                    suggest_corrections(word, dictionary, dict_size);
                }
                index = 0; // Reset for the next word
            }
        }
        ptr++;
    }

    // Check for the last word if there's no punctuation at the end
    if (index > 0) {
        word[index] = '\0';
        if (!is_word_in_dictionary(word, dictionary, dict_size)) {
            printf(" - %s\n", word);
            suggest_corrections(word, dictionary, dict_size);
        }
    }
}

int main() {
    char dictionary[MAX_WORDS][MAX_WORD_LEN];
    int dict_size;

    // Load the dictionary
    dict_size = load_dictionary("dictionary.txt", dictionary);
    if (dict_size == -1) {
        exit(EXIT_FAILURE);
    }

    // Sample input text for spell checking
    const char *input_text = "Ths is a smple text with speling erors to teest the spell chcker.";

    // Perform spell checking
    spell_check(input_text, dictionary, dict_size);

    return 0;
}