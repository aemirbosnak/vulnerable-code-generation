//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH 1024
#define DASH 0
#define DOT 1

// Morse code for all English alphabets, numbers and special characters
const char morse_code[][13] = {
    ".-",           // A
    "-...",         // B
    "-.-.",         // C
    "-..",          // D
    ".",            // E
    "..-.",         // F
    "--.",           // G
    "....",          // H
    "..",           // I
    ".---",         // J
    "-.-",          // K
    ".-..",         // L
    "--",           // M
    "-.",           // N
    "---",          // O
    ".--.",         // P
    "--.-",         // Q
    ".-.",          // R
    "...",          // S
    "-",            // T
    "..-",          // U
    "...-",         // V
    ".--",          // W
    "-..-",         // X
    "--..",         // Y
    "-----",         // Z
    ".----",        // 1
    "..---",        // 2
    "...--",        // 3
    "....-",        // 4
    ".....",        // 5
    "-....",        // 6
    "--...",        // 7
    "---..",        // 8
    "----.",        // 9
    "-----.",       // 0
    ".---..",       // SOS
};

void decode_morse(int *signal, int length) {
    int i = 0, j = 0;
    char letter;

    while (i < length) {
        if (signal[i] == DOT) {
            if (signal[i + 1] == DASH || (i + 2 >= length)) {
                letter = morse_code[j][i % 13];
                j++;
                i++;
                if (morse_code[j][0] == 0) {
                    printf("%c ", letter);
                    j = 0;
                }
            }
        }
        i++;
    }
    printf("\n");
}

int main() {
    int signal[LENGTH];

    printf("Enter Morse code signal (1 for dot, 0 for dash):\n");

    for (int i = 0; i < LENGTH; i++) {
        scanf("%d", &signal[i]);
    }

    decode_morse(signal, LENGTH);

    return 0;
}