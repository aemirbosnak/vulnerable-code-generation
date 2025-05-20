//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 1000
#define MAX_MORSE_LEN 5000

char* textToMorse(char input[MAX_INPUT_LEN+1])
{
    char* morse = malloc(MAX_MORSE_LEN+1);
    memset(morse, 0, MAX_MORSE_LEN+1);

    char* morseChars[36] = {
        ".-",    "-...",  "-.-.",  "-..",   ".",    
        "..-.",  "--.",   "....",  "..",    ".---", 
        "-.-",   ".-..",  "--",    "-.",    "---",  
        ".--.",  "--.-",  ".-.",   "...",   "-",    
        "..-",   "...-",  ".--",   "-..-",  "-.--", 
        "--..",  ".----", "..---", "...--", "....-", 
        ".....", "-....", "--...", "---..", "----.", 
        "-----"
    };

    int morseIndex = 0;
    int i;
    for (i = 0; i < strlen(input); i++) {
        char c = input[i];
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            int charIndex;
            if (c >= '0' && c <= '9') {
                charIndex = c - '0' + 26;
            } else if (c >= 'A' && c <= 'Z') {
                charIndex = c - 'A';
            } else {
                charIndex = c - 'a';
            }
            char* morseChar = morseChars[charIndex];
            int j;
            for (j = 0; j < strlen(morseChar); j++) {
                morse[morseIndex++] = morseChar[j];
                if (j < strlen(morseChar) - 1) {
                    morse[morseIndex++] = ' ';
                }
            }
            if (i < strlen(input) - 1) {
                morse[morseIndex++] = ' ';
            }
        }
    }

    return morse;
}

int main(void)
{
    printf("Enter text to convert to Morse code: ");
    char input[MAX_INPUT_LEN+1];
    fgets(input, MAX_INPUT_LEN+1, stdin);
    input[strlen(input)-1] = '\0'; // Remove newline character

    char* morse = textToMorse(input);

    printf("Morse code: %s\n", morse);

    free(morse);

    return 0;
}