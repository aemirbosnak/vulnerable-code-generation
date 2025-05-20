//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert text to Morse code
void text_to_morse(char* text) {
    char* morse_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789,.?-";
    char morse_code[1000];
    int i, j;

    for (i = 0; text[i]!= '\0'; i++) {
        char c = toupper(text[i]);
        int found = 0;

        // Search for character in Morse code table
        for (j = 0; morse_table[j]!= '\0'; j++) {
            if (morse_table[j] == c) {
                strcat(morse_code, morse_table[j]);
                found = 1;
                break;
            }
        }

        // If character not found, add space to Morse code
        if (!found) {
            strcat(morse_code, " ");
        }
    }

    // Print Morse code
    printf("Morse code: %s\n", morse_code);
}

int main() {
    char text[1000];

    // Prompt user for input
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from input
    int len = strlen(text);
    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    // Convert text to Morse code
    text_to_morse(text);

    return 0;
}