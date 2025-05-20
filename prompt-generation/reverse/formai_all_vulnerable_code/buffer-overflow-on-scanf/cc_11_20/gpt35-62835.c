//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <string.h>

// Define Morse code characters
char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                     ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                     "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Define corresponding alphabetical characters
char* alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", 
                    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

int main() {
    char inputString[1000];
    int length;
    
    // Get input from user
    printf("Enter text to convert to Morse code (uppercase letters only):\n");
    scanf("%[^\n]", inputString);
    
    // Calculate length of input string
    length = strlen(inputString);
    
    // Convert each character of the input string to Morse code and print
    printf("Morse code: ");
    for (int i = 0; i < length; i++) {
        char currentChar = inputString[i];
        if (currentChar == ' ') {
            printf("/ ");
        } else {
            // Find index of current character in the alphabet array
            int index = currentChar - 'A';
            // Print corresponding Morse code character
            printf("%s ", morseCode[index]);
        }
    }
    printf("\n");
    
    // Allow user to configure Morse code to alphabetical character conversion
    printf("Would you like to configure the Morse code to alphabetical character conversion? (y/n)\n");
    char response;
    scanf(" %c", &response);
    if (response == 'y') {
        printf("Please enter Morse code and corresponding alphabetical character(s) in the format 'morseCode letter(s)'.\n");
        printf("Enter 'done' to finish.\n");
        char morseInput[10];
        char alphaInput[10];
        int customAlphabetIndex = 26; // Start at end of alphabet array
        do {
            scanf("%s", morseInput);
            if (strcmp("done", morseInput) == 0) {
                break;
            }
            scanf("%s", alphaInput);
            // Check if morseInput exists in morseCode array
            int i;
            int exists = 0;
            for (i = 0; i < 26; i++) {
                if (strcmp(morseCode[i], morseInput) == 0) {
                    exists = 1;
                    break;
                }
            }
            if (exists) {
                // If morseInput exists, update corresponding character in alphabet array
                strcpy(alphabet[i], alphaInput);
            } else {
                // If morseInput does not exist, add to end of arrays
                strcpy(morseCode[customAlphabetIndex], morseInput);
                strcpy(alphabet[customAlphabetIndex], alphaInput);
                customAlphabetIndex++;
            }
        } while (strcmp("done", morseInput) != 0);
    }
    
    // Convert Morse code back to alphabetical characters using updated conversion arrays if applicable
    printf("Would you like to convert Morse code back to alphabetical characters? (y/n)\n");
    scanf(" %c", &response);
    if (response == 'y') {
        printf("Enter Morse code to convert:\n");
        char morseString[1000];
        scanf(" %[^\n]", morseString);
        char* morseChar = strtok(morseString, " "); // Start with first Morse code character in input string
        printf("Alphabetical characters: ");
        while (morseChar != NULL) {
            if (strcmp(morseChar, "/") == 0) {
                printf(" ");
            } else {
                // Find index of current Morse code character in the morseCode array
                int index = -1;
                int i;
                for (i = 0; i < 26; i++) {
                    if (strcmp(morseCode[i], morseChar) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    // Print corresponding alphabetical character
                    printf("%s", alphabet[index]);
                } else {
                    printf("(?)"); // Print question mark if Morse code character is not in conversion arrays
                }
            }
            morseChar = strtok(NULL, " "); // Move on to next Morse code character in input string
        }
        printf("\n");
    }
    
    return 0;
}