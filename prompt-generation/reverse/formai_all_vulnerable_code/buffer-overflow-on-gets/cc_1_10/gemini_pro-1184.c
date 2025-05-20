//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *phrase;
    char *translation;
} DictionaryEntry;

// Initialize the dictionary with some sample entries.
DictionaryEntry dictionary[] = {
    { "hello", "ola" },
    { "goodbye", "adeus" },
    { "thank you", "obrigado" },
    { "you're welcome", "de nada" },
    { "yes", "sim" },
    { "no", "não" },
    { "I don't understand", "não entendo" },
    { "What is your name?", "Qual é o seu nome?" },
    { "My name is...", "Meu nome é..." },
    { "Nice to meet you", "Prazer em conhecê-lo" }
};

// The number of entries in the dictionary.
const int NUM_ENTRIES = sizeof(dictionary) / sizeof(DictionaryEntry);

// Translate a phrase from English to Alien language.
char *translate(char *phrase) {
    for (int i = 0; i < NUM_ENTRIES; i++) {
        if (strcmp(phrase, dictionary[i].phrase) == 0) {
            return dictionary[i].translation;
        }
    }

    // If the phrase is not found in the dictionary, return the original phrase.
    return phrase;
}

// Main function.
int main() {
    // Get the phrase to be translated from the user.
    char phrase[100];
    printf("Enter a phrase to translate: ");
    gets(phrase);

    // Translate the phrase.
    char *translation = translate(phrase);

    // Print the translation.
    printf("Translation: %s\n", translation);

    return 0;
}