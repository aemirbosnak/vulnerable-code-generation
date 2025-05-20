//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 256
#define DICTIONARY_SIZE 10

// Structure for the dictionary entries
typedef struct {
    char* english;
    char* alien;
} DictionaryEntry;

// Initialize the dictionary
DictionaryEntry dictionary[DICTIONARY_SIZE] = {
    {"hello", "glorp"},
    {"world", "zibbz"},
    {"how", "flib"},
    {"are", "bloop"},
    {"you", "snorp"},
    {"goodbye", "womp"},
    {"friend", "plang"},
    {"yes", "gurg"},
    {"no", "blarf"},
    {"please", "skree"}
};

// Function to translate a word into the alien language
char* translate_word(const char* word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcasecmp(word, dictionary[i].english) == 0) {
            return dictionary[i].alien; // Return alien translation
        }
    }
    return NULL; // No translation found
}

// Function to translate a full line of text
void translate_line(const char* line, char* translated_line) {
    char word[MAX_WORD_LENGTH];
    int index = 0;
    int translated_index = 0;

    while (sscanf(line + index, "%s", word) > 0) {
        char* alien_word = translate_word(word);
        if (alien_word != NULL) {
            strcpy(translated_line + translated_index, alien_word);
        } else {
            strcpy(translated_line + translated_index, word); // Keep original word if no translation
        }
        translated_index += strlen(alien_word);
        translated_line[translated_index++] = ' '; // Add space
        index += strlen(word) + 1; // Move to the next word
    }
    translated_line[translated_index - 1] = '\0'; // Remove trailing space
}

// Main function to execute the translator
int main() {
    char input[MAX_LINE_LENGTH];
    char translated[MAX_LINE_LENGTH];
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Type a line in English to translate into Alien Language:\n");

    while (1) {
        printf("You: ");
        if (!fgets(input, sizeof(input), stdin)) {
            break; // Exit on Ctrl+D
        }

        // Remove newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // Exit condition
        if (strcasecmp(input, "exit") == 0) {
            printf("Exiting translator. Take care!\n");
            break;
        }

        translate_line(input, translated);
        printf("Alien: %s\n", translated);
    }

    return 0;
}