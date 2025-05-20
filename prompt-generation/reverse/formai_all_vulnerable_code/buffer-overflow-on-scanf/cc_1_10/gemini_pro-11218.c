//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char alien_dict[26][26] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "NOPQRSTUVWXYZABCDEFGHIJKLM",
    "GHIJKLMNOPQRSTUVWXYZABCDEF",
    "DEFGHIJKLMNOPQRSTUVWXYZABC",
    "CDEFGHIJKLMNOPQRSTUVWXYZAB",
    "BCDEFGHIJKLMNOPQRSTUVWXYZ",
    "ZYXWVUTSRQPONMLKJIHGFEDCBA",
    "MLKJIHGFEDCBAZYXWVUTSRQPON",
    "KJIHGFEDCBAZYXWVUTSRQPONML",
    "JIHGFEDCBAZYXWVUTSRQPONMLK",
    "IHGFEDCBAZYXWVUTSRQPONMLKJ",
    "HGEDCBAZYXWVUTSRQPONMLKIJ",
    "GFEDCBAZYXWVUTSRQPONMLKIJH",
    "FEDCBAZYXWVUTSRQPONMLKIJHG",
    "EDCBAZYXWVUTSRQPONMLKIJHGF",
    "DCBAZYXWVUTSRQPONMLKIJHGF",
    "CBAZYXWVUTSRQPONMLKIJHGFED",
    "BAZYXWVUTSRQPONMLKIJHGFEDC",
    "AZYXWVUTSRQPONMLKIJHGFEDCB",
    "ZYXWVUTSRQPONMLKIJHGFEDCBA",
    "YXWVUTSRQPONMLKIJHGFEDCBAZ",
    "XWUTSRQPONMLKIJHGFEDCBAZY",
    "WUTSRQPONMLKIJHGFEDCBAZYX",
    "UTSRQPONMLKIJHGFEDCBAZYXW",
    "TSRQPONMLKIJHGFEDCBAZYXWU"
};

// Function to translate a string from English to Alien language
char *translate_to_alien(char *input) {
    int input_len = strlen(input);
    char *output = malloc(input_len + 1);
    for (int i = 0; i < input_len; i++) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            output[i] = alien_dict[c - 'A'][0];
        } else if (c >= 'a' && c <= 'z') {
            output[i] = alien_dict[c - 'a'][0];
        } else {
            output[i] = c;
        }
    }
    output[input_len] = '\0';
    return output;
}

// Function to translate a string from Alien language to English
char *translate_from_alien(char *input) {
    int input_len = strlen(input);
    char *output = malloc(input_len + 1);
    for (int i = 0; i < input_len; i++) {
        char c = input[i];
        for (int j = 0; j < 26; j++) {
            if (c == alien_dict[j][0]) {
                output[i] = 'A' + j;
                break;
            }
        }
    }
    output[input_len] = '\0';
    return output;
}

int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a string to translate: ");
    scanf("%s", input);

    // Translate the string to Alien language
    char *alien_translation = translate_to_alien(input);
    printf("Alien translation: %s\n", alien_translation);

    // Translate the string back to English
    char *english_translation = translate_from_alien(alien_translation);
    printf("English translation: %s\n", english_translation);

    // Free the allocated memory
    free(alien_translation);
    free(english_translation);

    return 0;
}