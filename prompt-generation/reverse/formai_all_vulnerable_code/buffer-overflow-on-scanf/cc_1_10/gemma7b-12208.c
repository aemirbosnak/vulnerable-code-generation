//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    char output[100];
    int i, j, k, l, n, hex_value;
    int flag = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    n = strlen(input);

    for (i = 0; i < n; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            flag = 1;
            hex_value = input[i] - 'a' + 10;
            output[k] = hex_value + 0x30;
            k++;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            flag = 1;
            hex_value = input[i] - 'A' + 10;
            output[k] = hex_value + 0x30;
            k++;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            flag = 1;
            hex_value = input[i] - '0';
            output[k] = hex_value + 0x30;
            k++;
        }
    }

    if (flag == 0)
    {
        printf("Invalid input.\n");
    }
    else
    {
        output[k] = '\0';
        printf("Hexadecimal equivalent: %s\n", output);
    }

    return 0;
}