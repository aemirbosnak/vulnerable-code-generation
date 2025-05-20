//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Define Morse code conversion table
char morse_code[4][4] = {
    {'.---', '-..---', '.-..', '-..'},
    {'.---', '-..', '.-', '..'},
    {'.', '-.', '.-', '...'},
    {'.---', '-..---', '.-..', '---'}
};

// Function to convert a character to Morse code
char convert_char_to_morse(char character) {
    switch (character) {
        case 'a':
            return morse_code[0][0];
        case 'b':
            return morse_code[0][1];
        case 'c':
            return morse_code[0][2];
        case 'd':
            return morse_code[0][3];
        case 'e':
            return morse_code[1][0];
        case 'f':
            return morse_code[1][1];
        case 'g':
            return morse_code[1][2];
        case 'h':
            return morse_code[1][3];
        case 'i':
            return morse_code[2][0];
        case 'j':
            return morse_code[2][1];
        case 'k':
            return morse_code[2][2];
        case 'l':
            return morse_code[2][3];
        case 'm':
            return morse_code[3][0];
        case 'n':
            return morse_code[3][1];
        case 'o':
            return morse_code[3][2];
        case 'p':
            return morse_code[3][3];
        case 'q':
            return morse_code[4][0];
        case 'r':
            return morse_code[4][1];
        case 's':
            return morse_code[4][2];
        case 't':
            return morse_code[4][3];
        case 'u':
            return morse_code[1][0] + morse_code[0][0];
        case 'v':
            return morse_code[1][0] + morse_code[0][1];
        case 'w':
            return morse_code[1][0] + morse_code[0][2];
        case 'x':
            return morse_code[1][1] + morse_code[0][0];
        case 'y':
            return morse_code[1][1] + morse_code[0][1];
        case 'z':
            return morse_code[1][1] + morse_code[0][2];
        default:
            return 'N/A';
    }
}

int main() {
    char character;

    // Get the character to convert
    printf("Enter a character: ");
    scanf("%c", &character);

    // Convert the character to Morse code
    char morse_code_output = convert_char_to_morse(character);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code_output);

    return 0;
}