//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[10] = "";
    int i = 0;
    int num = 0;
    int exp = 0;
    char output[20] = "";

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            num = num * 16 + input[i] - 'a' + 10;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            num = num * 16 + input[i] - 'A' + 10;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            num = num * 16 + input[i] - '0';
        }
    }

    while (num / 16)
    {
        exp++;
        num /= 16;
    }

    for (i = exp; i >= 0; i--)
    {
        int digit = num % 16;
        char hexDigit = digit + 'a' - 10;
        output[i] = hexDigit;
    }

    output[exp] = '\0';

    printf("Hexadecimal number: %s\n", output);

    return 0;
}