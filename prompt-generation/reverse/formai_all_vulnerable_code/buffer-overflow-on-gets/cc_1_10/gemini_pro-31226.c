//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alien_word {
    char* alien_word;
    char* english_translation;
};

// Initialize the dictionary with a few words
struct alien_word dictionary[] = {
    {"akla", "hello"},
    {"bork", "goodbye"},
    {"chit", "thank you"},
    {"chirp", "you're welcome"},
    {"drek", "please"},
    {"eek", "excuse me"},
    {"flarp", "I don't understand"},
    {"gloop", "I'm sorry"},
    {"hork", "help me"},
    {"jiffy", "quickly"},
    {"klonk", "slowly"},
    {"lurk", "carefully"},
    {"moop", "happily"},
    {"nork", "sadly"},
    {"oogle", "angrily"},
    {"plop", "excitedly"},
    {"qwirk", "nervously"},
    {"rark", "tiredly"},
    {"snik", "sleepily"},
    {"twerp", "awake"},
    {"urp", "hungry"},
    {"vark", "thirsty"},
    {"wibble", "cold"},
    {"xarp", "hot"},
    {"yark", "light"},
    {"zork", "dark"}
};

// Function to translate an alien word to English
char* translate_alien_word(char* alien_word) {
    // Iterate over the dictionary to find a matching alien word
    for (int i = 0; i < sizeof(dictionary) / sizeof(struct alien_word); i++) {
        if (strcmp(dictionary[i].alien_word, alien_word) == 0) {
            // Return the English translation of the alien word
            return dictionary[i].english_translation;
        }
    }

    // If no matching alien word is found, return an error message
    return "Unknown alien word";
}

// Function to translate a sentence from Alien to English
void translate_alien_sentence(char* alien_sentence) {
    // Split the sentence into words
    char* words[100];
    char* word = strtok(alien_sentence, " ");
    int i = 0;
    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }

    // Translate each word in the sentence
    for (int j = 0; j < i; j++) {
        printf("%s ", translate_alien_word(words[j]));
    }

    // Print a newline at the end of the sentence
    printf("\n");
}

int main() {
    // Get the alien sentence from the user
    char alien_sentence[100];
    printf("Enter an alien sentence: ");
    gets(alien_sentence);

    // Translate the sentence and print the result
    translate_alien_sentence(alien_sentence);

    return 0;
}