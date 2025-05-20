//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void inv_hex_converter(int argc, char *argv[])
{
    char input[1024];
    int i, j, k, offset = 0, is_neg = 0;
    long int num = 0;

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
        else
        {
            printf("Invalid input.\n");
            exit(1);
        }

        offset++;
    }

    if (offset == 0)
    {
        printf("No hexadecimal digits found.\n");
        exit(1);
    }

    if (num < 0)
    {
        is_neg = 1;
        num = -num;
    }

    printf("Hexadecimal number: ");
    for (j = 0; num / 16 > 0; j++)
    {
        k = num % 16;
        printf("%x ", k);
        num /= 16;
    }

    if (!is_neg)
    {
        printf("0x");
    }

    printf("\n");
}

int main()
{
    inv_hex_converter(0, NULL);
    return 0;
}