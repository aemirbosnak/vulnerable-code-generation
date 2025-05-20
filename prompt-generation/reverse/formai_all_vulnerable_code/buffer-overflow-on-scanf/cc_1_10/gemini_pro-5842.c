//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Morse code table */
char *morse_table[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    " ",     // space
};

/* Convert a character to Morse code */
char *char_to_morse(char c) {
    int i;

    for (i = 0; i < 26; i++) {
        if (c == 'a' + i || c == 'A' + i) {
            return morse_table[i];
        }
    }

    for (i = 0; i < 10; i++) {
        if (c == '0' + i) {
            return morse_table[26 + i];
        }
    }

    return " "; // space
}

/* Convert a string to Morse code */
char *string_to_morse(char *s) {
    int i, len;
    char *morse;

    len = strlen(s);
    morse = malloc(len * 5 + 1); // 5 dots/dashes per character + 1 for null-terminator

    for (i = 0; i < len; i++) {
        strcat(morse, char_to_morse(s[i]));
    }

    return morse;
}

/* Print a string in Morse code */
void print_morse(char *s) {
    int i, len;

    len = strlen(s);

    for (i = 0; i < len; i++) {
        if (s[i] == '.') {
            printf("· ");
        } else if (s[i] == '-') {
            printf("- ");
        } else {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    char *text, *morse;

    printf("Enter a string to convert to Morse code: ");
    text = malloc(100);
    scanf("%s", text);

    morse = string_to_morse(text);

    printf("Morse code: ");
    print_morse(morse);

    free(text);
    free(morse);

    return 0;
}