//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DASH      "-"
#define DOT       "."
#define SPACE     " "
#define MORSE_LEN 26

const char *morse = ".-,-....,.....,....-,....-,....-,.....,....-,....-,---.,--.-,--.,--..";

void print_morse(const char *morse_code) {
    int i;
    for (i = 0; i < strlen(morse_code); i++) {
        printf("%c", morse_code[i]);
        if (i < strlen(morse_code) - 1 && morse[morse_code[i + 1] - 'A'] != morse[morse_code[i] - 'A'])
            printf(SPACE);
    }
}

int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    scanf("%s", text);

    // Convert text to uppercase
    for (int i = 0; text[i]; i++) {
        text[i] = toupper(text[i]);
    }

    // Convert text to Morse code
    for (int i = 0; text[i]; i++) {
        int index = text[i] - 'A';
        if (index >= 0 && index < MORSE_LEN) {
            print_morse(morse + index * MORSE_LEN);
            printf(SPACE);
        } else {
            switch (text[i]) {
                case ' ':
                    printf(SPACE);
                    break;
                case '.':
                    printf(DOT);
                    break;
                case '_':
                    printf(DASH);
                    printf(DASH);
                    break;
                case '-':
                    printf(DASH);
                    break;
                default:
                    printf("Invalid character: %c", text[i]);
            }
            printf(SPACE);
        }
    }

    printf("\n");

    return 0;
}