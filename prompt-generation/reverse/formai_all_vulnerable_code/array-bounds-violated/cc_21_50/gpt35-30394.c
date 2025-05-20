//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function to convert character to morse code
char* charToMorse(char c) {
    switch (c) {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return NULL;
    }
}

int main() {
    // get the input text from user
    char text[1000];
    printf("Enter the text you want to convert to morse code:\n");
    fgets(text, 1000, stdin);

    // remove newline character from the input
    int len = strlen(text);
    if(text[len-1] == '\n') {
        text[len-1] = '\0';
    }

    // convert the text to morse code
    char morse[10000];
    int pointer = 0;
    for (int i=0; i<len; i++) {
        char* code = charToMorse(text[i]);
        if (code == NULL) {
            printf("Invalid input");
            return 0;
        }
        int codeLength = strlen(code);
        for (int j=0; j<codeLength; j++) {
            morse[pointer++] = code[j];
        }
        morse[pointer++] = ' ';
    }
    morse[pointer-1] = '\0';

    printf("Morse code of the input text:\n%s\n", morse);
    return 0;
}