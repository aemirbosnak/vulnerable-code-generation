//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
struct alien_dict_entry {
    char alien_word[10];
    char english_word[10];
};

struct alien_dict_entry alien_dict[] = {
    {"a", "apple"},
    {"b", "banana"},
    {"c", "cat"},
    {"d", "dog"},
    {"e", "elephant"},
    {"f", "fish"},
    {"g", "goat"},
    {"h", "horse"},
    {"i", "ice cream"},
    {"j", "juice"},
    {"k", "kite"},
    {"l", "lion"},
    {"m", "monkey"},
    {"n", "nut"},
    {"o", "orange"},
    {"p", "pineapple"},
    {"q", "queen"},
    {"r", "rabbit"},
    {"s", "snake"},
    {"t", "tiger"},
    {"u", "umbrella"},
    {"v", "violin"},
    {"w", "watermelon"},
    {"x", "x-ray"},
    {"y", "yacht"},
    {"z", "zebra"}
};

// Get the size of the alien dictionary
int alien_dict_size = sizeof(alien_dict) / sizeof(struct alien_dict_entry);

// Translate an alien word to English
char *translate_alien_word(char *alien_word) {
    // Iterate over the alien dictionary
    for (int i = 0; i < alien_dict_size; i++) {
        // Check if the alien word matches the current dictionary entry
        if (strcmp(alien_dict[i].alien_word, alien_word) == 0) {
            // Return the corresponding English word
            return alien_dict[i].english_word;
        }
    }

    // If the alien word is not found in the dictionary, return NULL
    return NULL;
}

// Translate an English word to alien
char *translate_english_word(char *english_word) {
    // Iterate over the alien dictionary
    for (int i = 0; i < alien_dict_size; i++) {
        // Check if the English word matches the current dictionary entry
        if (strcmp(alien_dict[i].english_word, english_word) == 0) {
            // Return the corresponding alien word
            return alien_dict[i].alien_word;
        }
    }

    // If the English word is not found in the dictionary, return NULL
    return NULL;
}

// Main function
int main() {
    // Get the alien word from the user
    char alien_word[10];
    printf("Enter the alien word: ");
    scanf("%s", alien_word);

    // Translate the alien word to English
    char *english_word = translate_alien_word(alien_word);

    // Print the English translation
    if (english_word != NULL) {
        printf("The English translation is: %s\n", english_word);
    } else {
        printf("The alien word is not in the dictionary.\n");
    }

    // Get the English word from the user
    char english_word2[10];
    printf("Enter the English word: ");
    scanf("%s", english_word2);

    // Translate the English word to alien
    char *alien_word2 = translate_english_word(english_word2);

    // Print the alien translation
    if (alien_word2 != NULL) {
        printf("The alien translation is: %s\n", alien_word2);
    } else {
        printf("The English word is not in the dictionary.\n");
    }

    return 0;
}