//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_hex[100];
    char output_dec[100];
    int i = 0;
    int j = 0;
    int num = 0;
    int flag = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_hex);

    // Validate input
    for (i = 0; input_hex[i] != '\0'; i++)
    {
        if (!((input_hex[i] >= 'a' && input_hex[i] <= 'f') || (input_hex[i] >= 'A' && input_hex[i] <= 'F') || (input_hex[i] >= '0' && input_hex[i] <= '9')))
        {
            flag = 1;
            break;
        }
    }

    // Convert hexadecimal to decimal
    if (!flag)
    {
        for (i = 0; input_hex[i] != '\0'; i++)
        {
            num = num * 16 + input_hex[i] - 'a' + 10;
            output_dec[j++] = num % 10 + '0';
            num /= 16;
        }

        // Print decimal number
        printf("Decimal equivalent: ");
        for (i = j - 1; i >= 0; i--)
        {
            printf("%c", output_dec[i]);
        }

        printf("\n");
    }

    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}