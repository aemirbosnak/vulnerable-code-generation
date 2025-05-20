//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 80
#define MAX_ART_LENGTH 1000
#define ART_WIDTH 80

// The list of ASCII characters that we can use to create the art
char ascii_chars[] = " .,:;ox%#@";

// A function that maps a value from one range to another
int map(int value, int old_min, int old_max, int new_min, int new_max) {
    return (value - old_min) * (new_max - new_min) / (old_max - old_min) + new_min;
}

// A function that generates ASCII art from an input string 
void generate_art(char *input_string, char *art) {

    // Determine the length of the input string
    int input_length = strlen(input_string);

    // Loop through each row of the art and generate it
    int row_index = 0;
    for (int i = 0; i < MAX_ART_LENGTH; i += ART_WIDTH + 1) {

        // Loop through each character in the row and generate it
        for (int j = 0; j < ART_WIDTH; j++) {

            // Calculate the index in the input string that corresponds to this character
            int input_index = map(i+j, 0, MAX_ART_LENGTH, 0, input_length-1);

            // Get the ASCII code of the current character in the input string
            int ascii_code = input_string[input_index];

            // Map the ASCII code to an index in the ascii_chars array
            int ascii_index = map(ascii_code, 0, 127, 0, strlen(ascii_chars)-1);

            // Get the ASCII character that corresponds to the mapped index
            char ascii_char = ascii_chars[ascii_index];

            // Set the current character in the art to the ASCII character
            art[row_index * (ART_WIDTH + 1) + j] = ascii_char;
        }

        // Add a newline character to the end of the row
        art[row_index * (ART_WIDTH + 1) + ART_WIDTH] = '\n';

        // Increment the row index
        row_index++;
    }

    // Add a null terminator to the end of the art string
    art[MAX_ART_LENGTH] = '\0';
}

// The main function
int main(void) {
    char input[MAX_INPUT_LENGTH];
    char art[MAX_ART_LENGTH+1];

    // Get user input
    printf("Enter a string to convert to ASCII art: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    // Generate the ASCII art
    generate_art(input, art);

    // Print the ASCII art
    printf("%s", art);

    return 0;
}