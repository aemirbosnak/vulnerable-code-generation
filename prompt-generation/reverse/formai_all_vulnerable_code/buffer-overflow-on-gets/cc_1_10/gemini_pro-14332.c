//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MORSE_CODE_LENGTH 100

// Morse code table
const char *morse_code_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-",
    "--..--", "...---...", "...-.-", "....--", ".....-", "-....-", "--...",
    "---...", ".----.", "-....-", "..--..", "-.--.-", "-.--.-",
    ".----", "..-.-", "...--", "...--", "....-."
};

// Convert a character to Morse code
char *char_to_morse_code(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }

    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return (char *)morse_code_table[index];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse_code(char *str) {
    char *morse_code = malloc(MAX_MORSE_CODE_LENGTH * strlen(str) + 1);
    if (morse_code == NULL) {
        return NULL;
    }

    int len = 0;
    for (int i = 0; i < strlen(str); i++) {
        char *c_morse_code = char_to_morse_code(str[i]);
        if (c_morse_code != NULL) {
            strcat(morse_code, c_morse_code);
            len += strlen(c_morse_code);
        } else {
            free(morse_code);
            return NULL;
        }
    }

    morse_code[len] = '\0';
    return morse_code;
}

// Print Morse code in a nice format
void print_morse_code(char *morse_code) {
    for (int i = 0; i < strlen(morse_code); i++) {
        if (morse_code[i] == '.') {
            printf("·");
        } else if (morse_code[i] == '-') {
            printf("- ");
        } else if (morse_code[i] == ' ') {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    // Get input string
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    gets(str);

    // Convert string to Morse code
    char *morse_code = string_to_morse_code(str);
    if (morse_code == NULL) {
        printf("Error converting string to Morse code.\n");
        return 1;
    }

    // Print Morse code
    printf("Morse code: ");
    print_morse_code(morse_code);

    // Free memory
    free(morse_code);

    return 0;
}