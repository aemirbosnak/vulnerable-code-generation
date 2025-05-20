//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the cat language dictionary
char *cat_dict[] = {
    "meow", "food",
    "purr", "love",
    "hiss", "angry",
    "scratch", "play",
    "groom", "clean"
};

// Translate a human word to cat language
char *translate_to_cat(char *word) {
    for (int i = 0; i < sizeof(cat_dict) / sizeof(char *); i += 2) {
        if (strcmp(word, cat_dict[i]) == 0) {
            return cat_dict[i + 1];
        }
    }

    // If the word is not found in the dictionary, return the original word
    return word;
}

// Translate a sentence to cat language
char *translate_sentence_to_cat(char *sentence) {
    // Allocate memory for the translated sentence
    char *translated_sentence = malloc(strlen(sentence) + 1);

    // Translate each word in the sentence
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        strcat(translated_sentence, translate_to_cat(word));
        strcat(translated_sentence, " ");
        word = strtok(NULL, " ");
    }

    // Remove the trailing space from the translated sentence
    translated_sentence[strlen(translated_sentence) - 1] = '\0';

    // Return the translated sentence
    return translated_sentence;
}

// Main function
int main() {
    // Get the human sentence from the user
    char sentence[100];
    printf("Enter a sentence to translate to cat language: ");
    gets(sentence);

    // Translate the sentence to cat language
    char *translated_sentence = translate_sentence_to_cat(sentence);

    // Print the translated sentence
    printf("Translated sentence: %s\n", translated_sentence);

    // Free the memory allocated for the translated sentence
    free(translated_sentence);

    return 0;
}