//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
/*
 * C Text to Morse code conversion program
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Morse code mapping
char *morse_code[] = {
    ".-",   // A
    "-...", // B
    "-.-.",  // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

// Define the function to convert text to Morse code
void text_to_morse(char *text) {
    int i, j;
    for (i = 0; text[i] != '\0'; i++) {
        for (j = 0; j < 26; j++) {
            if (text[i] == morse_code[j][0]) {
                printf("%s ", morse_code[j]);
                break;
            }
        }
    }
}

// Define the function to convert Morse code to text
void morse_to_text(char *morse) {
    int i, j;
    for (i = 0; morse[i] != '\0'; i++) {
        for (j = 0; j < 26; j++) {
            if (morse[i] == morse_code[j][0]) {
                printf("%c", j + 'A');
                break;
            }
        }
    }
}

// Define the main function
int main() {
    char text[100];
    char morse[100];

    // Get the text to convert
    printf("Enter the text to convert: ");
    scanf("%s", text);

    // Convert the text to Morse code
    text_to_morse(text);
    printf("\n");

    // Convert the Morse code to text
    printf("Enter the Morse code to convert: ");
    scanf("%s", morse);
    morse_to_text(morse);
    printf("\n");

    return 0;
}