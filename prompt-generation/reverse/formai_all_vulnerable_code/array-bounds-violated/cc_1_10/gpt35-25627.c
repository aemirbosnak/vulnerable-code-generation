//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000 // Maximum length of input string
#define MAX_ROWS 10 // Number of rows in output ASCII art
#define MAX_COLS 200 // Number of columns in output ASCII art

int main()
{
    char inputString[MAX_LENGTH]; // Input string
    char asciiArt[MAX_ROWS][MAX_COLS]; // Output ASCII art
    
    // Read input string
    printf("Enter a string: ");
    fgets(inputString, MAX_LENGTH, stdin);
    
    // Calculate length of input string
    int length = strlen(inputString);
    
    // Remove newline character from input string
    if(inputString[length-1] == '\n')
        inputString[--length] = '\0';
    
    // Initialize output ASCII art with spaces
    for(int i=0; i<MAX_ROWS; i++)
        for(int j=0; j<MAX_COLS; j++)
            asciiArt[i][j] = ' ';
    
    // Calculate number of characters per row
    int charsPerRow = (length + MAX_ROWS - 1) / MAX_ROWS;

    // Loop through rows and columns
    int i = 0, j = 0, k = 0;
    while(i < MAX_ROWS && k < length)
    {
        j = 0;
        while(j < charsPerRow && k < length)
        {
            asciiArt[i][j] = inputString[k++];
            j++;
        }
        i++;
    }

    // Print output ASCII art
    for(int i=0; i<MAX_ROWS; i++)
    {
        for(int j=0; j<MAX_COLS; j++)
            printf("%c", asciiArt[i][j]);
        
        printf("\n");
    }
    
    return 0; // End of program
}