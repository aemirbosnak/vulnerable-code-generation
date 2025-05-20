//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
// C Text to Morse Code Conversion Program
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Morse code lookup table
const char *morseCodeLookupTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Function to convert text to Morse code
void textToMorseCode(char *text, char *morseCode) {
    int i, j;

    // Convert all characters to uppercase for uniformity
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = toupper(text[i]);
    }

    for (i = 0, j = 0; text[i] != '\0'; i++, j++) {
        // Check if character is alphanumeric or a space
        if (isalnum(text[i])) {
            // Convert the alphanumeric character to its respective Morse code
            strcpy(&morseCode[j], morseCodeLookupTable[toupper(text[i]) - 'A']);
        } else if (text[i] == ' ') {
            // Add space for each word
            morseCode[j++] = ' ';
        } else {
            // If character is not alphanumeric and not space, ignore it
            j--;
        }
    }
    morseCode[j] = '\0';
}

int main() {
    char text[100], morseCode[500];
    int choice;

    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    do {
        printf("Choose output format:\n");
        printf("1. Dots and Dashes.\n");
        printf("2. Audio format.\n");
        printf("3. Quit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                textToMorseCode(text, morseCode);
                printf("Morse code for '%s': %s\n", text, morseCode);
                break;
            case 2:
                printf("Converting to audio format.\n"); // code for audio conversion goes here
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}