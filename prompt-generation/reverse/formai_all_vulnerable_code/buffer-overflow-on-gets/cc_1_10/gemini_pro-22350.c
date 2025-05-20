//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the Morse code dictionary
char *morse_codes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    // Check if the character is valid
    if (c < 'A' || c > 'Z') {
        return NULL;
    }

    // Return the corresponding Morse code
    return morse_codes[c - 'A'];
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    // Allocate memory for the Morse code string
    char *morse_code = malloc(1000);

    // Convert each character in the string to Morse code
    int i = 0;
    while (str[i] != '\0') {
        char *morse_char = char_to_morse(str[i]);
        strcat(morse_code, morse_char);
        strcat(morse_code, " ");
        i++;
    }

    // Return the Morse code string
    return morse_code;
}

// Main function
int main() {
    // Get the string to convert from the user
    char str[100];
    printf("Enter the string to convert to Morse code: ");
    gets(str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("The Morse code for \"%s\" is: %s\n", str, morse_code);

    // Free the memory allocated for the Morse code string
    free(morse_code);

    return 0;
}