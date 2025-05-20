//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Morse code dictionary
char *morse_dict[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };

// Define the Morse code dictionary size
#define MORSE_DICT_SIZE 63

// Define the maximum input string length
#define MAX_INPUT_LENGTH 100

// Define the Morse code output format
#define MORSE_CODE_FORMAT " %c "

// Function to convert the input string to Morse code
void input_to_morse(char *input) {
    int i, j, len;

    // Get the input string length
    len = strlen(input);

    // Loop through each character in the input string
    for (i = 0; i < len; i++) {
        // Check if the character is an alphabet or a number
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
            // Convert the character to Morse code
            printf(MORSE_CODE_FORMAT, morse_dict[(int) input[i] - 65]);
        } else {
            // Print a space for non-alphanumeric characters
            printf(" ");
        }
    }
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];

    // Get the input string from the user
    printf("Enter a string to convert to Morse code: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = '\0';

    // Convert the input string to Morse code
    input_to_morse(input);

    return 0;
}