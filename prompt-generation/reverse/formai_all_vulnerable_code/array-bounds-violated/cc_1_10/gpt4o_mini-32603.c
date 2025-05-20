//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256

// Define the Morse code mappings
const char* morse_code[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",    ".---",
    "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",   "...",   "-",
    "..-",   "...-", ".--",  "-..-", "-.--", "--..", // A-Z
    "-----", ".----", "..---", "...--", "....-", "---..", "----." // 0-9
};

char get_morse_char(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return morse_code[ch - 'A'];
    } else if (ch >= '0' && ch <= '9') {
        return morse_code[ch - '0' + 26];
    } else if (ch == ' ') {
        return " "; // Space in Morse code
    } else {
        return ""; // Unknown character (return empty)
    }
}

void text_to_morse(const char *input) {
    int i = 0;
    printf("Morse Code: ");
    while (input[i]) {
        char morse_char[10]; // Buffer for Morse representation
        strcpy(morse_char, get_morse_char(toupper(input[i])));
        
        if (strlen(morse_char) > 0) {
            printf("%s ", morse_char); // Print Morse code with a space
        }
        i++;
    }
    printf("\n");
}

int main() {
    char user_input[MAX_INPUT];
    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("Please enter your text (up to %d characters): ", MAX_INPUT - 1);
    
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        user_input[strcspn(user_input, "\n")] = '\0'; // Remove newline
        printf("Your Input: %s\n", user_input);
        
        text_to_morse(user_input); // Convert input to Morse code
    } else {
        printf("Error reading your input!\n");
    }

    printf("Thanks for using the Morse Code converter. Goodbye!\n");
    return 0;
}