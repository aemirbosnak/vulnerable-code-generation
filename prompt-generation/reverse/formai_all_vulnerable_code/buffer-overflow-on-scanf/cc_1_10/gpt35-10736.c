//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
// Defining a maximum input length for the string

int main()
{
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];
    int choice, i;
    printf("Enter the string to be processed: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    // Taking input from the user using fgets to avoid buffer overflow
    
    printf("\nEnter the processing choice:\n1. Remove Spaces\n2. Replace Spaces with Underscores\n3. Reverse the String\nEnter your choice: ");
    scanf("%d", &choice);
    // Taking the processing choice from the user
    
    switch(choice)
    {
        case 1:  // Removing spaces from the input string
            for(i=0; input[i]!='\0'; i++)
            {
                if(input[i] != ' ')  
                {
                    output[i] = input[i];
                }
            }
            output[i] = '\0';
            // End the output string with '\0' character
            printf("\nOutput string with spaces removed: %s\n", output);
            break;
            
        case 2:  // Replacing spaces with underscores in the input string
            for(i=0; input[i]!='\0'; i++)
            {
                if(input[i] == ' ')
                {
                    output[i] = '_';
                }
                else
                {
                    output[i] = input[i];
                }
            }
            output[i] = '\0';
            printf("\nOutput string with spaces replaced with underscores: %s\n", output);
            break;
            
        case 3:  // Reversing the input string
            for(i=0; input[i]!='\0'; i++)
            {
                output[i] = input[strlen(input)-1-i];
            }
            output[i] = '\0';
            printf("\nOutput string reversed: %s\n", output);
            break;
            
        default:  // Handling invalid choice
            printf("\nInvalid choice!\n");
    }

    return 0;
}