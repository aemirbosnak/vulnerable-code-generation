//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: surprised
// Meow! Welcome to the Cat Language Translator!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cat language dictionary
char *cat_dict[] = {
    "meow", "food",
    "purr", "happy",
    "hiss", "angry",
    "mew", "tired",
    "chirp", "excited",
    "trill", "playful",
    "yowl", "pain"
};

// Translate human language to cat language
char *human_to_cat(char *human_phrase) {
    // Allocate memory for the cat phrase
    char *cat_phrase = malloc(strlen(human_phrase) + 1);

    // Translate each word in the human phrase
    char *word = strtok(human_phrase, " ");
    while (word != NULL) {
        // Search for the word in the cat dictionary
        int i = 0;
        while (i < sizeof(cat_dict) / sizeof(char *)) {
            if (strcmp(word, cat_dict[i]) == 0) {
                // Found the word! Add it to the cat phrase
                strcat(cat_phrase, cat_dict[i + 1]);
                break;
            }
            i += 2;
        }

        // If the word was not found, add it as-is
        if (i == sizeof(cat_dict) / sizeof(char *)) {
            strcat(cat_phrase, word);
        }

        // Add a space to the cat phrase
        strcat(cat_phrase, " ");

        // Get the next word in the human phrase
        word = strtok(NULL, " ");
    }

    // Remove the trailing space from the cat phrase
    cat_phrase[strlen(cat_phrase) - 1] = '\0';

    // Return the cat phrase
    return cat_phrase;
}

// Translate cat language to human language
char *cat_to_human(char *cat_phrase) {
    // Allocate memory for the human phrase
    char *human_phrase = malloc(strlen(cat_phrase) + 1);

    // Translate each word in the cat phrase
    char *word = strtok(cat_phrase, " ");
    while (word != NULL) {
        // Search for the word in the cat dictionary
        int i = 0;
        while (i < sizeof(cat_dict) / sizeof(char *)) {
            if (strcmp(word, cat_dict[i + 1]) == 0) {
                // Found the word! Add it to the human phrase
                strcat(human_phrase, cat_dict[i]);
                break;
            }
            i += 2;
        }

        // If the word was not found, add it as-is
        if (i == sizeof(cat_dict) / sizeof(char *)) {
            strcat(human_phrase, word);
        }

        // Add a space to the human phrase
        strcat(human_phrase, " ");

        // Get the next word in the cat phrase
        word = strtok(NULL, " ");
    }

    // Remove the trailing space from the cat phrase
    human_phrase[strlen(human_phrase) - 1] = '\0';

    // Return the human phrase
    return human_phrase;
}

// Main function
int main() {
    // Get the human phrase from the user
    char human_phrase[100];
    printf("Enter a human phrase: ");
    gets(human_phrase);

    // Translate the human phrase to cat language
    char *cat_phrase = human_to_cat(human_phrase);
    printf("Cat language: %s\n", cat_phrase);

    // Translate the cat phrase back to human language
    char *human_phrase2 = cat_to_human(cat_phrase);
    printf("Human language: %s\n", human_phrase2);

    // Free the allocated memory
    free(cat_phrase);
    free(human_phrase2);

    return 0;
}