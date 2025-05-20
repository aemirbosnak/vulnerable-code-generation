//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>

// Function to convert text to ASCII art
void textToASCII(char* text) {

    // Array to store ASCII art
    char asciiArt[5][100];

    // Initialize ASCII art array with empty spaces
    for(int i=0; i<5; i++) {
        for(int j=0; j<100; j++) {
            asciiArt[i][j] = ' ';
        }
    }

    // Convert each character of text to ASCII art using switch case
    for(int i=0; text[i]!='\0'; i++) {
        switch(text[i]) {
            case 'A':
                asciiArt[0][i*6+2] = '/';
                asciiArt[1][i*6+1] = '/';
                asciiArt[1][i*6+2] = '_';
                asciiArt[1][i*6+3] = '\\';
                asciiArt[2][i*6] = '/';
                asciiArt[2][i*6+2] = '|';
                asciiArt[2][i*6+4] = '\\';
                asciiArt[3][i*6] = '|';
                asciiArt[3][i*6+2] = '|';
                asciiArt[3][i*6+4] = '|';
                asciiArt[4][i*6] = '|';
                asciiArt[4][i*6+4] = '|';
                break;
            case 'B':
                asciiArt[0][i*6] = '|';
                asciiArt[0][i*6+1] = '_';
                asciiArt[0][i*6+2] = '_';
                asciiArt[0][i*6+3] = '|';
                asciiArt[1][i*6] = '|';
                asciiArt[1][i*6+1] = '_';
                asciiArt[1][i*6+2] = '_';
                asciiArt[1][i*6+3] = '\\';
                asciiArt[2][i*6] = '|';
                asciiArt[2][i*6+1] = '|';
                asciiArt[2][i*6+2] = '_';
                asciiArt[2][i*6+3] = '|';
                asciiArt[3][i*6] = '|';
                asciiArt[3][i*6+1] = '_';
                asciiArt[3][i*6+2] = '_';
                asciiArt[3][i*6+3] = '/';
                asciiArt[4][i*6] = '|';
                asciiArt[4][i*6+1] = '_';
                asciiArt[4][i*6+2] = '_';
                asciiArt[4][i*6+3] = '|';
                break;
            case 'C':
                asciiArt[0][i*6+2] = '_';
                asciiArt[0][i*6+3] = '_';
                asciiArt[1][i*6] = '/';
                asciiArt[1][i*6+2] = '|';
                asciiArt[2][i*6] = '|';
                asciiArt[3][i*6] = '|';
                asciiArt[4][i*6] = '\\';
                asciiArt[4][i*6+2] = '|';
                break;
            case 'D':
                asciiArt[0][i*6] = '|';
                asciiArt[0][i*6+1] = '_';
                asciiArt[0][i*6+2] = '_';
                asciiArt[0][i*6+3] = '|';
                asciiArt[1][i*6] = '|';
                asciiArt[1][i*6+1] = '\\';
                asciiArt[2][i*6] = '|';
                asciiArt[3][i*6] = '|';
                asciiArt[4][i*6] = '|';
                asciiArt[4][i*6+1] = '_';
                asciiArt[4][i*6+2] = '_';
                asciiArt[4][i*6+3] = '|';
                break;
            case 'E':
                asciiArt[0][i*6] = '|';
                asciiArt[0][i*6+1] = '_';
                asciiArt[0][i*6+2] = '_';
                asciiArt[0][i*6+3] = '_';
                asciiArt[1][i*6] = '|';
                asciiArt[1][i*6+1] = '_';
                asciiArt[2][i*6] = '|';
                asciiArt[3][i*6] = '|';
                asciiArt[3][i*6+1] = '_';
                asciiArt[4][i*6] = '|';
                asciiArt[4][i*6+1] = '_';
                asciiArt[4][i*6+2] = '_';
                asciiArt[4][i*6+3] = '_';
                break;
            case 'F':
                asciiArt[0][i*6] = '|';
                asciiArt[0][i*6+1] = '_';
                asciiArt[0][i*6+2] = '_';
                asciiArt[0][i*6+3] = '_';
                asciiArt[1][i*6] = '|';
                asciiArt[1][i*6+1] = '_';
                asciiArt[2][i*6] = '|';
                asciiArt[3][i*6] = '|';
                asciiArt[4][i*6] = '|';
                break;
            // Add more character cases here...
            default:
                // If the character is not recognized, leave a space
                break;
        }
    }

    // Print the ASCII art
    for(int i=0; i<5; i++) {
        for(int j=0; asciiArt[i][j]!='\0'; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Input text to convert to ASCII art
    char text[] = "HELLO WORLD";

    // Call the textToASCII function to convert text to ASCII art
    textToASCII(text);

    return 0;
}