//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language alphabet
#define CAT_ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Define the English alphabet
#define ENG_ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Function to translate a Cat Language string to English
char* translate_to_english(char* cat_string) {
    // Allocate memory for the English string
    char* eng_string = malloc(strlen(cat_string) + 1);

    // Iterate over the Cat Language string
    for (int i = 0; i < strlen(cat_string); i++) {
        // Find the index of the Cat Language character in the Cat Language alphabet
        int cat_index = strchr(CAT_ALPHABET, cat_string[i]) - CAT_ALPHABET;

        // Find the English character at the same index in the English alphabet
        char eng_char = ENG_ALPHABET[cat_index];

        // Append the English character to the English string
        eng_string[i] = eng_char;
    }

    // Add a null terminator to the English string
    eng_string[strlen(cat_string)] = '\0';

    // Return the English string
    return eng_string;
}

// Function to translate an English string to Cat Language
char* translate_to_cat_language(char* eng_string) {
    // Allocate memory for the Cat Language string
    char* cat_string = malloc(strlen(eng_string) + 1);

    // Iterate over the English string
    for (int i = 0; i < strlen(eng_string); i++) {
        // Find the index of the English character in the English alphabet
        int eng_index = strchr(ENG_ALPHABET, eng_string[i]) - ENG_ALPHABET;

        // Find the Cat Language character at the same index in the Cat Language alphabet
        char cat_char = CAT_ALPHABET[eng_index];

        // Append the Cat Language character to the Cat Language string
        cat_string[i] = cat_char;
    }

    // Add a null terminator to the Cat Language string
    cat_string[strlen(eng_string)] = '\0';

    // Return the Cat Language string
    return cat_string;
}

// Main function
int main() {
    // Get the Cat Language string from the user
    char* cat_string = (char*) malloc(100);
    printf("Enter a Cat Language string: ");
    scanf("%s", cat_string);

    // Translate the Cat Language string to English
    char* eng_string = translate_to_english(cat_string);

    // Print the English string
    printf("The English translation is: %s\n", eng_string);

    // Translate the English string back to Cat Language
    char* cat_string2 = translate_to_cat_language(eng_string);

    // Print the Cat Language string
    printf("The Cat Language translation back is: %s\n", cat_string2);

    // Free the allocated memory
    free(cat_string);
    free(eng_string);
    free(cat_string2);

    return 0;
}