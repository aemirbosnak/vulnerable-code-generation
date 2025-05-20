//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Morse code dictionary
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.", "-...",
    "-.-.-", ".-..", "--..--"
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_code[index];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *code = char_to_morse(str[i]);
        if (code != NULL) {
            strcpy(morse_code + j, code);
            j += strlen(code);
            morse_code[j++] = ' ';
        }
    }
    return morse_code;
}

// Function to print Morse code
void print_morse_code(char *morse_code) {
    printf("%s", morse_code);
}

// Main function
int main() {
    // Get the input string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    print_morse_code(morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}