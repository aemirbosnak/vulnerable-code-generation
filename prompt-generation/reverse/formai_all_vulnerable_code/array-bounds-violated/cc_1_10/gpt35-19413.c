//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declaration
void printMorseCode(char message[], int messageLength);

// Morse Code array
const char *morseTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--..", "/", ".----", "..---", "...--", "....-", ".....", "-....", "--...", 
    "---..", "----.", "-----"
};

const char *alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";

int main() {
    char inputMessage[100];             // Input message
    int inputLength;                    // Length of input message
    
    // Get user input
    printf("Enter a message to be converted to Morse code: ");
    fgets(inputMessage, sizeof(inputMessage), stdin);
    inputLength = strlen(inputMessage) - 1;
    inputMessage[inputLength] = '\0';   // Remove newline character from input string
    
    // Print Morse code
    printMorseCode(inputMessage, inputLength);
    
    return 0;
}

// Function to print Morse code
void printMorseCode(char message[], int messageLength) {
    int i, j;
    char currentChar;
    int foundIndex;
    char *morseCode;
    
    printf("The Morse code for your message is: \n");
    
    for (i = 0; i < messageLength; i++) {
        currentChar = tolower(message[i]);
        
        // Check if current character is in the Morse Code table
        foundIndex = strchr(alphabet, currentChar) - alphabet;     // Get index of character
        if (foundIndex < 0 || foundIndex > 35) {    // Character not found
            printf("%c", currentChar);      // Print original character
        } else {    // Character found, print Morse code equivalent
            morseCode = (char*)morseTable[foundIndex];
            for (j = 0; j < strlen(morseCode); j++) {
                printf("%c", morseCode[j]);
                if (j != strlen(morseCode) - 1) {
                    printf(" ");
                }
            }
        }
        printf(" ");
    }
    printf("\n");
}