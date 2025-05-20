//Code Llama-13B DATASET v1.0 Category: Alien Language Translator ; Style: surprised
// Alien Language Translator
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store a word and its translation
typedef struct {
    char word[20];
    char translation[20];
} word_translation;

// Function to translate a word from the alien language to English
char* translate(char* word) {
    // Define the words and their translations
    word_translation words[5] = {
        {"Glarg", "Hello"},
        {"Zlorg", "Goodbye"},
        {"Bleep", "Yes"},
        {"Bloop", "No"},
        {"Splorg", "Excuse me"}
    };

    // Loop through the words and compare with the input word
    for (int i = 0; i < 5; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return words[i].translation;
        }
    }

    // If the word is not found, return NULL
    return NULL;
}

// Main function
int main() {
    // Prompt the user to enter a word
    printf("Enter a word: ");
    char word[20];
    scanf("%s", word);

    // Translate the word and print the result
    char* translation = translate(word);
    if (translation != NULL) {
        printf("Translation: %s\n", translation);
    } else {
        printf("Word not found\n");
    }

    return 0;
}