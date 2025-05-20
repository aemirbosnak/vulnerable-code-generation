//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: Sherlock Holmes
/*
 * Text to Morse code conversion program
 * Written in the style of Sherlock Holmes
 */
#include <stdio.h>

int main() {
    // Declare variables
    char text[100];
    char morse[100];
    int i, j;

    // Get the input text from the user
    printf("Enter the text to be converted: ");
    scanf("%s", text);

    // Initialize the Morse code array
    for (i = 0; i < 100; i++) {
        morse[i] = ' ';
    }

    // Convert the text to Morse code
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'A') {
            strcpy(morse, ".-");
        } else if (text[i] == 'B') {
            strcpy(morse, "-...");
        } else if (text[i] == 'C') {
            strcpy(morse, "-.-.");
        } else if (text[i] == 'D') {
            strcpy(morse, "-..");
        } else if (text[i] == 'E') {
            strcpy(morse, ".");
        } else if (text[i] == 'F') {
            strcpy(morse, "..-.");
        } else if (text[i] == 'G') {
            strcpy(morse, "--.");
        } else if (text[i] == 'H') {
            strcpy(morse, "....");
        } else if (text[i] == 'I') {
            strcpy(morse, "..");
        } else if (text[i] == 'J') {
            strcpy(morse, ".---");
        } else if (text[i] == 'K') {
            strcpy(morse, "-.-");
        } else if (text[i] == 'L') {
            strcpy(morse, ".-..");
        } else if (text[i] == 'M') {
            strcpy(morse, "--");
        } else if (text[i] == 'N') {
            strcpy(morse, "-.");
        } else if (text[i] == 'O') {
            strcpy(morse, "---");
        } else if (text[i] == 'P') {
            strcpy(morse, ".--.");
        } else if (text[i] == 'Q') {
            strcpy(morse, "--.-");
        } else if (text[i] == 'R') {
            strcpy(morse, ".-.");
        } else if (text[i] == 'S') {
            strcpy(morse, "...");
        } else if (text[i] == 'T') {
            strcpy(morse, "-");
        } else if (text[i] == 'U') {
            strcpy(morse, "..-");
        } else if (text[i] == 'V') {
            strcpy(morse, "...-");
        } else if (text[i] == 'W') {
            strcpy(morse, ".--");
        } else if (text[i] == 'X') {
            strcpy(morse, "-..-");
        } else if (text[i] == 'Y') {
            strcpy(morse, "-.--");
        } else if (text[i] == 'Z') {
            strcpy(morse, "--..");
        } else if (text[i] == ' ') {
            strcpy(morse, " ");
        } else if (text[i] == '\n') {
            strcpy(morse, "\n");
        } else {
            // If the character is not a letter or space, print an error message
            printf("Error: Invalid character %c\n", text[i]);
        }

        // Print the Morse code for the current character
        printf("%s", morse);
    }

    return 0;
}