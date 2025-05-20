//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void print_binary(unsigned int decimal)
{
    char binary[MAX_SIZE];
    int i = 0, j = 0;

    while (decimal > 0)
    {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    while (i > 0)
    {
        printf("%c", binary[--i]);
    }
}

int main()
{
    char input[MAX_SIZE];
    unsigned int decimal;
    int i, j;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    for (i = 0; input[i]!= '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            printf("Invalid input!\n");
            return 0;
        }
    }

    decimal = 0;

    for (i = 0, j = strlen(input) - 1; i < j; i++, j--)
    {
        decimal += (input[i] - '0') * pow(10, j);
    }

    print_binary(decimal);

    return 0;
}