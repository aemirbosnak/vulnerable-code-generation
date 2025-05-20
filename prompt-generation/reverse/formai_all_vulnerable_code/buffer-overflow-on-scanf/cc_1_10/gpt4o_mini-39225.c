//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MORSE_CODE_LENGTH 36

// Morse code for A-Z and 0-9
const char *morse_code[MORSE_CODE_LENGTH] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.", 
    "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",   
    "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",  
    "...-", ".--",  "-..-", "-.--", "--..", // A-Z
    "-----", ".----", "..---", "...--", "....-", ".....", 
    "-....", "--...", "---..", "---."  // 0-9
};

// Helper function to convert character to Morse code index
int char_to_index(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A'; // Index 0-25 for A-Z
    if (c >= '0' && c <= '9') return c - '0' + 26; // Index 26-35 for 0-9
    return -1; // Invalid character
}

// Function to convert text to Morse code
void text_to_morse(const char *text) {
    size_t len = strlen(text);

    printf("Morse Code: ");
    for (size_t i = 0; i < len; i++) {
        char c = toupper(text[i]); // Convert to uppercase
        if (c == ' ') {
            printf("  "); // Space between words
        } else {
            int index = char_to_index(c);
            if (index != -1) {
                printf("%s ", morse_code[index]);
            } else {
                printf("? "); // For unsupported characters
            }
        }
    }
    printf("\n");
}

// Menu function
void display_menu() {
    printf("\n--- Morse Code Converter ---\n");
    printf("1. Convert Text to Morse Code\n");
    printf("2. Exit\n");
}

int main() {
    char input_text[256];
    int choice = 0;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter text (up to 255 characters): ");
            getchar(); // Consume the newline after the choice
            fgets(input_text, sizeof(input_text), stdin);
            // Remove newline character at the end if present
            input_text[strcspn(input_text, "\n")] = 0;

            text_to_morse(input_text);
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}