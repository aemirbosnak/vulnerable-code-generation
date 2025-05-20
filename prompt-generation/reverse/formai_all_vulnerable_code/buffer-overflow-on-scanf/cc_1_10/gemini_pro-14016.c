//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
// Ahoy there, matey! Let's embark on a grand adventure to convert text to Morse code, with a touch of nautical flair.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table, using a nested array for easy access.
char morseCode[][5] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", "----", ".-.-", "-..-",
    "..--", "-.--", "-.-.-", "..--.-", ".----.", "-.-.-.", "---...", "-....-", "..--..",
    ".----", ".--.-", "--..-", ".-.--", "....-.", "-----", "-----"
};
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

// Function to convert a single character to its Morse code representation.
char* charToMorse(char c) {
    int i;
    for (i = 0; i < strlen(alphabet); i++) {
        if (c == alphabet[i]) {
            return morseCode[i];
        }
    }
    return " "; // Return a placeholder for invalid characters.
}

// Function to convert an entire string to Morse code.
char* stringToMorse(char* str) {
    int i, len = strlen(str);
    char* morseCodeString = malloc(len * 5); // Allocate enough space for the converted Morse code.
    for (i = 0; i < len; i++) {
        strcat(morseCodeString, charToMorse(str[i]));
        strcat(morseCodeString, " "); // Add a space as a separator between characters.
    }
    return morseCodeString;
}

int main() {
    // Let's set sail and get some input from the user.
    char message[100];
    printf("Ahoy, matey! Enter your message to be converted to Morse code:\n");
    scanf("%s", message);

    // Time to cast our lines and convert that message to Morse code.
    char* morseCodeMessage = stringToMorse(message);

    // Now, let's hoist the sails and display the Morse code.
    printf("\nYour message in Morse code:\n");
    printf("%s\n", morseCodeMessage);

    // Finally, let's drop anchor and clean up.
    free(morseCodeMessage); // Don't forget to release the memory allocated for the Morse code string.
    return 0;
}