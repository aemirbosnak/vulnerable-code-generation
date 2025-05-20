//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: visionary
/*
 * Text to Morse code conversion program
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <string.h>

#define LENGTH 80 // Maximum length of the input string
#define MAX_MORSE_LEN 100 // Maximum length of the Morse code string

// Function to convert a character to Morse code
char* to_morse(char ch) {
    switch (ch) {
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
        default: return " "; // Return space for any other character
    }
}

// Function to convert a string to Morse code
void to_morse_code(char* str, char* morse) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++, j++) {
        morse[j] = to_morse(str[i]);
    }
    morse[j] = '\0';
}

int main() {
    char str[LENGTH], morse[MAX_MORSE_LEN];
    printf("Enter a string: ");
    scanf("%s", str);
    to_morse_code(str, morse);
    printf("Morse code: %s\n", morse);
    return 0;
}