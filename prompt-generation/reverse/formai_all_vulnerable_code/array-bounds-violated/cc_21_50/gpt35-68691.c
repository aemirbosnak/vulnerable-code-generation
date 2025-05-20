//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *morse_code(char c) {
    switch (toupper(c)) {
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        case '0':
            return "-----";
        default:
            return "";
    }
}

int main() {
    char message[100], morse[500], c;
    int i, j, len;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    len = strlen(message);
    message[len - 1] = '\0';

    for (i = 0, j = 0; i < len; i++) {
        c = message[i];
        if (isalpha(c) || isdigit(c)) {
            char *code = morse_code(c);
            if (strlen(code) > 0) {
                if (j > 0) {
                    morse[j++] = ' ';
                }
                strcat(morse, code);
                j += strlen(code);
            }
        }
    }

    printf("Morse code: %s\n", morse);

    return 0;
}