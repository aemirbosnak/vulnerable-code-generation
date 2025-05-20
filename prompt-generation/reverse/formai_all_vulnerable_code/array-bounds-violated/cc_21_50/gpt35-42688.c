//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: statistical
#include <stdio.h>
#include <string.h>

char* convertToMorse(char character);

int main() {
    char input[101];    /* Maximum input length of 100 characters */
    int length, i, j;
    char morse[101][20];    /* Maximum Morse code length of 20 dots and dashes */
    
    printf("Enter text to convert to Morse code:\n");
    fgets(input, sizeof(input), stdin);    /* Read user input */
    
    length = strlen(input);    /* Get length of input */
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';    /* Remove newline character from input */
        length--;
    }
    
    for (i = 0; i < length; i++) {
        morse[i][0] = '\0';    /* Initialize Morse code array */
        if (input[i] == ' ') {
            /* Add space to Morse code array if input is a space */
            strcpy(morse[i], " ");
        } else {
            /* Convert character to Morse code and add to Morse code array */
            char* code = convertToMorse(input[i]);
            strcpy(morse[i], code);
        }
    }
    
    /* Print input and Morse code in table format */
    printf("%-10s%s\n", "Input", "Morse Code");
    for (i = 0; i < length; i++) {
        printf("%-10c%s\n", input[i], morse[i]);
    }
    
    return 0;
}

/* Convert character to Morse code */
char* convertToMorse(char character) {
    switch (character) {
        case 'a':
        case 'A':
            return ".-";
        case 'b':
        case 'B':
            return "-...";
        case 'c':
        case 'C':
            return "-.-.";
        case 'd':
        case 'D':
            return "-..";
        case 'e':
        case 'E':
            return ".";
        case 'f':
        case 'F':
            return "..-.";
        case 'g':
        case 'G':
            return "--.";
        case 'h':
        case 'H':
            return "....";
        case 'i':
        case 'I':
            return "..";
        case 'j':
        case 'J':
            return ".---";
        case 'k':
        case 'K':
            return "-.-";
        case 'l':
        case 'L':
            return ".-..";
        case 'm':
        case 'M':
            return "--";
        case 'n':
        case 'N':
            return "-.";
        case 'o':
        case 'O':
            return "---";
        case 'p':
        case 'P':
            return ".--.";
        case 'q':
        case 'Q':
            return "--.-";
        case 'r':
        case 'R':
            return ".-.";
        case 's':
        case 'S':
            return "...";
        case 't':
        case 'T':
            return "-";
        case 'u':
        case 'U':
            return "..-";
        case 'v':
        case 'V':
            return "...-";
        case 'w':
        case 'W':
            return ".--";
        case 'x':
        case 'X':
            return "-..-";
        case 'y':
        case 'Y':
            return "-.--";
        case 'z':
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