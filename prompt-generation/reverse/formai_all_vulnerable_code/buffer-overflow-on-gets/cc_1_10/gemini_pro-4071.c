//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
    "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "_", "=", "+",
    ",", ".", "/", ";", ":", "'", "\"", "\\", "|", "[", "]", "{", "}",
    " ", "\n", "\t"
};

// Define the number of words in the alien language dictionary
#define NUM_WORDS (sizeof(alien_dict) / sizeof(char *))

// Define the maximum length of an alien word
#define MAX_WORD_LENGTH 100

// Define the maximum length of an alien sentence
#define MAX_SENTENCE_LENGTH 1000

// Translate an alien word from the dictionary
char *translate_word(char *word) {
    // Allocate memory for the translated word
    char *translated_word = malloc(MAX_WORD_LENGTH);

    // Translate the word one character at a time
    int i;
    for (i = 0; i < strlen(word); i++) {
        // Find the index of the character in the alien language dictionary
        int index = 0;
        while (strcmp(alien_dict[index], word[i]) != 0) {
            index++;
        }

        // Append the translated character to the translated word
        translated_word[i] = alien_dict[(index + 1) % NUM_WORDS];
    }

    // Return the translated word
    return translated_word;
}

// Translate an alien sentence from the dictionary
char *translate_sentence(char *sentence) {
    // Allocate memory for the translated sentence
    char *translated_sentence = malloc(MAX_SENTENCE_LENGTH);

    // Translate the sentence one word at a time
    int i;
    char *word;
    for (i = 0, word = strtok(sentence, " "); word != NULL; word = strtok(NULL, " ")) {
        // Translate the word
        char *translated_word = translate_word(word);

        // Append the translated word to the translated sentence
        strcat(translated_sentence, translated_word);

        // Free the memory allocated for the translated word
        free(translated_word);
    }

    // Return the translated sentence
    return translated_sentence;
}

// Main function
int main() {
    // Get the alien sentence from the user
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter an alien sentence: ");
    gets(sentence);

    // Translate the alien sentence
    char *translated_sentence = translate_sentence(sentence);

    // Print the translated sentence
    printf("Translated sentence: %s\n", translated_sentence);

    // Free the memory allocated for the translated sentence
    free(translated_sentence);

    return 0;
}