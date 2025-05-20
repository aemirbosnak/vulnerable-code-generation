//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Morse code alphabet and durations
#define ALPHABET_SIZE 26
typedef struct MorseCode {
    char letter;
    char *morse;
    int duration;
} MorseCode;

// Initialize Morse alphabet and durations
MorseCode morseAlphabet[ALPHABET_SIZE] = {
    {'A', ".-", 1}, {'B', "-...", 1}, {'C', "-.-.", 1}, {'D', "-..", 1},
    {'E', ".", 1}, {'F', "..-.", 1}, {'G', "--.", 1}, {'H', "....", 1},
    {'I', "..", 1}, {'J', ".---", 1}, {'K', "-.-", 1}, {'L', ".-..", 1},
    {'M', "--", 1}, {'N', "-.", 1}, {'O', "---", 1}, {'P', ".--.", 1},
    {'Q', "--.-", 1}, {'R', ".-.", 1}, {'S', "...", 1}, {'T', "-", 1},
    {'U', "..-", 1}, {'V', "...-", 1}, {'W', ".--", 1}, {'X', "-..-", 1},
    {'Y', "-.--", 1}, {'Z', "--..", 1}, {' ', "/", 1}
};

// Function to print Morse code
void printMorseCode(char morse[]) {
    int i;
    for (i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == ' ') {
            printf("/");
            continue;
        }
        int j;
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (morseAlphabet[j].letter == morse[i]) {
                printf("%s", morseAlphabet[j].morse);
                break;
            }
        }
    }
    printf("\n");
}

// Function to convert text to Morse code
void textToMorseCode(char text[]) {
    int i, j;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            printf("/ ");
            continue;
        }
        bool found = false;
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (morseAlphabet[j].letter == text[i]) {
                printf("%s ", morseAlphabet[j].morse);
                found = true;
                break;
            }
        }
        if (!found) {
            printf("Unrecognized character: %c\n", text[i]);
        }
    }
}

// Main function
int main() {
    char inputText[100];
    printf("Enter text to convert to Morse code: ");
    scanf("%s", inputText);

    textToMorseCode(inputText);

    return 0;
}