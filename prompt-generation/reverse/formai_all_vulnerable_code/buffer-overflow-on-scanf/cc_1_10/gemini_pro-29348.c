//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char morse_table[26][5] = {
    {'.', '-', '-', '-', '-'}, // A
    {'-', '...', '-', '-', '-'}, // B
    {'-', '-', '.-.', '-', '-'}, // C
    {'-', '-', '-', '.-', '-'}, // D
    {'.', '.', '-', '-', '-'}, // E
    {'.', '.-', '.-', '-', '-'}, // F
    {'-', '--', '-', '-', '-'}, // G
    {'.', '....', '-', '-', '-'}, // H
    {'.', '.', '-', '-', '-'}, // I
    {'.', '-', '-', '-', '.'}, // J
    {'-', '-', '.-', '-', '-'}, // K
    {'.', '-', '.-.', '-', '-'}, // L
    {'-', '-', '-', '-', '-'}, // M
    {'-', '-', '-', '-', '-'}, // N
    {'-', '-', '-', '-', '-'}, // O
    {'.', '--', '.-', '-', '-'}, // P
    {'-', '--', '-', '-', '-'}, // Q
    {'.', '-', '-', '.-', '-'}, // R
    {'.', '.', '.', '-', '-'}, // S
    {'-', '-', '-', '-', '-'}, // T
    {'.', '-', '-', '-', '-'}, // U
    {'.', '.-', '.-', '-', '-'}, // V
    {'.', '-', '-', '-', '-'}, // W
    {'-', '--', '-', '-', '-'}, // X
    {'-', '-', '.-', '-', '-'}, // Y
    {'-', '-', '-', '-', '-'}  // Z
};

// Function to convert a character to Morse code
void char_to_morse(char c, char *morse_code) {
    int index = c - 'A';
    strcpy(morse_code, morse_table[index]);
}

// Function to convert a string to Morse code
void string_to_morse(char *str, char *morse_code) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char_to_morse(str[i], morse_code);
        strcat(morse_code, " ");
    }
}

// Main function
int main() {
    // Get the input string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char morse_code[1000];
    string_to_morse(str, morse_code);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    return 0;
}