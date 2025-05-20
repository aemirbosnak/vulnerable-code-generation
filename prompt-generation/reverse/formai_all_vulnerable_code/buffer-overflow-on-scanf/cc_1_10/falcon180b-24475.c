//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_CODE_LENGTH 10

char morse_code[MAX_CODE_LENGTH];

void convert_text_to_morse_code(char *text, int length) {
    if(length == 0) {
        printf(" ");
        return;
    }

    char *word = malloc(MAX_WORD_LENGTH * sizeof(char));
    strncpy(word, text, length);
    word[length] = '\0';

    if(isalpha(word[0])) {
        printf("%s ", morse_code);
        convert_text_to_morse_code(text + length, strlen(text) - length);
    } else {
        printf(" ");
        convert_text_to_morse_code(text + length, strlen(text) - length);
    }

    free(word);
}

int main() {
    morse_code[0] = '.';
    morse_code[1] = '-';
    morse_code[2] = '.';
    morse_code[3] = '-';
    morse_code[4] = '.';
    morse_code[5] = '-';
    morse_code[6] = '.';
    morse_code[7] = '-';
    morse_code[8] = '.';
    morse_code[9] = '-';

    char text[MAX_WORD_LENGTH];
    printf("Enter a text to convert to Morse code: ");
    scanf("%s", text);

    convert_text_to_morse_code(text, strlen(text));

    return 0;
}