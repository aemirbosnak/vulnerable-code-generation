//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH_SHORT 0
#define LENGTH_LONG  1

const char morse[][5] = {
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
    "--..", // Y
    "-----"  // Z
};

void convert(const char *input, int length) {
    int i, j;

    for (i = 0; i < length; i++) {
        char c = toupper(input[i]);

        if (c >= 'A' && c <= 'Z') {
            for (j = 0; j < 26; j++) {
                if (strcmp(morse[j], &input[i]) == 0) {
                    printf("%s ", morse[j]);
                    break;
                }
            }
        } else if (c == ' ') {
            printf("-- "); // Space
        }
    }

    printf("\n");
}

int main() {
    char input[100];

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    input[strlen(input) - 1] = '\0'; // Remove newline character

    convert(input, strlen(input));

    return 0;
}