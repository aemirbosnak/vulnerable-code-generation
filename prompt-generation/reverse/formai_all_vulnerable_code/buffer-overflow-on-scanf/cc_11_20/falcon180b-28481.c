//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define MAX_SIZE 1000

int main()
{
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int i, j, k;
    int decimal, binary[MAX_SIZE];
    int length;
    char *ptr;
    int choice;

    printf("Please enter a decimal number (up to %d digits): ", MAX_SIZE);
    fgets(input, MAX_SIZE, stdin);

    length = strlen(input);
    if (length == 0 || input[0] == '\n')
    {
        printf("Error: Please enter a valid decimal number.\n");
        return 1;
    }

    for (i = 0; i < length; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Error: Please enter a valid decimal number.\n");
            return 1;
        }
    }

    decimal = atoi(input);

    if (decimal == 0)
    {
        printf("Binary representation: 0\n");
        return 0;
    }

    memset(binary, 0, sizeof(binary));
    j = 0;

    while (decimal > 0)
    {
        binary[j++] = decimal % 2;
        decimal /= 2;
    }

    length = j;
    for (i = 0; i < length; i++)
    {
        output[i] = binary[length - i - 1] + '0';
    }
    output[i] = '\0';

    printf("Binary representation: %s\n", output);

    printf("Do you want to convert the binary number back to decimal? (y/n) ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        int binary_decimal = 0;
        i = 0;

        while (output[i]!= '\0')
        {
            binary_decimal += output[i] - '0';
            binary_decimal *= 2;
            i++;
        }

        printf("Decimal representation: %d\n", binary_decimal);
    }

    return 0;
}