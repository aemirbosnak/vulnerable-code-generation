//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This program converts input text into ASCII art by replacing each character with a block of characters.
  The block of characters used is a 5x3 matrix where each element is either a space or a block character.
*/

// Matrix containing the ASCII art characters
const char ASCII_ART[26][15] = {
    {" ██╗\n███║\n╚██║\n ██║\n ██║\n ╚═╝\n"},
    {"█████╗\n██╔══██╗\n███████║\n██╔══██║\n██║  ██║\n╚═╝  ╚═╝\n"},
    {" ██████╗\n██╔════╝\n██║     \n██║     \n╚██████╗\n ╚═════╝\n"},
    {"██████╗\n██╔═══╝\n██║    \n██║    \n██████╗\n╚═════╝\n"},
    {"██╗  ██╗\n██║ ██╔╝\n█████╔╝ \n██╔═██╗ \n██║  ██╗\n╚═╝  ╚═╝\n"},
    {"██████╗\n██╔═══╝\n██████╗\n██╔═══╝\n██████╗\n╚═════╝\n"},
    {" ██╗\n███║\n╚██║\n ██║\n ██║\n ╚═╝\n"},
    {" █████╗\n██╔══██╗\n███████║\n██╔══██║\n██║  ██║\n╚═╝  ╚═╝\n"},
    {" ██╗\n██║\n██║\n██║\n╚█████╗\n ╚════╝\n"},
    {"    ██╗\n    ██║\n███████║\n╚════██║\n     ██║\n     ╚═╝\n"},
    {"██╗   ██╗\n╚██╗ ██╔╝\n ╚████╔╝ \n  ╚██╔╝  \n   ██║   \n   ╚═╝   \n"},
    {"██╗   ██╗\n╚██╗ ██╔╝\n ╚████╔╝ \n  ╚██╔╝  \n   ██║   \n   ╚═╝   \n"},
    {"██████╗\n██╔═══╝\n██████╗\n██╔═══╝\n██████╗\n╚═════╝\n"},
    {"██████╗\n██╔═══╝\n██████╗\n██╔═══╝\n██║    \n╚═╝    \n"},
    {" ██████╗\n██╔════╝\n██║ ███╗\n██║   ██║\n╚██████╔╝\n ╚═════╝\n"},
    {"██╗  ██╗\n██║  ██║\n███████║\n██╔══██║\n██║  ██║\n╚═╝  ╚═╝\n"},
    {" █████╗\n██╔══██╗\n██║  ██║\n██║  ██║\n╚█████╔╝\n ╚════╝\n"},
    {" █████╗\n██╔══██╗\n██║  ██║\n██║  ██║\n╚███╔███╔╝\n ╚════╝\n"},
    {"██╗   ██╗\n██║   ██║\n██║   ██║\n██║   ██║\n╚██████╔╝\n ╚═════╝\n"},
    {"██╗  ██╗\n██║  ██║\n███████║\n██╔══██║\n██║  ██║\n╚═╝  ╚═╝\n"},
    {"██╗\n██║\n██║\n██║\n██║\n╚═╝\n"},
    {"     ██╗\n     ██║\n     ██║\n██   ██║\n╚█████╔╝\n ╚════╝\n"},
    {"██╗   ██╗\n╚██╗ ██╔╝\n ╚████╔╝ \n  ╚██╔╝  \n   ██║   \n   ╚═╝   \n"},
    {"██╗  ██╗\n╚██╗ ██╔╝\n ╚████╔╝ \n  ██╔╝   \n██╔╝    \n╚═╝     \n"},
    {"███╗\n██╔╝\n██║\n██║\n███║\n╚══╝\n"},
    {"     ██╗\n     ██║\n     ██║\n██   ██║\n╚█████╔╝\n ╚════╝\n"},
    {"██████╗\n╚════██╗\n █████╔╝\n██╔═══╝ \n███████╗\n╚══════╝\n"}
};

int main() {
    char input[100]; // Input text
    int input_length; // Length of input text
    int i, j, k; // Index variables

    // Prompt the user for input text
    printf("Enter input text: ");
    scanf("%[^\n]", input);

    input_length = strlen(input);

    // Loop over each row of the ASCII art character matrix
    for(i = 0; i < 3; i++) {
        // Loop over each character in the input text
        for(j = 0; j < input_length; j++) {
            // Get the index of the current character in the ASCII table
            k = input[j] - 'a';

            // If the current character is a space, print five spaces
            if(input[j] == ' ') {
                printf("     ");
            }
            // If the current character is not in the ASCII table, print an error message
            else if(k < 0 || k > 25) {
                printf("ERROR ");
            }
            // Otherwise, print the corresponding ASCII art character for the current character
            else {
                printf("%c", ASCII_ART[k][5*i]);
                printf("%c", ASCII_ART[k][5*i+1]);
                printf("%c", ASCII_ART[k][5*i+2]);
                printf("%c", ASCII_ART[k][5*i+3]);
                printf("%c", ASCII_ART[k][5*i+4]);
            }
        }

        printf("\n");
    }
    
    return 0;
}