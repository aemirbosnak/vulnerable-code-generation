//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse Code representation for each letter and digit
const char *morseCodeMap[] = {
    [0] = "A",     [1] = "B",     [2] = "C",     [3] = "D",
    [4] = "E",     [5] = "F",     [6] = "G",     [7] = "H",
    [8] = "I",     [9] = "J",     [10] = "K",    [11] = "L",
    [12] = "M",    [13] = "N",    [14] = "O",    [15] = "P",
    [16] = "Q",    [17] = "R",    [18] = "S",    [19] = "T",
    [20] = "U",    [21] = "V",    [22] = "W",    [23] = "X",
    [24] = "Y",    [25] = "Z",    [26] = "1",    [27] = "2",
    [28] = "3",    [29] = "4",    [30] = "5",    [31] = "6",
    [32] = "7",    [33] = "8",    [34] = "9",    [35] = "0"
};

const char *morseChar[] = {
    ".-",    "-...",  "-.-.",  "-..",   ".",     "..-.", 
    "--.",   "....",  "..",    ".---",  "-.-",   ".-..", 
    "--",    "-.",    "---",    ".--.",  "--.-",  ".-.", 
    "...",   "-",     "..-",    "...-",   "-.--",  "--..",  
    ".----",  "..---", "...--",  "....-",  ".....",  "-....",  
    "--...",  "---..", "----.",  "-----"
};

// Function to convert text to Morse code
void textToMorse(const char *inputText) {
    printf("Morse Code Output:\n");
    
    for (size_t i = 0; i < strlen(inputText); i++) {
        char c = inputText[i];
        
        if (c >= 'A' && c <= 'Z') {
            printf("%s ", morseChar[c - 'A']);
        } else if (c >= 'a' && c <= 'z') {
            printf("%s ", morseChar[c - 'a']);
        } else if (c >= '0' && c <= '9') {
            printf("%s ", morseChar[c - '0' + 26]);
        } else if (c == ' ') {
            printf("   "); // Spacing between words
        } else {
            printf("? "); // Unknown characters
        }
    }

    printf("\n");
}

// Main function to execute the program
int main() {
    char inputText[256];
    printf("Enter text to convert to Morse code:\n");
    
    // Read input from user
    if (fgets(inputText, sizeof(inputText), stdin) != NULL) {
        // Remove newline character from input
        inputText[strcspn(inputText, "\n")] = 0;
        
        // Convert input text to Morse code
        textToMorse(inputText);
    } else {
        fprintf(stderr, "Error reading input!\n");
    }

    return 0;
}