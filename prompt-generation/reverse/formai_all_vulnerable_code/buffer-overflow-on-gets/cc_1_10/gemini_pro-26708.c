//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to convert text to ASCII art
char *text_to_ascii(char *text) {
    // Create an array to store the ASCII art
    char *ascii_art = (char *)malloc(strlen(text) * 10);

    // Loop through each character in the text
    int i = 0;
    while (text[i] != '\0') {
        // Get the ASCII code for the character
        int ascii_code = (int)text[i];

        // Convert the ASCII code to a string
        char ascii_code_str[10];
        sprintf(ascii_code_str, "%d", ascii_code);

        // Add the ASCII code string to the ASCII art array
        strcat(ascii_art, ascii_code_str);

        // Add a newline character to the ASCII art array
        strcat(ascii_art, "\n");

        // Increment the index of the character
        i++;
    }

    // Return the ASCII art
    return ascii_art;
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter the text you want to convert to ASCII art: ");
    gets(text);

    // Convert the text to ASCII art
    char *ascii_art = text_to_ascii(text);

    // Print the ASCII art
    printf("\n%s", ascii_art);

    // Free the memory allocated for the ASCII art
    free(ascii_art);

    return 0;
}