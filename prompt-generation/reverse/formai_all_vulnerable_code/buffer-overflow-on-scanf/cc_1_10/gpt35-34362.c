//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 8   // Number of rows
#define COLS 8   // Number of columns

char characters[] = {'$', '@', 'B', '%', '8', '*', 't', 'o', ':', '.', ' '};  // Character set

// Function to convert a character into an ASCII art
void charToASCII(char myChar)
{
    int row, col;   // Variables for rows and columns
    int index = abs(myChar) % 11;   // Get the index of the character in the character set
    
    // Loop through all the rows
    for (row = 0; row < ROWS; row++)
    {
        // Loop through all the columns
        for (col = 0; col < COLS; col++)
        {
            if ((row == 0 && col == 0) || (row == ROWS - 1 && col == COLS - 1))   // Upper left and lower right corners
            {
                printf("%c", '@');
            }
            else if ((row == ROWS - 1 && col == 0) || (row == 0 && col == COLS - 1))   // Lower left and upper right corners
            {
                printf("%c", '#');
            }
            else   // Middle of the character
            {
                int charIndex = row * COLS + col - 1;
                if (charIndex % 5 == 0 && charIndex <= strlen(characters) - 1 && charIndex >= 0)
                {
                    printf("%c", characters[index]);
                }
                else
                {
                    printf("%c", ' ');
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    char myString[50];
    printf("Enter your string (maximum 50 characters): \n");
    scanf("%s", myString);
    
    int i;
    for (i = 0; i < strlen(myString); i++)
    {
        charToASCII(myString[i]);
        printf("\n");
    }
    
    return 0;
}