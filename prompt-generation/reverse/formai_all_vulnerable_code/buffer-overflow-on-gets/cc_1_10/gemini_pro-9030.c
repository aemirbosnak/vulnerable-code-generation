//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char input[100];
    int i, j, k;

    // Get user input
    printf("Enter your input: ");
    gets(input);

    // Check for invalid characters
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] < 'a' || input[i] > 'z')
        {
            printf("Invalid character: %c\n", input[i]);
            return 1;
        }
    }

    // Convert input to uppercase
    for (i = 0; i < strlen(input); i++)
    {
        input[i] = toupper(input[i]);
    }

    // Remove duplicate characters
    for (i = 0; i < strlen(input); i++)
    {
        for (j = i + 1; j < strlen(input); j++)
        {
            if (input[i] == input[j])
            {
                for (k = j; k < strlen(input); k++)
                {
                    input[k] = input[k + 1];
                }
                j--;
            }
        }
    }

    // Print the sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}