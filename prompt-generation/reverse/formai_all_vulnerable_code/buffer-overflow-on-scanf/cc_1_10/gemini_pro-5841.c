//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
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
    " ",     // Space
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    // Convert the character to uppercase
    c = toupper(c);

    // Check if the character is a letter
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    }

    // Check if the character is a number
    else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    }

    // Check if the character is a space
    else if (c == ' ') {
        return morse_table[36];
    }

    // Otherwise, return an error message
    else {
        return "Invalid character";
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    // Allocate memory for the Morse code string
    char *morse_str = malloc(strlen(str) * 5);

    // Convert each character in the string to Morse code
    int i;
    for (i = 0; i < strlen(str); i++) {
        strcat(morse_str, char_to_morse(str[i]));
        strcat(morse_str, " ");
    }

    // Return the Morse code string
    return morse_str;
}

// Function to print the Morse code
void print_morse(char *morse_str) {
    // Print the Morse code string
    printf("%s\n", morse_str);
}

// Main function
int main() {
    // Get the input string
    char str[100];
    printf("Enter the string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_str = string_to_morse(str);

    // Print the Morse code
    print_morse(morse_str);

    // Free the allocated memory
    free(morse_str);

    return 0;
}