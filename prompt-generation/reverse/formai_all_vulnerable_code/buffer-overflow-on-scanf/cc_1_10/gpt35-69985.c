//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>

// Define constants for the width and height of each character in the ASCII art
#define CHAR_WIDTH 5
#define CHAR_HEIGHT 7

// Function to print a single character in ASCII art
void print_char(char c) {
    static const char ascii_table[128][CHAR_HEIGHT][CHAR_WIDTH+1] = {
        // ASCII table containing the art for each character
        // This table is based on the Figlet font: http://www.figlet.org/fontdb.cgi
        // Each character is represented as a 2D array of characters (strings) with size CHAR_HEIGHT x CHAR_WIDTH+1
        // The +1 is for the null terminator at the end of each string
        // The table only contains the first 128 ASCII characters
        // Characters outside this range will be printed as a space
        
        // Character 0x20: Space
        {
            "     ",
            "     ",
            "     ",
            "     ",
            "     ",
            "     ",
            "     "
        },
        
        // Character 0x21: Exclamation mark
        {
            "     ",
            "  |  ",
            "  |  ",
            "  |  ",
            "  |  ",
            "     ",
            "  |  "
        },
        
        // Character 0x22: Double quotes
        {
            "     ",
            " | | ",
            " | | ",
            "     ",
            "     ",
            "     ",
            "     "
        },
        
        // ... and so on for the rest of the ASCII characters
        
        // Character 0x7F: Delete
        {
            "     ",
            "XXXXX",
            "XXXXX",
            "XXXXX",
            "XXXXX",
            "XXXXX",
            "XXXXX"
        }
    };
    
    // Look up the art for the given character in the ASCII table
    const char (*art)[CHAR_HEIGHT][CHAR_WIDTH+1] = &ascii_table[(int)c];
    
    // Print each row of the art, one by one
    for (int row = 0; row < CHAR_HEIGHT; row++) {
        printf("%s\n", (*art)[row]);
    }
}

int main() {
    // Get a string of text from the user
    char text[100];
    printf("Enter some text: ");
    scanf("%s", text);
    
    // Print the ASCII art for each character in the input string
    for (int i = 0; text[i] != '\0'; i++) {
        print_char(text[i]);
    }
    
    return 0;
}