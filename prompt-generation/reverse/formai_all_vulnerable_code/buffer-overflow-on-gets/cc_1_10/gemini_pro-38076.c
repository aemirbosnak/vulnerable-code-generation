//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char* morse_dict[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Function to convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_dict[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_dict[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_dict[c - '0' + 26];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse_str = malloc((len * 5 + 1) * sizeof(char)); // Allocate enough space for the Morse code string

    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char* morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcpy(morse_str + j, morse_char);
            j += strlen(morse_char);
            morse_str[j++] = ' '; // Add a space between Morse code characters
        }
    }

    morse_str[j] = '\0'; // Null-terminate the Morse code string
    return morse_str;
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    gets(str);

    // Convert the string to Morse code
    char* morse_str = string_to_morse(str);

    // Print the Morse code string
    printf("Morse code: %s\n", morse_str);

    // Free the allocated memory
    free(morse_str);

    return 0;
}