//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[20];
    int i = 0;
    char output[20];
    int j = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Convert the input string to uppercase
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a')
        {
            input[i] -= 32;
        }
    }

    // Check if the input is valid
    if (!valid_hex(input))
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert the input to hexadecimal
    for (i = 0; input[i] != '\0'; i++)
    {
        int num = input[i] - '0';
        output[j] = '0' + num / 16;
        output[j + 1] = '0' + num % 16;
        j += 2;
    }

    // Print the output
    printf("Hexadecimal equivalent: ");
    for (i = 0; output[i] != '\0'; i++)
    {
        printf("%c ", output[i]);
    }

    printf("\n");

    return 0;
}

int valid_hex(char *str)
{
    int i = 0;

    // Check for invalid characters
    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] < 'a' || str[i] > 'f') && (str[i] < 'A' || str[i] > 'F') && (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
    }

    // Check for valid length
    if (strlen(str) > 20)
    {
        return 0;
    }

    return 1;
}