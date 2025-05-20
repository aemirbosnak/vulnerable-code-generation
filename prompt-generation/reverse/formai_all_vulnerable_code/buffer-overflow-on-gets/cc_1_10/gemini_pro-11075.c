//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
struct alien_dict {
    char alien_word[10];
    char english_word[10];
};

// Create an array of alien language words and their English translations
struct alien_dict dict[] = {
    {"ploog", "hello"},
    {"floog", "goodbye"},
    {"slarti", "thank you"},
    {"blurg", "please"},
    {"flarp", "help me"},
    {"zorg", "I don't understand"},
    {"blippy", "yes"},
    {"floppy", "no"},
    {"grunf", "maybe"},
    {"snorf", "I love you"},
};

// Get the number of words in the dictionary
int num_words = sizeof(dict) / sizeof(struct alien_dict);

// Translate an alien word into English
char *translate_alien_word(char *alien_word) {
    // Iterate over the dictionary to find the matching alien word
    for (int i = 0; i < num_words; i++) {
        if (strcmp(alien_word, dict[i].alien_word) == 0) {
            // Return the English translation of the alien word
            return dict[i].english_word;
        }
    }

    // If the alien word is not found in the dictionary, return NULL
    return NULL;
}

// Translate an English word into an alien word
char *translate_english_word(char *english_word) {
    // Iterate over the dictionary to find the matching English word
    for (int i = 0; i < num_words; i++) {
        if (strcmp(english_word, dict[i].english_word) == 0) {
            // Return the alien word that corresponds to the English word
            return dict[i].alien_word;
        }
    }

    // If the English word is not found in the dictionary, return NULL
    return NULL;
}

// Get a sentence from the user and translate it into English
char *get_and_translate_sentence() {
    // Get a sentence from the user
    char sentence[100];
    printf("Enter a sentence in Alien language: ");
    gets(sentence);

    // Tokenize the sentence into individual words
    char *words[100];
    int num_words = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Translate each word in the sentence
    char *translated_sentence[100];
    for (int i = 0; i < num_words; i++) {
        translated_sentence[i] = translate_alien_word(words[i]);
    }

    // Join the translated words into a single sentence
    char *result = malloc(100);
    strcpy(result, translated_sentence[0]);
    for (int i = 1; i < num_words; i++) {
        strcat(result, " ");
        strcat(result, translated_sentence[i]);
    }

    // Return the translated sentence
    return result;
}

// Get a sentence from the user and translate it into Alien language
char *get_and_translate_sentence_to_alien() {
    // Get a sentence from the user
    char sentence[100];
    printf("Enter a sentence in English: ");
    gets(sentence);

    // Tokenize the sentence into individual words
    char *words[100];
    int num_words = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Translate each word in the sentence
    char *translated_sentence[100];
    for (int i = 0; i < num_words; i++) {
        translated_sentence[i] = translate_english_word(words[i]);
    }

    // Join the translated words into a single sentence
    char *result = malloc(100);
    strcpy(result, translated_sentence[0]);
    for (int i = 1; i < num_words; i++) {
        strcat(result, " ");
        strcat(result, translated_sentence[i]);
    }

    // Return the translated sentence
    return result;
}

// Main function
int main() {
    // Get a sentence from the user and translate it into English
    char *translated_sentence = get_and_translate_sentence();

    // Print the translated sentence
    printf("English translation: %s\n", translated_sentence);

    // Get a sentence from the user and translate it into Alien language
    translated_sentence = get_and_translate_sentence_to_alien();

    // Print the translated sentence
    printf("Alien language translation: %s\n", translated_sentence);

    return 0;
}