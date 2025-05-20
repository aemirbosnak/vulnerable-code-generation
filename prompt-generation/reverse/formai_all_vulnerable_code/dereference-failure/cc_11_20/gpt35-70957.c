//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <string.h>

char* letter_to_morse(char letter) {
    switch (letter) {
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
        case '0':
            return "-----";
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
        default:
            return "";
    }
}

char* text_to_morse(char* text) {
    char* morse = "";
    for (int i=0; i<strlen(text); i++) {
        if (text[i] == ' ') { // if space, add a slash
            morse = strcat(morse, "/");
        } else {
            char* letter_morse = letter_to_morse(text[i]);
            if (strlen(letter_morse) == 0) { // if not valid, ignore
                continue;
            }
            morse = strcat(morse, letter_morse);
        }
        morse = strcat(morse, " "); // add space between letters
    }
    return morse;
}

int main() {
    char text[100] = "HELLO WORLD";
    char* morse = text_to_morse(text);
    printf("%s\n", morse);
    return 0;
}