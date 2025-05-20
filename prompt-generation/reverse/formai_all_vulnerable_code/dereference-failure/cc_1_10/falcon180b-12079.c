//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_INPUT_SIZE 1000
#define MAX_MORSE_CODE_SIZE 10000
#define MORSE_CODE_DELIMITER " "

// Morse code lookup table
char *morse_code_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s [text]\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int text_length = strlen(text);

    if (text_length > MAX_INPUT_SIZE) {
        printf("Input text is too long.\n");
        return 1;
    }

    char *morse_code = malloc(MAX_MORSE_CODE_SIZE * sizeof(char));
    if (morse_code == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int morse_code_length = 0;
    char *word = strtok(text, " ");
    while (word!= NULL) {
        int word_length = strlen(word);
        char *morse_word = malloc(word_length * sizeof(char));
        if (morse_word == NULL) {
            printf("Memory allocation failed.\n");
            free(morse_code);
            return 1;
        }

        int morse_word_length = 0;
        char *letter = strtok(word, "");
        while (letter!= NULL) {
            if (isalpha(letter[0])) {
                int letter_index = tolower(letter[0]) - 'a';
                if (letter_index >= 0 && letter_index < 26) {
                    strcat(morse_word, morse_code_table[letter_index]);
                    morse_word_length += strlen(morse_code_table[letter_index]);
                }
            }
            letter = strtok(NULL, "");
        }

        strcat(morse_code, morse_word);
        morse_code_length += morse_word_length;
        free(morse_word);
        word = strtok(NULL, " ");
    }

    printf("%s\n", morse_code);
    free(morse_code);

    return 0;
}