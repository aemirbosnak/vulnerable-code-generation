//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Morse code dictionary
const char *morse_code[] = {
    ".-",     // A
    "-...",   // B
    "-.-.",   // C
    "-..",    // D
    ".",      // E
    "..-.",   // F
    "--.",    // G
    "....",   // H
    "..",     // I
    ".---",   // J
    "-.-",    // K
    ".-.." ,  // L
    "--",     // M
    "-.",     // N
    "---",    // O
    ".--.",   // P
    "--.-",   // Q
    ".-.",    // R
    "...",    // S
    "-",      // T
    "..-",    // U
    "...-",   // V
    ".--",    // W
    "-..-",   // X
    "-.--",   // Y
    "--..",   // Z
    "-----",  // 0
    ".----",  // 1
    "..---",  // 2
    "...--",  // 3
    "....-",  // 4
    ".....",  // 5
    "-....",  // 6
    "--...",  // 7
    "---..",  // 8
    "----.",  // 9
    "-.--.-", // " " (space)
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
    int len = strlen(str);
    char *morse_code_str = malloc(len * 5 + 1); // Allocate enough space for the Morse code string
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *morse_code_char = char_to_morse(str[i]);
        if (morse_code_char != NULL) {
            strcpy(morse_code_str + j, morse_code_char);
            j += strlen(morse_code_char);
            morse_code_str[j++] = ' '; // Add a space between characters
        }
    }
    morse_code_str[j] = '\0'; // Null-terminate the string
    return morse_code_str;
}

// Convert a Morse code string to a character
char morse_to_char(char *morse_code) {
    int i;
    for (i = 0; i < 37; i++) {
        if (strcmp(morse_code, morse_code[i]) == 0) {
            if (i < 26) {
                return 'A' + i;
            } else if (i < 36) {
                return '0' + i - 26;
            } else {
                return ' ';
            }
        }
    }
    return '\0'; // Not a valid Morse code character
}

// Convert a Morse code string to a string
char *morse_to_string(char *morse_code) {
    int len = strlen(morse_code);
    char *str = malloc(len + 1); // Allocate enough space for the string
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        if (morse_code[i] == ' ') {
            i++; // Skip the space
        }
        char morse_code_char[4];
        strncpy(morse_code_char, morse_code + i, 3);
        morse_code_char[3] = '\0'; // Null-terminate the string
        char c = morse_to_char(morse_code_char);
        str[j++] = c;
    }
    str[j] = '\0'; // Null-terminate the string
    return str;
}

// Main function
int main() {
    // Get the input string from the user
    char str[101];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code_str = string_to_morse(str);

    // Print the Morse code string
    printf("Morse code: %s\n", morse_code_str);

    // Convert the Morse code string back to a string
    char *decoded_str = morse_to_string(morse_code_str);

    // Print the decoded string
    printf("Decoded string: %s\n", decoded_str);

    // Free the allocated memory
    free(morse_code_str);
    free(decoded_str);

    return 0;
}