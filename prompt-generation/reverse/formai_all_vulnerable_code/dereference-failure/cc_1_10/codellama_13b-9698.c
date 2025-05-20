//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
// Example of a unique C Text to Morse code conversion program in a secure style
#include <stdio.h>
#include <string.h>

// Define a dictionary for the Morse code
char *morse_dict[] = {
    ".-", // A
    "-...", // B
    "-.-.", // C
    "-..", // D
    ".", // E
    "..-.", // F
    "--.", // G
    "....", // H
    "..", // I
    ".---", // J
    "-.-", // K
    ".-..", // L
    "--", // M
    "-.", // N
    "---", // O
    ".--.", // P
    "--.-", // Q
    ".-.", // R
    "...", // S
    "-", // T
    "..-", // U
    "...-", // V
    ".--", // W
    "-..-", // X
    "-.--", // Y
    "--.." // Z
};

// Define a function to convert a character to its corresponding Morse code
char *char_to_morse(char c) {
    return morse_dict[c - 'A'];
}

// Define a function to convert a string to its corresponding Morse code
char *str_to_morse(char *str) {
    int len = strlen(str);
    char *morse = malloc(len * 3 + 1);
    int i;
    for (i = 0; i < len; i++) {
        char_to_morse(str[i]);
        strcat(morse, morse_dict[str[i] - 'A']);
    }
    return morse;
}

// Test the program
int main() {
    char *str = "HELLO";
    char *morse = str_to_morse(str);
    printf("%s\n", morse);
    return 0;
}