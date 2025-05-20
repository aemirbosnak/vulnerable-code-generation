//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

struct {
    char *english;
    char *alien;
} dictionary[] = {
    {"hello", "zog"},
    {"world", "ploink"},
    {"how", "flib"},
    {"are", "glorb"},
    {"you", "snarf"},
    {"doing", "splorf"},
    {"today", "flargle"},
    {"?", "bleep"},
    {"!", "bloop"}
};

int num_words = sizeof(dictionary) / sizeof(dictionary[0]);

void translate_sentence(char *sentence) {
    char *token;
    char *alien_sentence = malloc(strlen(sentence) * 2); // Allocate memory for the translated sentence
    alien_sentence[0] = '\0'; // Initialize the string to an empty string

    token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) { // Compare the token to each word in the dictionary
                strcat(alien_sentence, dictionary[i].alien); // Append the alien word to the translated sentence
                break;
            }
        }
        if (i == num_words) { // If the word is not found in the dictionary, leave it as is
            strcat(alien_sentence, " ");
            strcat(alien_sentence, token);
        }
        token = strtok(NULL, " "); // Move to the next token
    }

    printf("%s\n", alien_sentence); // Print the translated sentence
    free(alien_sentence); // Free the memory allocated for the translated sentence
}

int main() {
    char sentence[100];

    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin); // Read a sentence from the user

    translate_sentence(sentence); // Translate the sentence

    return 0;
}