//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char *morse_code_dict[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }

    int index = c - 'A';
    if (index < 0 || index >= 26) {
        return NULL;
    }

    return morse_code_dict[index];
}

// Function to convert a string to Morse code
char *str_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1); // Maximum possible length of Morse code is 5 characters per character
    int pos = 0;

    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse != NULL) {
            strcpy(morse_code + pos, morse);
            pos += strlen(morse);
            morse_code[pos++] = ' ';
        }
    }

    morse_code[pos] = '\0';
    return morse_code;
}

int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = str_to_morse(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}