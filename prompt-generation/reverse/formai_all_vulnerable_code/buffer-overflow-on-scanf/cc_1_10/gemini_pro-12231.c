//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
struct alien_dictionary {
    char alien_word[20];
    char english_translation[20];
};

// Create an array of alien words and their English translations
struct alien_dictionary dictionary[] = {
    {"kroog", "hello"},
    {"glaak", "goodbye"},
    {"kree", "friend"},
    {"graak", "enemy"},
    {"krii", "ship"},
    {"groog", "planet"},
    {"kvaak", "star"},
    {"kvaak graak", "black star"},
    {"kvaak kree", "friendly star"},
    {"kvaak glaak", "goodbye star"}
};

// Get the number of words in the dictionary
int dictionary_size = sizeof(dictionary) / sizeof(dictionary[0]);

// Translate an Alien word to English
char* translate_alien_word(char *alien_word) {
    // Iterate over the dictionary to find the matching Alien word
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(dictionary[i].alien_word, alien_word) == 0) {
            // Return the English translation
            return dictionary[i].english_translation;
        }
    }

    // If the Alien word is not found in the dictionary, return NULL
    return NULL;
}

// Translate a sentence from Alien to English
char* translate_alien_sentence(char *alien_sentence) {
    // Split the Alien sentence into words
    char *words[100];
    int num_words = 0;
    char *token = strtok(alien_sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Translate each word in the sentence
    char *english_words[100];
    for (int i = 0; i < num_words; i++) {
        english_words[i] = translate_alien_word(words[i]);
        if (english_words[i] == NULL) {
            // If a word is not found in the dictionary, return NULL
            return NULL;
        }
    }

    // Concatenate the translated words into a sentence
    char *english_sentence = malloc(1000);
    strcpy(english_sentence, english_words[0]);
    for (int i = 1; i < num_words; i++) {
        strcat(english_sentence, " ");
        strcat(english_sentence, english_words[i]);
    }

    // Return the translated sentence
    return english_sentence;
}

// Main function
int main() {
    // Get the Alien sentence from the user
    char alien_sentence[1000];
    printf("Enter an Alien sentence: ");
    scanf("%s", alien_sentence);

    // Translate the Alien sentence to English
    char *english_sentence = translate_alien_sentence(alien_sentence);

    // Print the translated sentence
    if (english_sentence == NULL) {
        printf("Error: One or more words in the Alien sentence are not found in the dictionary.\n");
    } else {
        printf("English translation: %s\n", english_sentence);
    }

    return 0;
}