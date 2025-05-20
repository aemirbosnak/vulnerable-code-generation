//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

// Morse code table
static char *morse_table[] = {
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
};

// Convert a text character to its corresponding Morse code
static char *text_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    }
    if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    }
    return NULL;
}

// Convert a text string to its corresponding Morse code
static char *text_to_morse_string(char *text) {
    char *morse_code = malloc(strlen(text) * 5);
    int i;
    int j = 0;
    for (i = 0; i < strlen(text); i++) {
        char *morse = text_to_morse(text[i]);
        if (morse != NULL) {
            strcpy(morse_code + j, morse);
            j += strlen(morse);
            morse_code[j++] = ' ';
        }
    }
    morse_code[j] = '\0';
    return morse_code;
}

// Convert a Morse code string to its corresponding text
static char *morse_to_text(char *morse_code) {
    char *text = malloc(strlen(morse_code));
    int i;
    int j = 0;
    char *morse = strtok(morse_code, " ");
    while (morse != NULL) {
        for (i = 0; i < 36; i++) {
            if (strcmp(morse, morse_table[i]) == 0) {
                text[j++] = 'A' + i;
                break;
            }
        }
        morse = strtok(NULL, " ");
    }
    text[j] = '\0';
    return text;
}

// Convert a Morse code string to its corresponding ASCII code
static char *morse_to_ascii(char *morse_code) {
    char *ascii_code = malloc(strlen(morse_code));
    int i;
    int j = 0;
    char *morse = strtok(morse_code, " ");
    while (morse != NULL) {
        for (i = 0; i < 36; i++) {
            if (strcmp(morse, morse_table[i]) == 0) {
                ascii_code[j++] = i + (i < 26 ? 'A' : '0');
                break;
            }
        }
        morse = strtok(NULL, " ");
    }
    ascii_code[j] = '\0';
    return ascii_code;
}

// Main function
int main() {
    // Get the text from the user
    char text[MAX_BUF_SIZE];
    printf("Enter the text to convert: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse_code = text_to_morse_string(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Convert the Morse code to text
    char *text_back = morse_to_text(morse_code);

    // Print the converted text
    printf("Converted text: %s\n", text_back);

    // Convert the Morse code to ASCII code
    char *ascii_code = morse_to_ascii(morse_code);

    // Print the ASCII code
    printf("ASCII code: %s\n", ascii_code);

    // Free the allocated memory
    free(morse_code);
    free(text_back);
    free(ascii_code);

    return 0;
}