//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

/* -- C Text to Morse Code Conversion Example -- */

/* Morse Code Character Representations */
const char* morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--.."
};

/* ASCII Character Representations */
const char* ascii[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
    "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
    "W", "X", "Y", "Z"
};

/* Function to Convert ASCII Characters to Morse Code Characters */
char* asciiToMorse(char* text) {
    size_t len = strlen(text);
    static char morse[100] = "";
    for (size_t i = 0; i < len; i++) {
        /* Characters to Upper Case */
        text[i] = toupper(text[i]);
        for (size_t j = 0; j < 26; j++) {
            if (text[i] == *ascii[j]) {
                /* Append Morse Code Representation */
                strcat(morse, morseCode[j]);
                strcat(morse, " ");
                break;
            }
        }
    }
    return morse;
}

int main() {
    /* Welcome Message */
    printf("Welcome to C Text to Morse Code Conversion Example!\n\n");

    /* Get Input String */
    char text[100];
    printf("Enter the text you want to convert to Morse Code:\n");
    gets(text);

    /* Convert to UTF-8 and Print Result */
    printf("\nMorse Code Representation: %s\n", asciiToMorse(text));

    /* Goodbye Message */
    printf("\nThank you for using our program!\n");

    return 0;
}