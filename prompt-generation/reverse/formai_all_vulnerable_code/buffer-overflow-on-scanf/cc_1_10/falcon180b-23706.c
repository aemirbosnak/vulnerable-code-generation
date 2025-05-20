//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Morse code dictionary
char *morse_dict[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

// Function to convert input string to Morse code
void convert_to_morse(char *input) {
    int i, j, k;
    char *morse_output = (char *) malloc(strlen(input) * 5 + 1); // Allocate memory for Morse code output
    strcpy(morse_output, "");

    // Iterate through each character in the input string
    for (i = 0; input[i]!= '\0'; i++) {
        // Check if character is an alphabet or a number
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
            // Convert character to uppercase
            input[i] = toupper(input[i]);

            // Check if character is a number
            if (input[i] >= '0' && input[i] <= '9') {
                // Append Morse code for number to output string
                strcat(morse_output, morse_dict[input[i] - '0']);
            } else {
                // Append Morse code for alphabet to output string
                strcat(morse_output, morse_dict[input[i] - 'A']);
            }
        } else {
            // Append space to output string for non-alphanumeric characters
            strcat(morse_output, " ");
        }
    }

    // Print the Morse code output
    printf("%s\n", morse_output);

    // Free memory allocated for Morse code output
    free(morse_output);
}

int main() {
    char input[100];

    // Prompt user for input
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", input);

    // Convert input string to Morse code
    convert_to_morse(input);

    return 0;
}