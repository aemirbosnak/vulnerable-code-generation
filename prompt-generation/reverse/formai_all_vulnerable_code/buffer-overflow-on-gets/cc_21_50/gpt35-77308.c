//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// This function takes a character and returns the Morse Code equivalent
char * charToMorseCode(char ch) {
    switch(ch) {
        case 'A':
            return ".- ";
        case 'B':
            return "-... ";
        case 'C':
            return "-.-. ";
        case 'D':
            return "-.. ";
        case 'E':
            return ". ";
        case 'F':
            return "..-. ";
        case 'G':
            return "--. ";
        case 'H':
            return ".... ";
        case 'I':
            return ".. ";
        case 'J':
            return ".--- ";
        case 'K':
            return "-.- ";
        case 'L':
            return ".-.. ";
        case 'M':
            return "-- ";
        case 'N':
            return "-. ";
        case 'O':
            return "--- ";
        case 'P':
            return ".--. ";
        case 'Q':
            return "--.- ";
        case 'R':
            return ".-. ";
        case 'S':
            return "... ";
        case 'T':
            return "- ";
        case 'U':
            return "..- ";
        case 'V':
            return "...- ";
        case 'W':
            return ".-- ";
        case 'X':
            return "-..- ";
        case 'Y':
            return "-.-- ";
        case 'Z':
            return "--.. ";
        case '0':
            return "----- ";
        case '1':
            return ".---- ";
        case '2':
            return "..--- ";
        case '3':
            return "...-- ";
        case '4':
            return "....- ";
        case '5':
            return "..... ";
        case '6':
            return "-.... ";
        case '7':
            return "--... ";
        case '8':
            return "---.. ";
        case '9':
            return "----. ";
        case '.':
            return ".-.-.- ";
        case ',':
            return "--..-- ";
        case '?':
            return "..--.. ";
        case '\'':
            return ".----. ";
        case '!':
            return "-.-.-- ";
        case '/':
            return "-..-. ";
        case '(':
            return "-.--. ";
        case ')':
            return "-.--.- ";
        case '&':
            return ".-... ";
        case ':':
            return "---... ";
        case ';':
            return "-.-.-. ";
        case '=':
            return "-...- ";
        case '+':
            return ".-.-. ";
        case '-':
            return "-....- ";
        case '_':
            return "..--.- ";
        case '\"':
            return ".-..-. ";
        case '$':
            return "...-..- ";
        case '@':
            return ".--.-. ";
        default:
            return "";
    }
}

int main() {
    // Get the input string from user
    char str[100];
    printf("\nEnter the string to convert to Morse Code: ");
    gets(str);

    // Convert each character to Morse Code and store in the morseCode array
    char morseCode[1000];
    for(int i=0; i<strlen(str); i++) {
        char *morseChar = charToMorseCode(toupper(str[i]));
        strcat(morseCode, morseChar);
    }

    // Print the Morse code
    printf("\nMorse Code: ");
    printf("%s", morseCode);

    return 0;
}