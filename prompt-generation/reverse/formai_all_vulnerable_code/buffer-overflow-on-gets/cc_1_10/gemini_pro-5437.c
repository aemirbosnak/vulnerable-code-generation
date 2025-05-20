//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--.."
};

// Morse code alphabet
char alphabet[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

// Function to convert a character to Morse code
char *to_morse(char c) {
    for (int i = 0; i < 26; i++) {
        if (c == alphabet[i]) {
            return morse_table[i];
        }
    }
    return NULL;
}

// Function to convert a string to Morse code
char *to_morse_string(char *str) {
    char *morse_code = malloc(strlen(str) * 5);
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        char *morse = to_morse(str[i]);
        if (morse != NULL) {
            strcat(morse_code, morse);
            strcat(morse_code, " ");
            j += strlen(morse) + 1;
        }
    }
    morse_code[j - 1] = '\0';
    return morse_code;
}

// Function to print a string in Morse code
void print_morse(char *str) {
    char *morse_code = to_morse_string(str);
    printf("%s\n", morse_code);
    free(morse_code);
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Convert the string to Morse code
    char *morse_code = to_morse_string(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}