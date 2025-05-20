//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: irregular
#include <stdio.h>

int main()
{
    char input[1000] = "";
    printf("Enter your text here: ");
    scanf("%[^\n]", input); //read until enter is pressed
    
    //initialize array of ascii characters
    char ascii[10][10] = {
        {' ', '.', '.', '.', ' ', ' ', ' ', ' ', '.'},
        {'.', ' ', '.', ' ', ' ', ' ', ' ', '.', '.'},
        {'.', '.', '.', '.', '.', ' ', '.', '.', '.'},
        {'.', '.', '.', '.', '.', ' ', '.', '.', '.'},
        {'.', ' ', '.', ' ', ' ', ' ', ' ', '.', '.'},
        {'.', ' ', '.', ' ', ' ', ' ', ' ', '.', ' '},
        {'.', ' ', '.', '.', '.', '.', '.', '.', '.'},
        {'.', ' ', '.', ' ', ' ', ' ', '.', ' ', '.'},
        {'.', '.', '.', '.', ' ', ' ', '.', '.', '.'},
        {'.', '.', '.', '.', ' ', ' ', '.', '.', '.'},
    };
    
    //loop through each character in input
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        int asciiIndex;
        //check if c is uppercase letter
        if (c >= 'A' && c <= 'Z') {
            asciiIndex = c - 'A';
        }
        //check if c is lowercase letter
        else if (c >= 'a' && c <= 'z') {
            asciiIndex = c - 'a';
        }
        //check if c is a number
        else if (c >= '0' && c <= '9') {
            asciiIndex = c - '0' + 26;
        }
        else {
            asciiIndex = 36; //set asciiIndex to question mark
        }
        
        //print corresponding ascii character row by row
        for (int j = 0; j < 10; j++) {
            printf("%c", ascii[asciiIndex][j]);
        }
        printf(" "); //add space between characters
    }
    
    return 0;
}