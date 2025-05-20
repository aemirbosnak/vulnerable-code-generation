//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language dictionary
char *cat_dict[] = {
    "meow", "food", "water", "play", "sleep", "outside", "inside", "litter box", "scratching post", "grooming"
};

// Define the English Language dictionary
char *eng_dict[] = {
    "mew", "chow", "H2O", "frolic", "nap", "outdoors", "indoors", "toilet", "scratch pad", "groom"
};

// Translate a Cat Language word to English
char *cat_to_eng(char *cat_word) {
    for (int i = 0; i < sizeof(cat_dict) / sizeof(char *); i++) {
        if (strcmp(cat_word, cat_dict[i]) == 0) {
            return eng_dict[i];
        }
    }

    return "Unknown word";
}

// Translate an English word to Cat Language
char *eng_to_cat(char *eng_word) {
    for (int i = 0; i < sizeof(eng_dict) / sizeof(char *); i++) {
        if (strcmp(eng_word, eng_dict[i]) == 0) {
            return cat_dict[i];
        }
    }

    return "Unknown word";
}

// Get a Cat Language word from the user
char *get_cat_word() {
    char *cat_word = (char *)malloc(sizeof(char) * 20);
    printf("Enter a Cat Language word: ");
    scanf("%s", cat_word);

    return cat_word;
}

// Get an English word from the user
char *get_eng_word() {
    char *eng_word = (char *)malloc(sizeof(char) * 20);
    printf("Enter an English word: ");
    scanf("%s", eng_word);

    return eng_word;
}

// Print the translation
void print_translation(char *cat_word, char *eng_word) {
    printf("Cat Language: %s\n", cat_word);
    printf("English: %s\n", eng_word);
}

// Main function
int main() {
    // Get the Cat Language word
    char *cat_word = get_cat_word();

    // Translate the Cat Language word to English
    char *eng_word = cat_to_eng(cat_word);

    // Print the translation
    print_translation(cat_word, eng_word);

    // Free the allocated memory
    free(cat_word);
    free(eng_word);

    return 0;
}