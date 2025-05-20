//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Morse code representation for letters and digits
const char *morse_code[] = {
    [ 'A' - 'A' ] = ".-",
    [ 'B' - 'A' ] = "-...",
    [ 'C' - 'A' ] = "-.-.",
    [ 'D' - 'A' ] = "-..",
    [ 'E' - 'A' ] = ".",
    [ 'F' - 'A' ] = "..-.",
    [ 'G' - 'A' ] = "--.",
    [ 'H' - 'A' ] = "....",
    [ 'I' - 'A' ] = "..",
    [ 'J' - 'A' ] = ".---",
    [ 'K' - 'A' ] = "-.-",
    [ 'L' - 'A' ] = ".-..",
    [ 'M' - 'A' ] = "--",
    [ 'N' - 'A' ] = "-.",
    [ 'O' - 'A' ] = "---",
    [ 'P' - 'A' ] = ".--.",
    [ 'Q' - 'A' ] = "--.-",
    [ 'R' - 'A' ] = ".-.",
    [ 'S' - 'A' ] = "...",
    [ 'T' - 'A' ] = "-",
    [ 'U' - 'A' ] = "..-",
    [ 'V' - 'A' ] = "...-",
    [ 'W' - 'A' ] = ".--",
    [ 'X' - 'A' ] = "-..-",
    [ 'Y' - 'A' ] = "-.--",
    [ 'Z' - 'A' ] = "--..",
    [ '0' - '0' ] = "-----",
    [ '1' - '0' ] = ".----",
    [ '2' - '0' ] = "..---",
    [ '3' - '0' ] = "...--",
    [ '4' - '0' ] = "....-",
    [ '5' - '0' ] = ".....",
    [ '6' - '0' ] = "-....",
    [ '7' - '0' ] = "--...",
    [ '8' - '0' ] = "---..",
    [ '9' - '0' ] = "----.",
};

// Function to convert a character to its Morse code equivalent
void char_to_morse(char ch) {
    // Convert character to uppercase
    ch = toupper(ch);
    
    // Check for alphabetic characters and digits
    if (ch >= 'A' && ch <= 'Z') {
        printf("%s ", morse_code[ch - 'A']);
    } else if (ch >= '0' && ch <= '9') {
        printf("%s ", morse_code[ch - '0' + 26]);
    } else if (ch == ' ') {
        printf("/ "); // Use slash for space
    } else {
        printf("? "); // Unknown character
    }
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("Enter text to convert, or type 'exit' to quit the program.\n");

    while (1) {
        printf("Input: ");
        // Read a line of input from the user
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Remove newline character
            input[strcspn(input, "\n")] = 0;

            // Exit the program if the user types 'exit'
            if (strcasecmp(input, "exit") == 0) {
                printf("Exiting the Morse code converter. Goodbye!\n");
                break;
            }

            // Process each character in the input
            printf("Morse Code: ");
            for (int i = 0; i < strlen(input); i++) {
                char_to_morse(input[i]);
            }
            printf("\n");
        } else {
            printf("Error reading input.\n");
        }
    }

    return 0;
}