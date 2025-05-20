//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a character to its Morse code equivalent
void charToMorse(char letter, char morse[]) {
    // Define the Morse codes for each character
    char* morseAlphabet[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    // If the letter is a space, use "  " to represent it in Morse code
    if (letter == ' ') {
        strcpy(morse, "  ");
    } else {
        // Convert the letter to uppercase and subtract the ASCII value of 'A' to get its index value
        int index = toupper(letter) - 'A';
        // Copy the Morse code equivalent to the morse array
        strcpy(morse, morseAlphabet[index]);
    }
}

int main() {
    char message[100];
    char morseMessage[200];  // Double the size to leave room for spaces
    int i, j, length;

    // Prompt the user to enter a message to convert to Morse code
    printf("Enter a message to convert to Morse code:\n");
    fgets(message, 100, stdin);
    // Remove the newline character at the end of the input
    message[strcspn(message, "\n")] = '\0';

    // Prompt the user to enter a dot (.) for a short signal and a hyphen (-) for a long signal
    printf("Enter a dot (.) for a short signal and a hyphen (-) for a long signal:\n");
    char dot, dash;
    scanf(" %c%c", &dot, &dash);

    // Convert the message to Morse code
    length = strlen(message);
    for (i = 0, j = 0; i < length; i++) {
        char morse[5];  // Morse code for a single letter can be up to 4 characters plus null terminator
        charToMorse(message[i], morse);
        strcat(morseMessage+j, morse);
        if (i != length-1) {
            strcat(morseMessage+j, " ");  // Add a space between letters
            j++;
        }
        j += strlen(morse);
    }

    // Print the Morse code message
    printf("Morse code: %s\n", morseMessage);

    return 0;
}