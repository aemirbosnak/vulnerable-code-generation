//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Morse code mapping for each letter and number
const char* morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.--", "--..", // A to Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0 to 9
};

char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void print_morse(const char* message) {
    printf("Morse Code:\n");
    
    // Convert each character in the message
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = toupper(message[i]); // convert to uppercase
        if ('A' <= ch && ch <= 'Z') {
            printf("%s ", morse_code[ch - 'A']);
        } else if ('0' <= ch && ch <= '9') {
            printf("%s ", morse_code[ch - '0' + 26]);
        } else if (ch == ' ') {
            printf("/ "); // using '/' to represent space
        }
    }
    printf("\n");
}

void get_user_input(char* input) {
    printf("Enter text to convert to Morse code (max %d characters): ", MAX);
    if (fgets(input, MAX, stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
    }
}

int main() {
    char input[MAX];

    // Get user input
    get_user_input(input);
    
    // Print the input message
    printf("You entered: %s\n", input);
    
    // Convert to Morse code
    print_morse(input);

    return 0;
}