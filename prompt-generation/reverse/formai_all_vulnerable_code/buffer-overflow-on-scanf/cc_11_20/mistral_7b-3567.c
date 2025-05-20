//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DASH  "-"
#define DOT "."
#define SPACE "/"
#define SHORT_SIGNAL "."
#define LONG_SIGNAL "-"
#define ELEMENT_GAP " "
#define WORD_GAP "/"

// Converts English Alphabet characters to Morse code
char *english_to_morse(char c) {
    switch (c) {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        case '0': return "-----";
        default: return "";
    }
}

// Converts a string to Morse code
void string_to_morse(char *input, char *output) {
    int i, j;
    char *signal;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            strcat(output, WORD_GAP);
            continue;
        }

        signal = english_to_morse(input[i]);
        strcat(output, signal);
        strcat(output, ELEMENT_GAP);
    }
}

int main(int argc, char *argv[]) {
    char input[101], output[1001] = "";

    printf("Enter text to convert to Morse code: ");
    scanf("%s", input);

    string_to_morse(input, output);

    printf("\nMorse code:\n%s\n", output);

    return 0;
}