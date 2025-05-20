//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toMorse(char* text) {
    char* morse = (char*) malloc(strlen(text) * 5);
    char* morsePtr = morse;

    while (*text) {
        switch (toupper(*text)) {
            case 'A': strcpy(morsePtr, ".- "); break;
            case 'B': strcpy(morsePtr, "-... "); break;
            case 'C': strcpy(morsePtr, "-.-. "); break;
            case 'D': strcpy(morsePtr, "-.. "); break;
            case 'E': strcpy(morsePtr, ". "); break;
            case 'F': strcpy(morsePtr, "..-. "); break;
            case 'G': strcpy(morsePtr, "--. "); break;
            case 'H': strcpy(morsePtr, ".... "); break;
            case 'I': strcpy(morsePtr, ".. "); break;
            case 'J': strcpy(morsePtr, ".--- "); break;
            case 'K': strcpy(morsePtr, "-.- "); break;
            case 'L': strcpy(morsePtr, ".-.. "); break;
            case 'M': strcpy(morsePtr, "-- "); break;
            case 'N': strcpy(morsePtr, "-. "); break;
            case 'O': strcpy(morsePtr, "--- "); break;
            case 'P': strcpy(morsePtr, ".--. "); break;
            case 'Q': strcpy(morsePtr, "--.- "); break;
            case 'R': strcpy(morsePtr, ".-. "); break;
            case 'S': strcpy(morsePtr, "... "); break;
            case 'T': strcpy(morsePtr, "- "); break;
            case 'U': strcpy(morsePtr, "..- "); break;
            case 'V': strcpy(morsePtr, "...- "); break;
            case 'W': strcpy(morsePtr, ".-- "); break;
            case 'X': strcpy(morsePtr, "-..- "); break;
            case 'Y': strcpy(morsePtr, "-.-- "); break;
            case 'Z': strcpy(morsePtr, "--.. "); break;
            case ' ': strcpy(morsePtr, "/ "); break;
            default: *morsePtr = '\0'; break;
        }

        morsePtr += strlen(morsePtr);
        text++;
    }

    return morse;
}

int main() {
    char* text = "Hello, World!";
    char* morse = toMorse(text);

    printf("Text: %s\nMorse: %s\n", text, morse);

    free(morse);

    return 0;
}