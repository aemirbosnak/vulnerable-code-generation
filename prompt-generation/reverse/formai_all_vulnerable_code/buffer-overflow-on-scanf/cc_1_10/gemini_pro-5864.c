//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_code[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    " ",     // Space
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;  // Convert to uppercase
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else if (c == ' ') {
        return morse_code[36];  // Space
    } else {
        return NULL;  // Invalid character
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);  // Allocate memory for the Morse code string
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse != NULL) {
            strcpy(morse_code + j, morse);
            j += strlen(morse);
            morse_code[j++] = ' ';  // Add a space between characters
        }
    }
    morse_code[j] = '\0';  // Null-terminate the string
    return morse_code;
}

// Print the Morse code for a given string
void print_morse_code(char *morse_code) {
    printf("Morse code: %s\n", morse_code);
}

int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    print_morse_code(morse_code);

    // Free the memory allocated for the Morse code string
    free(morse_code);

    return 0;
}