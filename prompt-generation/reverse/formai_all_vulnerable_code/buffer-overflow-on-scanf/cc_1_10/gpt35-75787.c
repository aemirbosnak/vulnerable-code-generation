//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <string.h>

// Morse code lookup table
const char* MORSE_TABLE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to Morse code
void char_to_morse(char input, char* output) {
    int ascii = (int)input;
    if (ascii >= 65 && ascii <= 90) { // Upper case letters
        strcpy(output, MORSE_TABLE[ascii - 65]);
    } else if (ascii >= 97 && ascii <= 122) { // Lower case letters
        strcpy(output, MORSE_TABLE[ascii - 97]);
    } else if (ascii >= 48 && ascii <= 57) { // Digits
        strcpy(output, MORSE_TABLE[ascii - 22]);
    } else if (ascii == 32) { // Space
        strcpy(output, "/");
    } else { // Everything else is ignored
        strcpy(output, "");
    }
}

// Function to convert a string to Morse code
void text_to_morse(char* input, char* output) {
    char morse_code[5];
    output[0] = '\0'; // Make sure output is empty

    for (int i = 0; i < strlen(input); i++) {
        char_to_morse(input[i], morse_code);
        strcat(output, morse_code);
        strcat(output, " ");
    }
}

int main() {
    char text[100];
    char morse[200];

    printf("Enter some text to convert to Morse code: ");
    scanf("%[^\n]", text);
    text_to_morse(text, morse);
    printf("Text: %s\n", text);
    printf("Morse code: %s\n", morse);

    return 0;
}