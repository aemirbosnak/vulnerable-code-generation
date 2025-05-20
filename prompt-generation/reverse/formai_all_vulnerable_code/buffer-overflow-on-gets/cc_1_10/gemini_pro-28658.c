//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include <stdio.h>
#include <string.h>

// Morse code dictionary
char *morse_code[] = {
    ".-",     // A
    "-...",   // B
    "-.-.",   // C
    "-..",    // D
    ".",      // E
    "..-.",   // F
    "--.",    // G
    "....",   // H
    "..",     // I
    ".---",   // J
    "-.-",    // K
    ".-.." ,  // L
    "--",     // M
    "-.",     // N
    "---",    // O
    ".--.",   // P
    "--.-",   // Q
    ".-.",    // R
    "...",    // S
    "-",      // T
    "..-",   // U
    "...-",   // V
    ".--",    // W
    "-..-",   // X
    "-.--",   // Y
    "--..",   // Z
    "-----",  // 0
    ".----",  // 1
    "..---",  // 2
    "...--",  // 3
    "....-",  // 4
    ".....",  // 5
    "-....",  // 6
    "--...",  // 7
    "---..",  // 8
    "----.",  // 9
    "-.--.-", // !
    ".-..-.", // "
    "--..--", // #
    "....-.", // $
    ".----.", // %
    "-..-.-", // &
    ".--.-.", // '
    "-....-", // (
    "-.-.--", // )
    "-..--",  // *
    ".--.",   // +
    ",,--,",   // ,
    "--..--", // -
    "....--", // .
    "-..-.",  // /
    ".-...",  // :
    "-...-",  // ;
    "--.-.-", // ?
    "--.--.", // @
    "---...", // A (prosign)
    "--..--", // B (prosign)
    "...---", // C (prosign)
    "...--.-", // CH (prosign)
    "-.-.--.", // FR (prosign)
    "--...--", // GA (prosign)
    "....---", // K (prosign)
    "--.-.--", // NY (prosign)
    "-.-.--.", // SK (prosign)
    "-...---", // VA (prosign)
    ".-....-", // VE (prosign)
    "-.--.--", // W (prosign)
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else {
        // Not a valid character
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5); // Allocate enough memory for the Morse code
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        strcat(morse_code, morse);
        strcat(morse_code, " "); // Add a space between each character
        index += strlen(morse) + 1;
    }
    return morse_code;
}

int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    gets(str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code to the console
    printf("Morse code: %s\n", morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}