//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char *alien_dict[26] = {
    "Ayi", "Bifi", "Cidi", "Difi", "Efi", "Fifi", "Gidi", "Hifi", "Iji", "Jifi",
    "Kifi", "Lili", "Mifi", "Nifi", "Ofi", "Pifi", "Qifi", "Rifi", "Sifi", "Tifi",
    "Ufi", "Vifi", "Wifi", "Xifi", "Yifi", "Zifi"
};

// Translate a string from English to Alien language
char *translate_to_alien(char *english) {
    int len = strlen(english);
    char *alien = malloc(len * 4 + 1); // Allocate memory for the translated string
    int i;
    for (i = 0; i < len; i++) {
        char c = english[i];
        if (c >= 'a' && c <= 'z') {
            strcat(alien, alien_dict[c - 'a']);
        } else if (c >= 'A' && c <= 'Z') {
            strcat(alien, alien_dict[c - 'A']);
        } else {
            alien[i] = c; // Copy the character if it's not a letter
        }
    }
    alien[len * 4] = '\0'; // Add the null-terminator
    return alien;
}

// Translate a string from Alien language to English
char *translate_to_english(char *alien) {
    int len = strlen(alien);
    char *english = malloc(len / 4 + 1); // Allocate memory for the translated string
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < len; i += 4) {
        char *word = strndup(alien + i, 4);
        for (j = 0; j < 26; j++) {
            if (strcmp(word, alien_dict[j]) == 0) {
                english[k++] = j + 'a';
                break;
            }
        }
        free(word);
    }
    english[len / 4] = '\0'; // Add the null-terminator
    return english;
}

// Main function
int main() {
    // Get the input string
    char *input_string;
    printf("Enter a string to translate: ");
    input_string = malloc(100);
    scanf("%s", input_string);

    // Translate the string to Alien language
    char *alien_string = translate_to_alien(input_string);

    // Print the translated string
    printf("Translation in Alien language: %s\n", alien_string);

    // Translate the string back to English
    char *english_string = translate_to_english(alien_string);

    // Print the translated string
    printf("Translation back to English: %s\n", english_string);

    // Free the allocated memory
    free(input_string);
    free(alien_string);
    free(english_string);

    return 0;
}