//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code lookup table
char *morse_table[] = {
    ".-",    // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse = malloc(len * 5); // Allocate enough space for the worst case
    int i;
    int pos = 0;

    for (i = 0; i < len; i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcpy(morse + pos, morse_char);
            pos += strlen(morse_char);
            morse[pos++] = ' '; // Add a space between characters
        }
    }

    morse[pos] = '\0'; // Null-terminate the string
    return morse;
}

// Print a string in Morse code
void print_morse(char *morse) {
    int len = strlen(morse);
    int i;

    for (i = 0; i < len; i++) {
        if (morse[i] == ' ') {
            printf("   "); // Print a space for spaces in the Morse code
        } else if (morse[i] == '.') {
            printf("· "); // Print a dot for dots in the Morse code
        } else if (morse[i] == '-') {
            printf("- "); // Print a dash for dashes in the Morse code
        }
    }

    printf("\n");
}

int main() {
    // Get the input string from the user
    char *str = malloc(100);
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: ");
    print_morse(morse);

    // Free the allocated memory
    free(str);
    free(morse);

    return 0;
}