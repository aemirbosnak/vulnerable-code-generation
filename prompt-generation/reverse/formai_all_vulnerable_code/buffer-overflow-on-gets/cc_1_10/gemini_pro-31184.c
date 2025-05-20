//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", "----", ".-.-.-",
    "--..--", ".-.-", "...--", "...--...", ".-.-.-."
};

// Text to Morse code conversion function
void text_to_morse(char *text) {
    int i, j, k;
    char morse[1000];

    // Convert each character of the text to its corresponding Morse code
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            j = text[i] - 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            j = text[i] - 'a' + 26;
        } else if (text[i] == ' ') {
            j = 52;
        } else {
            j = -1;
        }

        if (j >= 0) {
            strcpy(morse + strlen(morse), morse_code[j]);
            strcat(morse + strlen(morse), " ");
        }
    }

    // Print the Morse code
    printf("Morse code: %s\n", morse);
}

// Main function
int main() {
    char text[1000];

    // Get the text from the user
    printf("Enter the text to be converted to Morse code: ");
    gets(text);

    // Convert the text to Morse code
    text_to_morse(text);

    return 0;
}