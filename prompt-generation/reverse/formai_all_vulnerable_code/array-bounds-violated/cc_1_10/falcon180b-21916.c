//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 100
#define CODE_LENGTH 5

// Morse code dictionary
char *morse_dict[] = {"A", ".-", "B", "-...", "C", "-.-.", "D", "-..", "E", ".", "F", "..-.", "G", "--.", "H", "....", "I", "..", "J", ".---", "K", "-.-", "L", ".-..", "M", "--", "N", "-.", "O", "---", "P", ".--.", "Q", "--.-", "R", ".-.", "S", "...", "T", "-", "U", "..-", "V", "...-", "W", ".--", "X", "-..-", "Y", "-.--", "Z", "--..", "1", ".----", "2", "..---", "3", "...--", "4", "....-", "5", ".....", "6", "-....", "7", "--...", "8", "---..", "9", "----.", "0", "-----"};

// Function to convert text to Morse code
void text_to_morse(char *text) {
    char morse_code[MAX_CODE_LENGTH];
    int i, j;

    // Initialize Morse code string
    memset(morse_code, '\0', MAX_CODE_LENGTH);

    // Loop through each character in the text
    for (i = 0; text[i]!= '\0'; i++) {
        // Convert uppercase to lowercase
        text[i] = tolower(text[i]);

        // Check if character is a letter or digit
        if (isalpha(text[i]) || isdigit(text[i])) {
            // Find Morse code for character
            for (j = 0; j < CODE_LENGTH; j++) {
                if (morse_dict[text[i] - 'A'] == morse_dict[j]) {
                    strcat(morse_code, morse_dict[j]);
                    break;
                }
            }
        } else {
            // Add space between words
            strcat(morse_code, " ");
        }
    }

    // Print Morse code
    printf("%s\n", morse_code);
}

int main() {
    char text[100];

    // Get text input from user
    printf("Enter text to convert to Morse code: ");
    scanf("%s", text);

    // Convert text to Morse code
    text_to_morse(text);

    return 0;
}