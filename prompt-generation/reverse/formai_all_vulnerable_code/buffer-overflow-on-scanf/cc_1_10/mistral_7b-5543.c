//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse code symbols
const char morse[][5] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert English character to Morse code
void char_to_morse(char c, char morse_code[32]) {
    int index;

    // Convert uppercase English character
    if (isupper(c)) {
        index = c - 'A';
    }
    // Convert lowercase English character
    else if (islower(c)) {
        index = c - 'a' + 26;
    }
    // If character is not alphabetic
    else {
        strcpy(morse_code, "");
        return;
    }

    // Copy Morse code for the given English character
    strcpy(morse_code, morse[index]);
}

// Function to print Morse code for a given English character
void print_morse(char morse_code[32]) {
    int i;

    // Print Morse code dots and dashes
    for (i = 0; morse_code[i] != '\0'; i++) {
        if (morse_code[i] == '.') {
            printf(" .   ");
        } else if (morse_code[i] == '-') {
            printf(" -   ");
        }
    }
    printf("\n");
}

int main() {
    char text[100], morse_code[1024][32];
    int i, j, length;

    printf("Enter English text: ");
    scanf("%s", text);

    // Convert English text to Morse code
    length = strlen(text);
    for (i = 0; i < length; i++) {
        char_to_morse(text[i], morse_code[i]);
        printf("%c to Morse code: ", text[i]);
        print_morse(morse_code[i]);
    }

    printf("\nText to Morse code conversion complete!\n");
    return 0;
}