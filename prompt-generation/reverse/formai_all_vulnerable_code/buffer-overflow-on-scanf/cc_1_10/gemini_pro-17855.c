//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_CHAR ' '
#define ALPHABET_SIZE 26
#define MORSE_CODE_SIZE 36

char *text_to_morse_code_table[ALPHABET_SIZE] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-", "---."
};

char *morse_code_to_text_table[MORSE_CODE_SIZE] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", SPACE_CHAR
};

char *text_to_morse_code(char *text) {
    int i, j;
    char *morse_code = malloc(strlen(text) * 5 + 1);
    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (text[i] == 'a' + j || text[i] == 'A' + j) {
                strcat(morse_code, text_to_morse_code_table[j]);
                strcat(morse_code, " ");
                break;
            }
            if (text[i] == SPACE_CHAR) {
                strcat(morse_code, " ");
                break;
            }
        }
    }
    return morse_code;
}

char *morse_code_to_text(char *morse_code) {
    int i, j;
    char *text = malloc(strlen(morse_code) + 1);
    char *token = strtok(morse_code, " ");
    while (token != NULL) {
        for (j = 0; j < MORSE_CODE_SIZE; j++) {
            if (strcmp(token, morse_code_to_text_table[j]) == 0) {
                strcat(text, morse_code_to_text_table[j]);
                break;
            }
            if (strcmp(token, " ") == 0) {
                strcat(text, " ");
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return text;
}

int main() {
    char *text, *morse_code;

    printf("Enter text to convert to Morse code: ");
    text = malloc(100);
    scanf("%s", text);

    morse_code = text_to_morse_code(text);
    printf("Morse code: %s\n", morse_code);

    text = morse_code_to_text(morse_code);
    printf("Text: %s\n", text);

    return 0;
}