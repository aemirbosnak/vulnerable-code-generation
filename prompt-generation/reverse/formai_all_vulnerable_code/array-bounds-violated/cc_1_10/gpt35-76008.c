//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert characters to ASCII art
void ascii_art(char ch) {
    // Array of ASCII art for each character
    char* char_art[] = {
        // ASCII art for 'A'
        "    /\\    \n"
        "   /  \\   \n"
        "  /----\\  \n"
        " /      \\ \n"
        "/        \\\n",
        
        // ASCII art for 'B'
        " |-----\\  \n"
        " |      \\ \n"
        " |-----/  \n"
        " |      \\ \n"
        " |______/ \n",
        
        // ASCII art for 'C'
        "   /----\\ \n"
        "  /       \n"
        " /        \n"
        " |        \n"
        " \\----\\  \n",
        
        // ASCII art for 'D'
        " |----\\   \n"
        " |     \\  \n"
        " |      \\ \n"
        " |     /  \n"
        " |____/   \n",
        
        // ASCII art for 'E'
        " |------ \n"
        " |       \n"
        " |------ \n"
        " |       \n"
        " |------ \n",
        
        // ASCII art for 'F'
        " |------ \n"
        " |       \n"
        " |------ \n"
        " |       \n"
        " |       \n",
    };
    
    // Convert character to uppercase
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    
    if (ch >= 'A' && ch <= 'Z') {
        // Print ASCII art for the character
        printf("%s", char_art[ch - 'A']);
    } else {
        printf("   /\n"
               "  /  \n"
               " /   \n"
               "/    \n");
    }
}

int main() {
    char input[50];
    
    printf("Enter a string: ");
    fgets(input, 50, stdin);
    
    printf("\nASCII ART:\n");
    
    // Loop through each character in the string and print the ASCII art
    for (int i = 0; i < strlen(input); i++) {
        ascii_art(input[i]);
    }
    
    return 0;
}