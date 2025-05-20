//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
    "  ", ".-.-.-", "..--..", "...--.", "....-.", ".....-", "-....-",
    "--...--", "---...-", "----..", "-----."
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int i = c - 'A';
    if (i >= 0 && i < 26) {
        return morse_table[i];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5); // enough space for the longest Morse code sequence
    int j = 0;
    for (int i = 0; i < len; i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcpy(morse_code + j, morse_char);
            j += strlen(morse_char);
            morse_code[j++] = ' '; // space between characters
        }
    }
    morse_code[j] = '\0';
    return morse_code;
}

// Print a string in Morse code
void print_morse_code(char *morse_code) {
    int len = strlen(morse_code);
    for (int i = 0; i < len; i++) {
        if (morse_code[i] == ' ') {
            printf("  ");
        } else {
            printf("%c", morse_code[i]);
        }
    }
    printf("\n");
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: ");
    print_morse_code(morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}