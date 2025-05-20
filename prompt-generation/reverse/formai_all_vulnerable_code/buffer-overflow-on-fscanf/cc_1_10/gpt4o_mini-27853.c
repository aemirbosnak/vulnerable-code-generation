//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define DICTIONARY_SIZE 5000

// Structure to hold a dictionary
typedef struct {
    char words[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int count;
} Dictionary;

// Function to load dictionary from a file
int load_dictionary(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open dictionary file");
        return -1;
    }

    dict->count = 0;
    while (fscanf(file, "%s", dict->words[dict->count]) != EOF && dict->count < DICTIONARY_SIZE) {
        dict->count++;
    }
    
    fclose(file);
    return 0;
}

// Function to check the spelling of a word
int check_spelling(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->count; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to extract words from a text buffer
int extract_words(char *text, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    int count = 0;
    char *token = strtok(text, " \n\t.,;:!?()[]");

    while (token != NULL && count < MAX_WORDS) {
        strncpy(words[count], token, MAX_WORD_LENGTH);
        words[count][MAX_WORD_LENGTH - 1] = '\0'; // Ensure null termination
        count++;
        token = strtok(NULL, " \n\t.,;:!?()[]");
    }

    return count;
}

// Function to perform spell checking
void spell_check(Dictionary *dict, const char *text) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = extract_words(text, words);
    
    printf("Spell Check Results:\n");
    for (int i = 0; i < word_count; i++) {
        if (!check_spelling(dict, words[i])) {
            printf("Misspelled: %s\n", words[i]);
        }
    }
}

int main() {
    Dictionary dict;
    const char *dictionary_file = "dictionary.txt"; // Path to the dictionary file

    // Load the dictionary
    if (load_dictionary(&dict, dictionary_file) != 0) {
        return EXIT_FAILURE;
    }

    // Sample text for spell checking
    char text[] = "This is a simple texxt with some speling errors. Enjoy programming!";
    
    spell_check(&dict, text);
    
    return EXIT_SUCCESS;
}