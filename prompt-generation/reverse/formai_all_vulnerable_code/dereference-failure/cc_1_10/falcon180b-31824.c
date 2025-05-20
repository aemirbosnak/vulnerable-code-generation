//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_MORSE_CODE_LENGTH 5000

void generate_morse_code(char *input, char *output) {
    int i = 0, j = 0;
    char morse_code[MAX_MORSE_CODE_LENGTH] = "";
    char *morse_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.- ";

    // Loop through each character in the input string
    while (input[i]!= '\0') {
        if (isalpha(input[i])) {
            // Convert uppercase letters to lowercase
            if (isupper(input[i])) {
                input[i] = tolower(input[i]);
            }

            // Add Morse code for uppercase letters to the output string
            strcat(output, (char *)morse_table + (int)tolower(input[i]) - 97);
        } else if (isdigit(input[i])) {
            // Add Morse code for digits to the output string
            strcat(output, (char *)morse_table + (int)input[i] - 48);
        } else {
            // Add Morse code for special characters to the output string
            strcat(output, (char *)morse_table + (int)input[i] - 58);
        }
        i++;
    }

    // Add a newline character to the end of the output string
    strcat(output, "\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_MORSE_CODE_LENGTH];

    // Prompt the user to enter a string to convert to Morse code
    printf("Enter a string to convert to Morse code: ");

    // Read the input string from the user
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from the end of the input string
    input[strcspn(input, "\n")] = '\0';

    // Generate the Morse code for the input string
    generate_morse_code(input, output);

    // Print the Morse code to the console
    printf("%s", output);

    return 0;
}