//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of input string

int main()
{
    char inputString[MAX_SIZE]; // Input string
    char outputString[MAX_SIZE]; // Output string after manipulation
    int inputStringLength = 0; // Length of input string
    int outputStringLength = 0; // Length of output string
    int i, j; // Loop variables

    // Request user to input a string
    printf("Enter a string (maximum %d characters):\n", MAX_SIZE);
    scanf("%[^\n]", inputString);

    // Get the length of input string
    inputStringLength = strlen(inputString);

    // Manipulate the input string
    for(i = 0; i < inputStringLength; i++)
    {
        if(inputString[i] == 'a' || inputString[i] == 'A')
        {
            outputString[outputStringLength++] = '@';
        }
        else if(inputString[i] == 'e' || inputString[i] == 'E')
        {
            outputString[outputStringLength++] = '3';
        }
        else if(inputString[i] == 'i' || inputString[i] == 'I')
        {
            outputString[outputStringLength++] = '!';
        }
        else if(inputString[i] == 'o' || inputString[i] == 'O')
        {
            outputString[outputStringLength++] = '0';
        }
        else if(inputString[i] == 'u' || inputString[i] == 'U')
        {
            outputString[outputStringLength++] = '^';
        }
        else if(inputString[i] == ' ')
        {
            outputString[outputStringLength++] = '_';
        }
        else
        {
            outputString[outputStringLength++] = inputString[i];
        }
    }

    // Terminate the output string with null character
    outputString[outputStringLength] = '\0';

    // Print the results
    printf("\nManipulated String:\n%s\n", outputString);

    return 0;
}