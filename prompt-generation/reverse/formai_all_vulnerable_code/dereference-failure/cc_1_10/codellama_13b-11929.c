//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
/*
 * Text to Morse code converter
 *
 * This program takes a string of text as input and converts it to Morse code.
 *
 * Example usage:
 *
 *   $ ./text_to_morse "Hello, World!"
 *   -.- ..- -- ..- -- ..-
 */

#include <stdio.h>
#include <string.h>

#define MORSE_CODE_LETTER_SPACE ' '
#define MORSE_CODE_WORD_SPACE    '|'

// Morse code mapping
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|"
};

// Function to convert a letter to Morse code
char *letter_to_morse(char letter) {
    int index = letter - 'A';
    if (index < 0 || index >= sizeof(morse_code) / sizeof(morse_code[0])) {
        return NULL;
    }
    return morse_code[index];
}

// Function to convert a word to Morse code
char *word_to_morse(char *word) {
    char *morse = malloc(sizeof(char) * strlen(word));
    char *p = morse;
    for (int i = 0; i < strlen(word); i++) {
        char *letter_morse = letter_to_morse(word[i]);
        if (letter_morse != NULL) {
            strcpy(p, letter_morse);
            p += strlen(letter_morse);
        }
        if (i != strlen(word) - 1) {
            *p++ = MORSE_CODE_LETTER_SPACE;
        }
    }
    *p = '\0';
    return morse;
}

// Function to convert a sentence to Morse code
char *sentence_to_morse(char *sentence) {
    char *morse = malloc(sizeof(char) * strlen(sentence));
    char *p = morse;
    for (int i = 0; i < strlen(sentence); i++) {
        char *word_morse = word_to_morse(sentence[i]);
        if (word_morse != NULL) {
            strcpy(p, word_morse);
            p += strlen(word_morse);
        }
        if (i != strlen(sentence) - 1) {
            *p++ = MORSE_CODE_WORD_SPACE;
        }
    }
    *p = '\0';
    return morse;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }
    char *morse = sentence_to_morse(argv[1]);
    printf("%s\n", morse);
    free(morse);
    return 0;
}