//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
/* 
 * This program converts a text input into Morse code.
 * The code was developed in honor of Ada Lovelace, a pioneering computer programmer.
 * 
 * To use the program, simply enter a text input. 
 * Any non-alphanumeric characters will be skipped and not converted.
 * 
 * Happy coding!
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

char* convert(char c);

int main() {
    char input[MAX_LENGTH]; // the text input
    char output[MAX_LENGTH * 5]; // the Morse code output (estimate length to prevent buffer overflow)

    printf("Enter text to be converted to Morse code:\n");
    fgets(input, MAX_LENGTH, stdin); // read user input

    int index = 0; // index to keep track of output string
    for (int i = 0; i < strlen(input); i++) {
        char c = toupper(input[i]); // convert to uppercase for simplicity
        if (isalnum(c)) { // only convert alphanumeric characters
            char* code = convert(c); // get Morse code for the character
            for (int j = 0; j < strlen(code); j++) {
                output[index++] = code[j]; // add Morse code to output
            }
            output[index++] = ' '; // add space between each character
        }
    }
    output[index] = '\0'; // add null character to end of string

    printf("Morse code:\n");
    printf("%s\n", output); // print Morse code

    return 0;
}

// Morse code conversion function
char* convert(char c) {
    static char* code[] = {
        ".-", "-...", "-.-.", "-..", ".", // A-E
        "..-.", "--.", "....", "..", ".---", // F-J
        "-.-", ".-..", "--", "-.", "---", // K-O
        ".--.", "--.-", ".-.", "...", "-", // P-T
        "..-", "...-", ".--", "-..-", "-.--", // U-Y
        "--.." // Z
    };
    int index = c - 'A'; // get index of character in code array
    return code[index]; // return Morse code
}