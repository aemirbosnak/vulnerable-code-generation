//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|", ",", ".", "..",
    "..-", "...", "....", ".....", "-....", "--...", "---..", "----.", "-----", "",
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_table[index];
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5); // Allocate enough space for the worst case scenario (5 characters per character)
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse_char = char_to_morse(str[i]);
        strcat(morse_code, morse_char);
        strcat(morse_code, " ");
        index += strlen(morse_char) + 1;
    }
    return morse_code;
}

// Print the Morse code representation of a string
void print_morse_code(char *morse_code) {
    printf("Morse code: %s\n", morse_code);
}

int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code representation of the string
    print_morse_code(morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}