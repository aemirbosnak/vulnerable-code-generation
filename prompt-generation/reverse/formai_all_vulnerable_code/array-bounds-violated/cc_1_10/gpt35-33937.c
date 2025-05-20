//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

// Define the maximum length of an input string
#define MAX_INPUT_LENGTH 100

// Define the number of letters in the Alien Language
#define ALPHABET_SIZE 10

// Define the Alien Language
char alienLanguage[ALPHABET_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'W'};

// Define the translation matrix for the Alien Language
char translationMatrix[ALPHABET_SIZE][ALPHABET_SIZE] = {
    {'W', 'i', 'g', 'f', 'e', 'd', 'c', 'b', 'a', 'h'},
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'W'},
    {'h', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'i', 'W'},
    {'W', 'd', 'e', 'f', 'g', 'h', 'a', 'b', 'c', 'i'},
    {'i', 'W', 'd', 'e', 'f', 'g', 'h', 'a', 'b', 'c'},
    {'c', 'i', 'W', 'd', 'e', 'f', 'g', 'h', 'a', 'b'},
    {'b', 'c', 'i', 'W', 'd', 'e', 'f', 'g', 'h', 'a'},
    {'a', 'b', 'c', 'i', 'W', 'd', 'e', 'f', 'g', 'h'},
    {'h', 'a', 'b', 'c', 'i', 'W', 'd', 'e', 'f', 'g'},
    {'g', 'h', 'a', 'b', 'c', 'i', 'W', 'd', 'e', 'f'}
};

void translate(char* inputString) {
    // Get the length of the input string
    int length = strlen(inputString);

    // Translate each letter in the input string
    for (int i = 0; i < length; i++) {
        // Search for the index of the letter in the Alien Language
        int index = -1;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (inputString[i] == alienLanguage[j]) {
                index = j;
                break;
            }
        }

        // If the letter is not found in the Alien Language, output an error message and exit the program
        if (index == -1) {
            printf("Error: Invalid input string!\n");
            return;
        }

        // Translate the letter using the translation matrix
        inputString[i] = translationMatrix[index][0];
    }

    // Output the translated string
    printf("Translated string: %s\n", inputString);
}

int main() {
    // Declare an array to hold the input string
    char inputString[MAX_INPUT_LENGTH];

    // Get the input string from the user
    printf("Enter an input string: ");
    fgets(inputString,MAX_INPUT_LENGTH,stdin);

    // Remove the newline character from the input string
    inputString[strlen(inputString) - 1] = '\0';

    // Translate the input string
    translate(inputString);

    return 0;
}