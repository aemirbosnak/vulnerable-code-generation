//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 

// Morse code lookup table
char *morse_code_lookup[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

// Function to convert text to morse code
void text_to_morse(char *string, int len) {

    int i, j, index;

    // Iterate through each character of the string
    for (i = 0; i < len; i++) {

        // Ignore spaces
        if (string[i] == ' ') {
            printf(" ");
        }

        // Convert letters to morse code
        else if (isalpha(string[i])) {
            
            index = tolower(string[i]) - 'a';
            
            // Print the morse code
            printf("%s ", morse_code_lookup[index]);
        }

        // Convert numbers to morse code
        else if (isdigit(string[i])) {
            
            index = string[i] - '0' + 22;
            
            // Print the morse code
            printf("%s ", morse_code_lookup[index]);
        }
    }
}

// Main function
int main(void) {

    char text[MAX_WORD_LENGTH];
    int len;
    printf("Enter some text to convert to morse code: ");
    fgets(text, MAX_WORD_LENGTH, stdin);

    // Remove newline character from input
    len = strlen(text);
    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
        len--;
    }

    // Convert input text to morse code
    printf("Morse code: ");
    text_to_morse(text, len);

    return 0;
}