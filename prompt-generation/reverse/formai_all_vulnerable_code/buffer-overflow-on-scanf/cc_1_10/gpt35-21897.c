//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

const char ALIEN_ALPHABET[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

void print_greeting() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please input the text you would like to translate:\n");
}

int main() {
    char input[1000];
    char output[1000];
    int translation_key;
    int input_length;
    int i, j;

    print_greeting();

    fgets(input, 1000, stdin);
    input_length = strlen(input);

    printf("Please enter the translation key (an integer between 1 and 50):\n");

    scanf("%d", &translation_key);

    // Sanity check
    if (translation_key < 1 || translation_key > 50) {
        printf("Invalid translation key!\n");
        return 1;
    }

    printf("Translating...\n");

    for (i = 0; i < input_length; i++) {
        char current_char = input[i];

        // Check if the current character exists in the alien alphabet
        int index = -1;
        for (j = 0; j < strlen(ALIEN_ALPHABET); j++) {
            if (ALIEN_ALPHABET[j] == current_char) {
                index = j;
                break;
            }
        }

        if (index != -1) {
            // Apply the Caesar Cipher
            int new_index = (index + translation_key) % strlen(ALIEN_ALPHABET);
            output[i] = ALIEN_ALPHABET[new_index];
        } else {
            output[i] = current_char;
        }
    }

    printf("Translation complete:\n%s\n", output);
    return 0;
}