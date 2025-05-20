//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
/***************************************************************
* Author: [Your name here]
* Email: [Your email here]
* Date: [Date of creation]
*
* Description: This program takes a user input message in text
* and converts it into Morse code using the International Morse
* Code standard. This program only supports uppercase letters,
* numbers, and basic punctuation marks.
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the Morse Code equivalents for each character
const char* letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
const char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
const char* punctuation[] = {".-.-.-", "--..--", "..--..", "-.-.--", "-..-.", "-.--.", "-....-", "..--.-", ".-..-.", ".----.", "-.--.-"};

// function to convert a single character to Morse Code
const char* convert_char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return letters[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return numbers[c - '0'];
    } else {
        switch(c) {
            case '.':
                return punctuation[0];
            case ',':
                return punctuation[1];
            case '?':
                return punctuation[2];
            case '!':
                return punctuation[3];
            case '/':
                return punctuation[4];
            case '(':
                return punctuation[5];
            case ')':
                return punctuation[6];
            case '&':
                return punctuation[7];
            case ':':
                return punctuation[8];
            case ';':
                return punctuation[9];
            case '=':
                return punctuation[10];
            case '+':
                return punctuation[11];
            case '-':
                return punctuation[12];
            case '_':
                return punctuation[13];
            case '\"':
                return punctuation[14];
            case '$':
                return punctuation[15];
            default:
                return "";
        }
    }
}

int main() {
    // define variables
    char message[200];
    char morse[400];
    int i, j;
    
    // get input from user
    printf("Enter a message to convert to Morse code: ");
    fgets(message, sizeof(message), stdin);
    
    // loop through each character in the message
    for (i = 0, j = 0; i < strlen(message); i++) {
        // get the Morse Code equivalent for the character
        const char* code = convert_char_to_morse(message[i]);
        // if the character is supported, add the Morse Code to the output
        if (strcmp(code, "") != 0) {
            strcat(morse, code);
            strcat(morse, " ");
            j += strlen(code) + 1;
        }
    }
    
    // print the Morse Code output
    printf("Morse code: %s\n", morse);
    
    return 0;
}