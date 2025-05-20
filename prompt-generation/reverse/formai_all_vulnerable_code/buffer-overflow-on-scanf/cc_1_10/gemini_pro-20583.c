//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
char *alien_dict[] = {
    "Zog", "Slurp", "Burp", "Gleep", "Glorf", "Blorf", "Quark", "Warp", "Spock", "Kirk"
};

// Earth language dictionary
char *earth_dict[] = {
    "Hello", "Goodbye", "Thank you", "Yes", "No", "Please", "Sorry", "Excuse me", "I don't understand", "Do you speak English?"
};

// Function to translate from Alien to Earth
char *alien_to_earth(char *alien_word) {
    for (int i = 0; i < sizeof(alien_dict) / sizeof(char *); i++) {
        if (strcmp(alien_word, alien_dict[i]) == 0) {
            return earth_dict[i];
        }
    }
    return NULL;
}

// Function to translate from Earth to Alien
char *earth_to_alien(char *earth_word) {
    for (int i = 0; i < sizeof(earth_dict) / sizeof(char *); i++) {
        if (strcmp(earth_word, earth_dict[i]) == 0) {
            return alien_dict[i];
        }
    }
    return NULL;
}

int main() {
    // Get the input from the user
    char input[100];
    printf("Enter an Alien or Earth word: ");
    scanf("%s", input);

    // Translate the word
    char *translation;
    if (strchr(input, ' ') != NULL) {
        // It's a sentence, so translate each word
        char *words[100];
        int num_words = 0;
        char *word = strtok(input, " ");
        while (word != NULL) {
            words[num_words++] = word;
            word = strtok(NULL, " ");
        }
        char *translated_sentence[100];
        for (int i = 0; i < num_words; i++) {
            translation = alien_to_earth(words[i]);
            if (translation == NULL) {
                translation = earth_to_alien(words[i]);
            }
            translated_sentence[i] = translation;
        }
        printf("Translation: ");
        for (int i = 0; i < num_words; i++) {
            printf("%s ", translated_sentence[i]);
        }
        printf("\n");
    } else {
        // It's a single word, so translate it
        translation = alien_to_earth(input);
        if (translation == NULL) {
            translation = earth_to_alien(input);
        }
        printf("Translation: %s\n", translation);
    }

    return 0;
}