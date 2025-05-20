//FormAI DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

/*
* 'ToBinary' function takes an integer and converts it to binary using 
* traditional medieval logic. It then returns the binary string.
*/
char* ToBinary(int decimal)
{
    char* binary = (char*)malloc(9);
    for (int i = 7; i >= 0; i--)
    {
        if (decimal & (1 << i))
        {
            binary[7 - i] = '1';
        }
        else
        {
            binary[7 - i] = '0';
        }
    }
    binary[8] = '\0';
    return binary;
}

// Main function
int main()
{

    int decimal;

    printf("----------------------------------------------\n");
    printf("|    Welcome to the Medieval Binary Converter  |\n");
    printf("----------------------------------------------\n");

    while (1)
    {

        printf("\nEnter a decimal number to convert to binary (0 to exit): ");
        scanf("%d", &decimal);

        if (decimal == 0)
        {
            printf("Fare thee well!\n");
            break;
        }

        printf("The binary representation of '%d' is: %s\n", decimal, ToBinary(decimal));
    }

    return 0;
}