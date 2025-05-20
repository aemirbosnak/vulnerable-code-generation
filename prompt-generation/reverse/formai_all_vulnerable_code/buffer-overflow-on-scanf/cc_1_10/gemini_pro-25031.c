//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MORSECODE_MAX_WORD_LEN 20
#define MORSECODE_MAX_LETTER_LEN 10

typedef struct {
    char letter;
    char morse_code[MORSECODE_MAX_LETTER_LEN];
} morse_code_mapping;

morse_code_mapping morse_code_table[26] = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."}
};

int main(int argc, char *argv[]) {
    char text[MORSECODE_MAX_WORD_LEN];
    char morse_code[MORSECODE_MAX_WORD_LEN * MORSECODE_MAX_LETTER_LEN];

    printf("Enter a word (uppercase letters only): ");
    scanf("%s", text);

    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++) {
        char letter = text[i];
        for (int j = 0; j < 26; j++) {
            if (letter == morse_code_table[j].letter) {
                strcat(morse_code, morse_code_table[j].morse_code);
            }
        }
    }

    printf("Morse code: %s\n", morse_code);

    return 0;
}