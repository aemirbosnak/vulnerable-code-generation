//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code alphabet
char *morse_alphabet[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    "....", ".-..", "..--", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Define the inverse Morse code alphabet (Morse code to text)
char inverse_morse_alphabet[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '
};

// Convert a text character to Morse code
char *text_to_morse(char character) {
    // Convert the character to uppercase
    character = toupper(character);

    // Get the index of the character in the alphabet
    int index = character - 'A';

    // Return the Morse code representation of the character
    return morse_alphabet[index];
}

// Convert a Morse code character to text
char morse_to_text(char character) {
    // Get the index of the character in the inverse alphabet
    int index = strchr(inverse_morse_alphabet, character) - inverse_morse_alphabet;

    // Return the text representation of the character
    return inverse_morse_alphabet[index];
}

// Convert a text string to Morse code
char *text_to_morse_string(char *text) {
    // Allocate memory for the Morse code string
    char *morse_code = malloc(strlen(text) * 5);

    // Convert each character in the text string to Morse code
    for (int i = 0; i < strlen(text); i++) {
        strcat(morse_code, text_to_morse(text[i]));
    }

    // Return the Morse code string
    return morse_code;
}

// Convert a Morse code string to text
char *morse_to_text_string(char *morse_code) {
    // Allocate memory for the text string
    char *text = malloc(strlen(morse_code) / 5);

    // Convert each character in the Morse code string to text
    for (int i = 0; i < strlen(morse_code); i += 5) {
        text[i / 5] = morse_to_text(morse_code[i]);
    }

    // Return the text string
    return text;
}

// Main function
int main() {
    // Get the text string from the user
    char text[100];
    printf("Enter a text string: ");
    scanf("%s", text);

    // Convert the text string to Morse code
    char *morse_code = text_to_morse_string(text);

    // Print the Morse code string
    printf("Morse code: %s\n", morse_code);

    // Convert the Morse code string to text
    char *text_back = morse_to_text_string(morse_code);

    // Print the text string
    printf("Text string: %s\n", text_back);

    // Free the allocated memory
    free(morse_code);
    free(text_back);

    return 0;
}