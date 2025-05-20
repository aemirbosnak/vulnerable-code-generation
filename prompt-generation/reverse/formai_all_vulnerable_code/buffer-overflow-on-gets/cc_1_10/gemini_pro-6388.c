//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the number of words in the dictionary
#define NUM_WORDS 100

// Define the dictionary
char *dictionary[NUM_WORDS] = {
    "meow", "purr", "hiss", "scratch", "bite", "play", "sleep", "eat", "drink", "love"
};

// Define the function to translate a word from English to Cat
char *translate_word(char *word) {
    // Loop through the dictionary
    for (int i = 0; i < NUM_WORDS; i++) {
        // If the word is found in the dictionary, return the translation
        if (strcmp(word, dictionary[i]) == 0) {
            return dictionary[i];
        }
    }

    // If the word is not found in the dictionary, return the original word
    return word;
}

// Define the function to translate a sentence from English to Cat
char *translate_sentence(char *sentence) {
    // Allocate memory for the translated sentence
    char *translated_sentence = malloc(strlen(sentence) + 1);

    // Loop through the words in the sentence
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        // Translate the word
        char *translated_word = translate_word(word);

        // Append the translated word to the translated sentence
        strcat(translated_sentence, translated_word);

        // Add a space to the translated sentence
        strcat(translated_sentence, " ");

        // Get the next word
        word = strtok(NULL, " ");
    }

    // Return the translated sentence
    return translated_sentence;
}

// Define the main function
int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence to translate: ");
    gets(sentence);

    // Translate the sentence
    char *translated_sentence = translate_sentence(sentence);

    // Print the translated sentence
    printf("Translated sentence: %s\n", translated_sentence);

    // Free the memory allocated for the translated sentence
    free(translated_sentence);

    return 0;
}