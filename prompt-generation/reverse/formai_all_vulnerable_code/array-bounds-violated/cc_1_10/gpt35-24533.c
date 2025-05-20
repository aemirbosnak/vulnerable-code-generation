//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

char *morse_lookup_table[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--.."   // Z
};

int main()
{
    char input[MAX_LENGTH] = { 0 }, morse[MAX_LENGTH] = { 0 };
    printf("Enter a message to convert to Morse code: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strlen(input) - 1] = '\0';

    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            strcat(morse, morse_lookup_table[toupper(input[i]) - 'A']);
            strcat(morse, " ");
        } else if (input[i] == ' ') {
            strcat(morse, "/ ");
        } else {
            continue;
        }
    }

    printf("Morse code: %s\n", morse);
    return 0;
}