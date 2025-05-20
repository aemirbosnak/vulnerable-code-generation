//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert a text string to ASCII art
char *text_to_ascii(char *text) {
    // Create a 2D array of characters to store the ASCII art
    char **ascii_art = (char **)malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++) {
        ascii_art[i] = (char *)malloc(sizeof(char) * 100);
    }

    // Convert the text to uppercase
    for (int i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }

    // Create a pointer to the first character in the text
    char *ptr = text;

    // Loop through the text, one character at a time
    while (*ptr != '\0') {
        // Get the ASCII value of the character
        int ascii_value = (int)*ptr;

        // Convert the ASCII value to a string
        char ascii_string[3];
        sprintf(ascii_string, "%d", ascii_value);

        // Add the ASCII string to the ASCII art array
        strcat(ascii_art[0], ascii_string);

        // Move the pointer to the next character in the text
        ptr++;
    }

    // Return the ASCII art array
    return ascii_art;
}

// Function to print the ASCII art
void print_ascii_art(char **ascii_art) {
    // Loop through the ASCII art array, one row at a time
    for (int i = 0; i < 100; i++) {
        // Print the row of ASCII art
        printf("%s\n", ascii_art[i]);
    }
}

// Main function
int main() {
    // Get the text to convert to ASCII art from the user
    char text[100];
    printf("Enter the text to convert to ASCII art: ");
    scanf("%s", text);

    // Convert the text to ASCII art
    char **ascii_art = text_to_ascii(text);

    // Print the ASCII art
    print_ascii_art(ascii_art);

    // Free the memory allocated for the ASCII art array
    for (int i = 0; i < 100; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return 0;
}