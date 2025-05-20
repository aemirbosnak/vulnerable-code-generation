//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our ASCII art characters
const char* ascii_chars[] = {
    " _  _  _  _  _  _  _  _  _ \n"
    "| || || || || || || || || |\n"
    "|_||_||_||_||_||_||_||_||_|",
    
    " ___  ___ \n"
    "|___||___|\n"
    "|   ||___|\n",

    "  ___  \n"
    " / _ \\ \n"
    "| | | |\n"
    "| |_| |\n"
    " \\___/ ",

    " _____ \n" 
    "|   __|\n"
    "|__   |\n"
    "|_____|\n",

    "  ___  \n"
    " / _ \\ \n"
    "| |_| |\n"
    "|  _  |\n"
    "|_| |_|",

    " _____ \n"
    "|   __|\n"
    "|   __|\n"
    "|__|   \n",

    "  ___  \n"
    " / _ \\ \n"
    "| | | |\n"
    "| |_| |\n"
    " \\__  |\n"
    "    |_|",
    
    " _____ \n"
    "|  ___|\n"
    "|___ \\ \n"
    "    \\_\\",
    
    " __   __\n"
    "|  \\ /  |\n"
    "|   |   |\n"
    "|__/ \\__|",
    
    " _   _ \n"
    "| \\ | |\n"
    "|  \\| |\n"
    "| |\\  |\n"
    "|_| \\_|"
};

// Function to generate ASCII art from text
void generate_art(char* text) {
    // Loop through each character in the text
    for(int i=0; i<strlen(text); i++) {
        // Convert the character to uppercase
        char c = toupper(text[i]);
        
        // If the character is a letter between A-Z, print the corresponding ASCII art character
        if(c>='A' && c<='Z') {
            printf("%s\n", ascii_chars[c-'A']);
        }
        // If the character is not a letter, print an empty line
        else {
            printf("\n");
        }
    }
}

int main() {
    // Get input text from the user
    char text[100];
    printf("Enter text: ");
    fgets(text, 100, stdin);
    
    // Generate the ASCII art from the input text
    generate_art(text);
    
    return 0;
}