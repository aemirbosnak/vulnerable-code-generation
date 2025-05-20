//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character to bit representation
char morse_code[][7] = {
    "-",    // A
    ".---", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-.",  // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
    "-----",// 0
    ".----",// 1
    "..---",// 2
    "...--",// 3
    "....-",// 4
    ".....",// 5
    "-....",// 6
    "--...",// 7
    "---..",// 8
    "----.",// 9
    " "     // Space
};

// Function to convert character to morse code
char *to_morse(char c) {
    int i;
    for (i = 0; i < 26; i++) {
        if (c == 'a' + i) {
            return morse_code[i];
        } else if (c == 'A' + i) {
            return morse_code[i];
        } else if (c == '0' + i) {
            return morse_code[26 + i];
        }
    }
    if (c == ' ') {
        return morse_code[36];
    }
    return NULL;
}

// Function to print morse code
void print_morse(char *morse) {
    while (*morse) {
        if (*morse == '.') {
            printf("·");
        } else if (*morse == '-') {
            printf("-");
        }
        morse++;
    }
    printf(" ");
}

// Main function
int main() {
    char text[100];
    printf("Enter text to be converted to Morse code: ");
    scanf("%s", text);
    printf("Morse code: ");
    for (int i = 0; i < strlen(text); i++) {
        char *morse = to_morse(text[i]);
        if (morse) {
            print_morse(morse);
        }
    }
    printf("\n");
    return 0;
}