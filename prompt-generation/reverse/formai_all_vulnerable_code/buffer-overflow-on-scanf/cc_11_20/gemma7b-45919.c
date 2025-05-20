//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[20];
    int i, j, num, count = 0, flag = 0;
    char hex[6];

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Check for valid input
    for (i = 0; input[i] != '\0'; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'f') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= '0' && input[i] <= '9'))
        {
            count++;
        }
        else
        {
            flag = 1;
        }
    }

    // Convert input to hexadecimal
    if (count == strlen(input) && flag == 0)
    {
        num = atoi(input);
        hex[0] = '0' + num / 16;
        hex[1] = '0' + num % 16;
        hex[2] = ':';
        hex[3] = hex[0] - 1 + 'a';
        hex[4] = hex[1] - 1 + 'a';
    }
    else
    {
        printf("Invalid input.\n");
    }

    // Print the converted hexadecimal
    if (hex[0] != '0')
    {
        printf("Converted hexadecimal: ");
        printf("%c%c:%c%c%c", hex[0], hex[1], hex[2], hex[3], hex[4]);
        printf("\n");
    }

    return 0;
}