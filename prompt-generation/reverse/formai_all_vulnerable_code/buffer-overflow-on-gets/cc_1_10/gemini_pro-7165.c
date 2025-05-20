//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language dictionary
char *cat_dict[] = {
    "meow", "food",
    "purr", "water",
    "hiss", "sleep",
    "chirp", "play",
    "growl", "angry",
    "mew", "kitten",
    "mrrow", "mother cat",
    "tom", "father cat",
    "kitty", "baby cat",
    "pussy", "female cat",
    "tabby", "striped cat",
    "calico", "multicolored cat",
    "tuxedo", "black and white cat",
    "siamese", "blue-eyed cat",
    "persian", "long-haired cat",
    "ragdoll", "floppy cat",
    "sphynx", "hairless cat",
    "maine coon", "large cat"
};

// Translate a human word to Cat Language
char *translate_to_cat(char *word) {
    int i;

    for (i = 0; i < sizeof(cat_dict) / sizeof(char *); i += 2) {
        if (strcmp(word, cat_dict[i]) == 0) {
            return cat_dict[i + 1];
        }
    }

    return NULL;
}

// Translate a Cat Language word to human language
char *translate_to_human(char *word) {
    int i;

    for (i = 0; i < sizeof(cat_dict) / sizeof(char *); i += 2) {
        if (strcmp(word, cat_dict[i + 1]) == 0) {
            return cat_dict[i];
        }
    }

    return NULL;
}

// Convert a string to lowercase
char *to_lowercase(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    return str;
}

// Main function
int main() {
    char input[100];
    char *translation;

    printf("Enter a word or phrase to translate (or 'quit' to exit): ");
    gets(input);

    while (strcmp(input, "quit") != 0) {
        translation = translate_to_cat(to_lowercase(input));

        if (translation != NULL) {
            printf("Cat Language: %s\n", translation);
        } else {
            translation = translate_to_human(to_lowercase(input));

            if (translation != NULL) {
                printf("Human Language: %s\n", translation);
            } else {
                printf("Invalid word or phrase.\n");
            }
        }

        printf("\nEnter a word or phrase to translate (or 'quit' to exit): ");
        gets(input);
    }

    return 0;
}