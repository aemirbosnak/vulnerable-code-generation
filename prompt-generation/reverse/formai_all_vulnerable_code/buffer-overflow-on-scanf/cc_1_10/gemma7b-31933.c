//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    int i, j, k, length, input_length, is_valid = 1;
    unsigned int number;

    printf("Welcome to the C Hexadecimal Converter!\n");
    printf("Please enter a hexadecimal number: ");

    // Get the input from the user
    scanf("%s", input);

    // Calculate the length of the input
    length = strlen(input);

    // Check if the input is valid
    for (i = 0; i < length; i++)
    {
        if (!((input[i] >= 'a' && input[i] <= 'f') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= '0' && input[i] <= '9')))
        {
            is_valid = 0;
            break;
        }
    }

    // If the input is valid, convert it to an integer
    if (is_valid)
    {
        number = strtol(input, NULL, 16);

        // Convert the integer to a hexadecimal string
        sprintf(output, "The hexadecimal equivalent of %d is: %x", number, number);

        // Print the output
        printf("%s\n", output);
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}