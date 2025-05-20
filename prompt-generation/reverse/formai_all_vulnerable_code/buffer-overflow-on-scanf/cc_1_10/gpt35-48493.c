//FormAI DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SIZE = 32; // Maximum binary string length

int convertBinaryToDecimal(char *binary)
{
    int decimal = 0;
    int size = strlen(binary);
    int base = 1;

    for (int i = size - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += base;
        
        base *= 2;
    }

    return decimal;
}

void convertDecimalToBinary(int decimal, char *binary)
{
    int i = 0;

    while (decimal > 0)
    {
        binary[i++] = (decimal % 2 == 0) ? '0' : '1';
        decimal /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%c", binary[j]);
}

int main()
{
    int choice;
    char binary[MAX_SIZE];
    int decimal;

    while (1)
    {
        printf("\nBinary Converter Menu\n");
        printf("=====================\n");
        printf("1. Convert Binary to Decimal\n");
        printf("2. Convert Decimal to Binary\n");
        printf("3. Quit\n");

        printf("\nEnter your choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
            case 1: // Binary to Decimal
            {
                printf("\nEnter a binary number: ");
                scanf(" %s", binary);

                int decimal = convertBinaryToDecimal(binary);

                printf("Decimal equivalent: %d\n", decimal);
                break;
            }

            case 2: // Decimal to Binary
            {
                printf("\nEnter a decimal number: ");
                scanf(" %d", &decimal);

                char *binary = (char *)malloc(sizeof(char) * MAX_SIZE);
                memset(binary, 0, MAX_SIZE);

                printf("Binary equivalent: ");
                convertDecimalToBinary(decimal, binary);
                printf("\n");
                break;
            }

            case 3: // Quit
            {
                printf("\nGoodbye!\n");
                return 0;
            }

            default: // Invalid option
            {
                printf("\nInvalid option, please try again.\n");
                break;
            }
        }
    }

    return 0;
}