//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 1024  // Maximum input length
#define MORSE_CODE_BUFFER 512  // Buffer size for Morse code output

// Morse code representations for letters and numbers
const char* morse_code_mapping[][2] = {
    {"A", ".-"}, {"B", "-..."}, {"C", "-.-."}, {"D", "-.."}, {"E", "."},
    {"F", "..-."}, {"G", "--."}, {"H", "...."}, {"I", ".."}, {"J", ".---"},
    {"K", "-.-"}, {"L", ".-.."}, {"M", "--"}, {"N", "-."}, {"O", "---"},
    {"P", ".--."}, {"Q", "--.-"}, {"R", ".-."}, {"S", "..."}, {"T", "-"},
    {"U", "..-"}, {"V", "...-"}, {"W", ".--"}, {"X", "-..-"}, {"Y", "-.--"},
    {"Z", "--.."}, {"0", "-----"}, {"1", ".----"}, {"2", "..---"}, {"3", "...--"},
    {"4", "....-"}, {"5", "....."}, {"6", "-...."}, {"7", "--..."}, {"8", "---.."},
    {"9", "----."}, {" ", " "}, // Space is represented as a plain space
    {NULL, NULL} // Sentinel value to indicate end of mappings
};

// Function to convert text to Morse code
void text_to_morse(char* input, char* output) {
    output[0] = '\0';  // Initialize output buffer
    for (int i = 0; input[i] != '\0'; i++) {
        char current_char = toupper(input[i]);  // Convert char to uppercase
        int j = 0;
        // Find the Morse code for the current character
        while (morse_code_mapping[j][0] != NULL) {
            if (morse_code_mapping[j][0][0] == current_char) {
                strcat(output, morse_code_mapping[j][1]);  // Append Morse code
                strcat(output, " ");  // Separate with a space
                break;
            }
            j++;
        }
        if (morse_code_mapping[j][0] == NULL) {
            strcat(output, "? ");  // Unknown character
        }
    }
}

// Function to print the menu
void print_menu() {
    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("1. Convert Text to Morse Code\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input[MAX_INPUT];  // Buffer to hold user input
    char morse_output[MORSE_CODE_BUFFER];  // Buffer for Morse code output
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice); // Read user's choice
        getchar(); // To consume the newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter the text to convert (max %d characters): ", MAX_INPUT - 1);
                fgets(input, MAX_INPUT, stdin); // Read user input
                // Remove trailing newline character
                input[strcspn(input, "\n")] = 0;  
                text_to_morse(input, morse_output); // Convert text to Morse code
                printf("Morse code: %s\n", morse_output);  // Display result
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
        printf("\n"); // New line for better readability
    }
    return 0; // End of program
}