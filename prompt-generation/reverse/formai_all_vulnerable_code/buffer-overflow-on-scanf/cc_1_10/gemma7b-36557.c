//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char input[MAX_BUFFER_SIZE] = "";
    char output[MAX_BUFFER_SIZE] = "";
    int input_length = 0;
    int i = 0;

    // Get the input from the user
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Calculate the length of the input
    input_length = strlen(input);

    // Convert the input to uppercase
    for (i = 0; i < input_length; i++)
    {
        input[i] = toupper(input[i]);
    }

    // Convert the input to hexadecimal
    for (i = 0; i < input_length; i++)
    {
        switch (input[i])
        {
            case 'A':
                output[i] = 'A';
                break;
            case 'B':
                output[i] = 'B';
                break;
            case 'C':
                output[i] = 'C';
                break;
            case 'D':
                output[i] = 'D';
                break;
            case 'E':
                output[i] = 'E';
                break;
            case 'F':
                output[i] = 'F';
                break;
            default:
                output[i] = '0' + input[i] - 'a';
                break;
        }
    }

    // Print the output
    printf("Hexadecimal equivalent: ");
    printf("%s\n", output);

    return 0;
}