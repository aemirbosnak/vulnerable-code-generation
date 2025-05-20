//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
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
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else {
        return "";
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1); // Allocate enough memory for the Morse code
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse_code, char_to_morse(str[i]));
        strcat(morse_code, " ");
    }
    morse_code[len * 5] = '\0'; // Null-terminate the string
    return morse_code;
}

// Main function
int main() {
    // Get the text to convert from the user
    char text[100];
    printf("Enter the text to convert to Morse code: ");
    gets(text);

    // Convert the text to Morse code
    char *morse_code = string_to_morse(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    return 0;
}