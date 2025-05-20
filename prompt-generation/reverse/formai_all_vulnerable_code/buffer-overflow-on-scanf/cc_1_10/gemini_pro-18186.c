//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include <stdio.h>
#include <ctype.h>

#define MAX_TEXT_LEN 256
#define MAX_MORSE_LEN 1024

// Morse code representation of the English alphabet
static const char *MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Morse code representation of the digits
static const char *MORSE_DIGITS[] = {
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

// Function to convert a character to its Morse code representation
static char *char_to_morse(char c) {
    if (isalpha(c)) {
        return MORSE_CODE[toupper(c) - 'A'];
    } else if (isdigit(c)) {
        return MORSE_DIGITS[c - '0'];
    } else {
        return NULL;
    }
}

// Function to convert a string to its Morse code representation
static char *text_to_morse(char *text) {
    char *morse_code = malloc(MAX_MORSE_LEN);
    if (morse_code == NULL) {
        return NULL;
    }

    int i = 0;
    int j = 0;
    while (text[i] != '\0') {
        char *morse_char = char_to_morse(text[i]);
        if (morse_char != NULL) {
            strcpy(&morse_code[j], morse_char);
            j += strlen(morse_char);
            morse_code[j++] = ' ';
        }
        i++;
    }
    morse_code[j] = '\0';

    return morse_code;
}

int main() {
    char text[MAX_TEXT_LEN];

    printf("Enter text to convert to Morse code: ");
    scanf("%s", text);

    char *morse_code = text_to_morse(text);
    if (morse_code == NULL) {
        printf("Error: Out of memory.\n");
        return 1;
    }

    printf("Morse code: %s\n", morse_code);

    free(morse_code);

    return 0;
}