//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"
#define TEXT_FILE "input.txt"
#define MAX_DICTIONARY_WORDS 1000

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to read the dictionary into an array
int load_dictionary(char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file.\n");
        return 0;
    }

    int count = 0;
    while (count < MAX_DICTIONARY_WORDS && fscanf(file, "%s", dictionary[count]) != EOF) {
        to_lowercase(dictionary[count]);
        count++;
    }
    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(char *word, char dictionary[][MAX_WORD_LENGTH], int dictionary_size) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to extract words from the text and check their spelling
void spell_check_text(char dictionary[][MAX_WORD_LENGTH], int dictionary_size) {
    FILE *file = fopen(TEXT_FILE, "r");
    if (!file) {
        fprintf(stderr, "Could not open text file.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    int line_number = 1;
    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        if (!is_word_in_dictionary(word, dictionary, dictionary_size)) {
            printf("Spelling error in line %d: %s\n", line_number, word);
        }
        // Check for line breaks
        if (strchr(word, '\n')) {
            line_number++;
        }
    }
    fclose(file);
}

int main() {
    char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
    int dictionary_size = load_dictionary(dictionary);

    printf("Loaded %d words into the dictionary.\n", dictionary_size);

    if (dictionary_size > 0) {
        spell_check_text(dictionary, dictionary_size);
    } else {
        printf("No words found in dictionary.\n");
    }

    return 0;
}