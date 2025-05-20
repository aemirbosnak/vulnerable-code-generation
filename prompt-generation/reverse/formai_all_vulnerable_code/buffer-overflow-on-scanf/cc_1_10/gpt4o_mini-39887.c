//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000

// Morse Code representation
const char *morseCodeMap[36] = {
    "A", ".-",    "B", "-...",  "C", "-.-.",  "D", "-..",   "E", ".",
    "F", "..-.",  "G", "--.",   "H", "....",   "I", "..",    "J", ".---",
    "K", "-.-",   "L", ".-..",  "M", "--",     "N", "-.",    "O", "---",
    "P", ".--.",  "Q", "--.-",  "R", ".-.",    "S", "...",   "T", "-",
    "U", "..-",   "V", "...-",  "W", ".--",    "X", "-..-",  "Y", "-.--",
    "Z", "--..",  "0", "-----", "1", ".----",  "2", "..---", "3", "...--",
    "4", "....-", "5", ".....", "6", "-....",  "7", "--...", "8", "---..",
    "9", "----."
};

// Function to convert a character to Morse code
const char *textToMorse(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return morseCodeMap[(c - 'A') * 2 + 1];
    } else if (c >= '0' && c <= '9') {
        return morseCodeMap[(c - '0' + 26) * 2 + 1];
    } else if (c == ' ') {
        return " ";  // Space character
    }
    return "";  // For unsupported characters
}

// Function to convert input text to Morse code
void convertToMorse(const char *text) {
    printf("Morse Code: ");
    for (int i = 0; i < strlen(text); i++) {
        const char *morse = textToMorse(text[i]);
        if (*morse) {
            printf("%s ", morse);
        }
    }
    printf("\n");
}

// Main function
int main() {
    char input[MAX_TEXT_LENGTH];
    char repeat;

    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("You can convert text to Morse code! Type your text below:\n");

    do {
        printf("\nEnter the text (up to %d characters): ", MAX_TEXT_LENGTH - 1);
        fgets(input, MAX_TEXT_LENGTH, stdin);

        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;

        convertToMorse(input);

        printf("\nDo you want to convert another text? (y/n): ");
        scanf(" %c", &repeat);
        getchar();  // Clear newline character after scanf

    } while (repeat == 'y' || repeat == 'Y');

    printf("Thank you for using the Morse Code Converter!\n");
    return 0;
}