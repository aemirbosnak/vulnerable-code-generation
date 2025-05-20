//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to generate ASCII art from text
void generateAsciiArt(char* text) {
    int index, row, col, ascii_val;
    
    // Define ASCII art characters
    char ascii_chars[10][8] = {
        {"@@@@@@@"},
        {"!   ___!_ "},
        {"!  !   !  !"},
        {"!  !   !  !"},
        {"!  !___!  !"},
        {"!        !"},
        {"!________!"},
        {"          "}
    };
    
    printf("\nASCII Art:\n\n");
    
    // Loop through each row of the ASCII art characters
    for(row = 0; row < 8; row++) {
        // Loop through each character in the input text
        for(index = 0; text[index] != '\0'; index++) {
            // Get the ASCII code for the character
            ascii_val = (int)text[index];
            
            // Check if the ASCII code is in the printable range
            if(ascii_val >= 32 && ascii_val <= 126) {
                // Get the column index for the ASCII character
                col = ascii_val - 32;
                
                // Print the corresponding character in the ASCII art
                printf("%c", ascii_chars[row][col]);
            }
        }
        // Move to the next row of the ASCII art
        printf("\n");
    }
    printf("\n");
}

int main() {
    char input_text[50];
    
    printf("Text to ASCII Art Generator\n\n");
    
    // Ask user for input text
    printf("Enter text (max. 50 characters): ");
    fgets(input_text, 50, stdin);
    printf("\nInput Text: %s\n", input_text);
    
    // Generate ASCII art from input text
    generateAsciiArt(input_text);
    
    return 0;
}