//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: distributed
#include <stdio.h>
#include <string.h>

// function to print ASCII art for given text
void printArt(char text[]) {
    // define 2D array to store the ASCII art for each character
    char art[7][7] = {
        {' ', ' ', '/', '-', '\\', ' ', ' '},
        {' ', '/', ' ', ' ', ' ', '\\', ' '},
        {'|', ' ', 'O', ' ', 'O', ' ', '|'},
        {' ', '\\', ' ', '_', ' ', '/', ' '},
        {' ', ' ', '\\', ' ', '/', ' ', ' '},
        {' ', ' ', ' ', '\\', '/', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    
    // loop through each character in the text
    for (int i = 0; i < strlen(text); i++) {
        // get ASCII value of current character
        int asciiVal = (int) text[i];
        
        // subtract 65 from ASCII value to get index in the art array (A = 65)
        int artIndex = asciiVal - 65;
        
        // if character is not a letter, print a space instead
        if (artIndex < 0 || artIndex > 25) {
            printf("       ");
            continue;
        }
        
        // loop through each row in the art array for the current character
        for (int j = 0; j < 7; j++) {
            // loop through each column in the art array for the current character
            for (int k = 0; k < 7; k++) {
                // print the current element of the art array
                printf("%c", art[j][k]);
            }
            // print a new line after each row of the art array
            printf("\n");
        }
    }
}

int main() {
    // get input text from user
    char text[100];
    printf("Enter text to convert to ASCII art: ");
    scanf("%s", text);
    
    // call function to print ASCII art for input text
    printArt(text);
    
    return 0;
}