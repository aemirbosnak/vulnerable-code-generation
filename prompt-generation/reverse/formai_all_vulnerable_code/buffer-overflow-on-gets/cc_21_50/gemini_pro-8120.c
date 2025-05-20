//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character set
char *morse_codes[] = {
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
    "--..",  // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    " ",     // Space
};

// Character to Morse code conversion function
char *to_morse(char character) {
    switch (character) {
        case 'A':
        case 'a':
            return morse_codes[0];
        case 'B':
        case 'b':
            return morse_codes[1];
        case 'C':
        case 'c':
            return morse_codes[2];
        case 'D':
        case 'd':
            return morse_codes[3];
        case 'E':
        case 'e':
            return morse_codes[4];
        case 'F':
        case 'f':
            return morse_codes[5];
        case 'G':
        case 'g':
            return morse_codes[6];
        case 'H':
        case 'h':
            return morse_codes[7];
        case 'I':
        case 'i':
            return morse_codes[8];
        case 'J':
        case 'j':
            return morse_codes[9];
        case 'K':
        case 'k':
            return morse_codes[10];
        case 'L':
        case 'l':
            return morse_codes[11];
        case 'M':
        case 'm':
            return morse_codes[12];
        case 'N':
        case 'n':
            return morse_codes[13];
        case 'O':
        case 'o':
            return morse_codes[14];
        case 'P':
        case 'p':
            return morse_codes[15];
        case 'Q':
        case 'q':
            return morse_codes[16];
        case 'R':
        case 'r':
            return morse_codes[17];
        case 'S':
        case 's':
            return morse_codes[18];
        case 'T':
        case 't':
            return morse_codes[19];
        case 'U':
        case 'u':
            return morse_codes[20];
        case 'V':
        case 'v':
            return morse_codes[21];
        case 'W':
        case 'w':
            return morse_codes[22];
        case 'X':
        case 'x':
            return morse_codes[23];
        case 'Y':
        case 'y':
            return morse_codes[24];
        case 'Z':
        case 'z':
            return morse_codes[25];
        case '0':
            return morse_codes[26];
        case '1':
            return morse_codes[27];
        case '2':
            return morse_codes[28];
        case '3':
            return morse_codes[29];
        case '4':
            return morse_codes[30];
        case '5':
            return morse_codes[31];
        case '6':
            return morse_codes[32];
        case '7':
            return morse_codes[33];
        case '8':
            return morse_codes[34];
        case '9':
            return morse_codes[35];
        case ' ':
            return morse_codes[36];
        default:
            return "";
    }
}

// Main function
int main() {
    // Get the input text
    char input_text[100];
    printf("Enter the text to convert to Morse code: ");
    gets(input_text);

    // Convert the text to Morse code
    char *morse_code[100];
    int i = 0;
    while (input_text[i] != '\0') {
        morse_code[i] = to_morse(input_text[i]);
        i++;
    }

    // Print the Morse code
    printf("The Morse code is: ");
    for (i = 0; i < strlen(input_text); i++) {
        printf("%s ", morse_code[i]);
    }

    printf("\n");

    return 0;
}