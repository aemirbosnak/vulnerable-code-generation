//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Morse code representation of letters and digits
const char *morseCode[36] = {
    "A", ".-", "B", "-...", "C", "-.-.", "D", "-..", "E", ".",
    "F", "..-.", "G", "--.", "H", "....", "I", "..", "J", ".---",
    "K", "-.-", "L", ".-..", "M", "--", "N", "-.", "O", "---",
    "P", ".--.", "Q", "--.-", "R", ".-.", "S", "...", "T", "-",
    "U", "..-", "V", "...-", "W", ".--", "X", "-..-", "Y", "-.--",
    "Z", "--..", "0", "-----", "1", ".----", "2", "..---", "3", "...--",
    "4", "....-", "5", ".....", "6", "-....", "7", "--...", "8", "---..",
    "9", "----."
};

// Function to convert character to Morse code
const char* charToMorse(char c) {
    if (isalpha(c)) {
        // Convert to uppercase if it's a letter
        return morseCode[c - 'A' + 1];
    } else if (isdigit(c)) {
        return morseCode[c - '0' + 27];
    } else { // Return empty string for unsupported characters
        return "";
    }
}

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the Morse Code Converter!\n");
    printf("Type a message to convert it to Morse code.\n");
    printf("Only letters A-Z and digits 0-9 are supported.\n");
    printf("Press Ctrl+C to exit the program.\n\n");
}

// Main function
int main() {
    displayInstructions();

    // Input buffer for user message
    char input[256];
    
    while (1) {
        printf("Enter your message (type exit to quit): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0; 

        // Check if user wants to exit
        if (strcasecmp(input, "exit") == 0) {
            printf("Exiting program... Goodbye!\n");
            break;
        }

        printf("Morse Code: ");
        for (size_t i = 0; i < strlen(input); i++) {
            char c = toupper(input[i]); // Normalize to uppercase
            const char *morse = charToMorse(c);
            if (strcmp(morse, "") != 0) {
                printf("%s ", morse); // Print Morse code
            }
        }
        printf("\n\n");
    }

    return 0;
}