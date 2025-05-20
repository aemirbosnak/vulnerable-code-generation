//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse_code = malloc(strlen(str) * 5);
    int i;
    for (i = 0; i < strlen(str); i++) {
        strcat(morse_code, char_to_morse(str[i]));
    }
    return morse_code;
}

// Main function
int main() {
    // Get the input string
    char *str = malloc(100);
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Free the allocated memory
    free(str);
    free(morse_code);

    return 0;
}