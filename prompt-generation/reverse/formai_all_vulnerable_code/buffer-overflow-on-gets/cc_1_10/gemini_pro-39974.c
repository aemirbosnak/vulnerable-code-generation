//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Morse code character and code pairs
typedef struct morse_pair {
    char character;
    char *code;
} morse_pair;

morse_pair morse_codes[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {' ', " "}
};

// Function to convert text to Morse code
char *text_to_morse(char *text) {
    int i, j;
    int text_len = strlen(text);
    int morse_len = 0;

    // Calculate the length of the Morse code string
    for (i = 0; i < text_len; i++) {
        for (j = 0; j < (sizeof(morse_codes) / sizeof(morse_pair)); j++) {
            if (text[i] == morse_codes[j].character) {
                morse_len += strlen(morse_codes[j].code) + 1;  // +1 for space
            }
        }
    }

    // Allocate memory for the Morse code string
    char *morse_code = (char *)malloc(morse_len);

    // Convert text to Morse code
    int index = 0;
    for (i = 0; i < text_len; i++) {
        for (j = 0; j < (sizeof(morse_codes) / sizeof(morse_pair)); j++) {
            if (text[i] == morse_codes[j].character) {
                strcpy(&morse_code[index], morse_codes[j].code);
                index += strlen(morse_codes[j].code);
                morse_code[index++] = ' ';  // Add space between characters
            }
        }
    }

    // Add null-terminator to the Morse code string
    morse_code[index] = '\0';

    return morse_code;
}

// Function to print the Morse code
void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

// Main function
int main() {
    // Get the text to be converted to Morse code
    char text[100];
    printf("Enter text to convert to Morse code: ");
    gets(text);

    // Convert text to Morse code
    char *morse_code = text_to_morse(text);

    // Print the Morse code
    printf("Morse code: ");
    print_morse_code(morse_code);

    // Free the memory allocated for the Morse code string
    free(morse_code);

    return 0;
}