//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dictionary of Morse code characters 
char *morseCodes[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--.."   // Z
};

int main()
{
    char inputStr[50];  // Initialization of Input string for Morse Conversion
    char morse[50];     // Initialization of Morse code string
    char *temp;         // Temporary pointer for Morse code string
    int i, j;           // Loop variables for Input and Morse codes
    int len;            // Length of input text string

    printf("Enter any text to convert it into Morse code:\n");
    fgets(inputStr, 50, stdin);   // Reading input text from user
    
    len = strlen(inputStr);       // Length calculation of input string
    
    // Removing newline from input string, if present
    if (inputStr[len-1] == '\n')
        inputStr[len-1] = '\0';
    
    // Conversion of input text to Morse code
    for (i = 0; i < len; i++) {
        // Space handling
        if (inputStr[i] == ' ') {
            strcat(morse, "   ");   // Three space strings for Morse code space
        }
        // Handling for only alphabets (A to Z)
        else if (inputStr[i] >= 'A' && inputStr[i] <= 'Z') {
            temp = morseCodes[inputStr[i] - 'A'];   // Conversion to Morse code
            strcat(morse, temp);
            strcat(morse, " ");   // Single space string between Morse code characters
        }
        // Handing for other than alphabets
        else {
            printf("Invalid Input string!\n");
            return -1;
        }
    }
    
    printf("\nMorse Code of %s is:\n%s\n", inputStr, morse);  // Displaying Morse code for input text

    return 0;
}