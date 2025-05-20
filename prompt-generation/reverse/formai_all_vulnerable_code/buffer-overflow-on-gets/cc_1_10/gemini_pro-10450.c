//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Morse code table
const char *morse_code[] = {
    ".-",   // A
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
    "--..", // Z
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
    " ",     // space
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else if (c == ' ') {
        return morse_code[36];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int i, len = strlen(str);
    char *morse_str = malloc(len * 4 + 1); // Allocate enough space for the Morse code string
    memset(morse_str, 0, len * 4 + 1); // Initialize the Morse code string to 0

    for (i = 0; i < len; i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcat(morse_str, morse_char);
            strcat(morse_str, " "); // Add a space between Morse code characters
        }
    }

    return morse_str;
}

// Print a Morse code string
void print_morse_code(char *morse_str) {
    int i, len = strlen(morse_str);

    for (i = 0; i < len; i++) {
        if (morse_str[i] == '.') {
            printf("·");
        } else if (morse_str[i] == '-') {
            printf("–");
        } else if (morse_str[i] == ' ') {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    char str[MAX_LINE_LENGTH];
    char *morse_str;

    printf("Enter a string to convert to Morse code: ");
    gets(str);

    morse_str = string_to_morse(str);

    printf("Morse code:");
    print_morse_code(morse_str);

    free(morse_str);

    return 0;
}