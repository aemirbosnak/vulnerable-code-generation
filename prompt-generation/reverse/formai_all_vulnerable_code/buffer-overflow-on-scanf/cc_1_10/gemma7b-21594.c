//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    char output[20];
    int i = 0;
    int j = 0;
    int number = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Validate input
    if (strlen(input) > 20)
    {
        printf("Error: input too long.\n");
        return 1;
    }

    // Convert input to uppercase
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a')
        {
            input[i] -= 32;
        }
    }

    // Calculate number of digits
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            number++;
        }
    }

    // Convert input to hexadecimal number
    if (number > 0)
    {
        for (i = 0; input[i] != '\0'; i++)
        {
            if (input[i] >= 'a')
            {
                output[j] = input[i] - 32;
                j++;
            }
            else
            {
                output[j] = input[i];
                j++;
            }
        }

        output[j] = '\0';

        printf("Hexadecimal equivalent: %s\n", output);
    }
    else
    {
        printf("Error: input is not valid.\n");
    }

    return 0;
}