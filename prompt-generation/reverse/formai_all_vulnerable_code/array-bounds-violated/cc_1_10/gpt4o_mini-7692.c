//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

const char *morseCode[] = {
    ".-",   // A 
    "-...", // B 
    "-.-.", // C 
    "-..",  // D 
    ".",    // E 
    "..-.", // F 
    "--.",  // G 
    "....", // H 
    "..",   // I 
    ".---", // J 
    "-.-",  // K 
    ".-..", // L 
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
    "--.."  // Z 
};

const int asciiOffset = 65; // Offset for converting A-Z (ASCII) to index

void printMorse(const char *input) {
    char ch;
    for (int i = 0; i < strlen(input); ++i) {
        ch = input[i];
        if (ch >= 'A' && ch <= 'Z') {
            printf("%s ", morseCode[ch - asciiOffset]);
        } else if (ch >= 'a' && ch <= 'z') {
            printf("%s ", morseCode[ch - asciiOffset]);
        } else if (ch == ' ') {
            printf("  "); // Space in Morse code
        } else {
            printf("? "); // Unknown character
        }
    }
    printf("\n"); // New line at the end
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("*-*-*- Morse Code Converter *-*-*-*\n");
    printf("Enter text (only letters and spaces are allowed):\n");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    printf("Your input in Morse Code:\n");
    printMorse(input);
    
    printf("****************************************\n");
    
    return 0;
}