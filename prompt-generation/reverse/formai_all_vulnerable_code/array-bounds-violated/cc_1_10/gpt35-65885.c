//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100 // Define maximum input length
#define MAX_OUTPUT_LENGTH 400 // Define maximum output length

char CHARACTER_TO_MORSE[30][10] = { // Morse code conversion table
    {".-"}, {"-..."}, {"-.-."}, {"-.."},
    {"."}, {"..-."}, {"--."}, {"...."},
    {".."}, {".---"}, {"-.-"}, {".-.."},
    {"--"}, {"-."}, {"---"}, {".--."},
    {"--.-"}, {".-."}, {"..."}, {"-"},
    {"..-"}, {"...-"}, {".--"}, {"-..-"},
    {"-.--"}, {"--.."}
};

char* convertTextToMorseCode(char*);
void printMorseCode(char*);

int main() {
    char inputText[MAX_INPUT_LENGTH];
    printf("Enter text to convert to Morse code: ");
    fgets(inputText, MAX_INPUT_LENGTH, stdin); // Read input text
    inputText[strlen(inputText)-1] = '\0'; // Remove trailing newline character
    printMorseCode(convertTextToMorseCode(inputText)); // Convert and print Morse code
    return 0;
}

char* convertTextToMorseCode(char* inputText) {
    static char output[MAX_OUTPUT_LENGTH]; // Define static output array
    int outputIndex = 0; // Define outputIndex variable
    for (int i = 0; i < strlen(inputText); i++) {
        if (isalpha(inputText[i])) { // Handle letters
            int index = toupper(inputText[i]) - 'A';
            strcat(output, CHARACTER_TO_MORSE[index]);
            strcat(output, " ");
            outputIndex += strlen(CHARACTER_TO_MORSE[index]) + 1;
        } else if (isdigit(inputText[i])) { // Handle numbers
            int index = inputText[i] - '0' + 25;
            strcat(output, CHARACTER_TO_MORSE[index]);
            strcat(output, " ");
            outputIndex += strlen(CHARACTER_TO_MORSE[index]) + 1;
        } else if (isspace(inputText[i])) { // Handle spaces
            strcat(output, "/ ");
            outputIndex += 2;
        } else { // Handle other characters as question marks
            strcat(output, "? ");
            outputIndex += 2;
        }
    }
    output[outputIndex-1] = '\0'; // Remove trailing space
    return output;
}

void printMorseCode(char* morseCode) {
    for (int i = 0; i < strlen(morseCode); i++) {
        if (morseCode[i] == '.') {
            printf("Dot ");
        } else if (morseCode[i] == '-') {
            printf("Dash ");
        } else if (morseCode[i] == '/') {
            printf("Space ");
        } else if (morseCode[i] == ' ') {
            printf("\n");
        }
    }
    printf("\n");
}