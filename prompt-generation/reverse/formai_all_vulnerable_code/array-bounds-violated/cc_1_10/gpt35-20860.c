//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToMorseCode(char*, char*);
void printMorseCode(char*);

int main() {
    char text[100];
    char morseCode[500];

    printf("Enter text to convert to Morse Code: ");
    fgets(text, 100, stdin);

    // Remove newline character from input
    if (text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }

    convertToMorseCode(text, morseCode);

    printf("Morse Code: ");
    printMorseCode(morseCode);

    return 0;
}

void convertToMorseCode(char* text, char* morseCode) {
    char morse[26][5] = {
        {".-"},   // a
        {"-..."}, // b
        {"-.-."}, // c
        {"-.."},  // d
        {"."},    // e
        {"..-."}, // f
        {"--."},  // g
        {"...."}, // h
        {".."},   // i
        {".---"}, // j
        {"-.-"},  // k
        {".-.."}, // l
        {"--"},   // m
        {"-."},   // n
        {"---"},  // o
        {".--."}, // p
        {"--.-"}, // q
        {".-."},  // r
        {"..."},  // s
        {"-"},    // t
        {"..-"},  // u
        {"...-"}, // v
        {".--"},  // w
        {"-..-"}, // x
        {"-.--"}, // y
        {"--.."}  // z
    };

    int i, len;
    len = strlen(text);

    for (i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            strcat(morseCode, morse[tolower(text[i]) - 97]);
            strcat(morseCode, " ");
        } else if (text[i] == ' ') {
            strcat(morseCode, "/ ");
        }
    }
}

void printMorseCode(char* morseCode) {
    int i, len;
    len = strlen(morseCode);

    for (i = 0; i < len; i++) {
        if (morseCode[i] == '.') {
            printf(".");
        } else if (morseCode[i] == '-') {
            printf("-");
        } else if (morseCode[i] == '/') {
            printf("/ ");
        } else {
            // This code should never be reached
            printf("ERROR: Unknown character in Morse Code\n");
            printf("CALLING SECURITY TO REPORT PARANOID ACT\n");
            // insert your paranoid actions here...
        }
    }
}