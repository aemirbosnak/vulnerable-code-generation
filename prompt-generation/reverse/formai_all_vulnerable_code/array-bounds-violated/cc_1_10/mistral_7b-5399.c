//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOT 0
#define DASH 1
#define SPACE 2
#define LETTERS_COUNT 26

char morse_codes[LETTERS_COUNT][3] = {
    {'.', '.'}, {'.', '-'}, {'-', '.'}, {'-', '-'},
    {'-', '.'}, {'-', '-'}, {'.', '.'}, {' ', ' '},
    {'...', '.'}, {'..', '.'}, {'...', '-'}, {'..', '-'},
    {'....', '.'}, {'.....', '.'}, {'-.', '.'}, {'-.', '-'},
    {'---', '.'}, {'----', '.'}, {'----', '-'}, {'---', '-'},
};

void print_morse_code(char letter) {
    int index = letter - 'A';
    if (index < 0 || index >= LETTERS_COUNT) {
        if (letter == ' ') {
            printf(" %c ", SPACE);
        } else {
            printf(" Unknown character: %c\n", letter);
            return;
        }
    }
    int i;
    for (i = 0; i < 3; i++) {
        if (morse_codes[index][i] == DOT) {
            printf(" . ");
        } else if (morse_codes[index][i] == DASH) {
            printf("- ");
        }
    }
    printf(" ");
}

void convert_text_to_morse_code(char* text) {
    int i, j;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            printf(" %c ", SPACE);
            continue;
        }
        print_morse_code(text[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text to be converted to morse code>\n", argv[0]);
        return 1;
    }
    convert_text_to_morse_code(argv[1]);
    return 0;
}