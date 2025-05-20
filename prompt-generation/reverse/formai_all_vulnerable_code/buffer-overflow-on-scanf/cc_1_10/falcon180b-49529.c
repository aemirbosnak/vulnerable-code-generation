//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert text to ASCII art
void text_to_ascii_art(char* input_text, char* output_ascii_art) {
    int input_length = strlen(input_text);
    int output_length = input_length * 8; // Each character will be replaced by 8 ASCII art characters
    output_ascii_art[0] = '\0'; // Initialize output string with null character
    
    // Loop through each character in the input text
    for (int i = 0; i < input_length; i++) {
        char input_char = tolower(input_text[i]); // Convert input character to lowercase
        
        // Check if the character is a letter
        if (isalpha(input_char)) {
            // Get the ASCII value of the input character
            int ascii_value = input_char - 'a';
            
            // Append the ASCII art for the input character to the output string
            strcat(output_ascii_art, "     ");
            strcat(output_ascii_art, "... ");
            strcat(output_ascii_art, "  .. ");
            strcat(output_ascii_art, ".... ");
            strcat(output_ascii_art, "..... ");
            strcat(output_ascii_art, "...... ");
            strcat(output_ascii_art, "....... ");
            strcat(output_ascii_art, "........ ");
        } else {
            // If the character is not a letter, append a space to the output string
            strcat(output_ascii_art, "        ");
        }
    }
}

int main() {
    char input_text[100];
    char output_ascii_art[800]; // Maximum output length is 8 times the input length
    
    // Get input text from user
    printf("Enter the text to convert to ASCII art: ");
    scanf("%s", input_text);
    
    // Convert input text to ASCII art
    text_to_ascii_art(input_text, output_ascii_art);
    
    // Print the ASCII art
    printf("\n%s\n", output_ascii_art);
    
    return 0;
}