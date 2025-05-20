//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

void convertToHexadecimal(long decimalNumber);
void convertToDecimal(const char* hexaDecimalNumber);

int main()
{
    char choice;
    long decimalNumber = 0;
    char hexaDecimalNumber[MAX_SIZE];

    while (1)
    {
        printf("Enter 1 to Convert Decimal to Hexadecimal.\n");
        printf("Enter 2 to Convert Hexadecimal to Decimal.\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1':
                printf("Enter a decimal number: ");
                scanf("%ld", &decimalNumber);
                convertToHexadecimal(decimalNumber);
                break;

            case '2':
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexaDecimalNumber);
                convertToDecimal(hexaDecimalNumber);
                break;

            default:
                printf("Invalid choice.\n");
        }

        printf("\n");

        // Clear input buffer
        while ((getchar()) != '\n');
    }

    return 0;
}

void convertToHexadecimal(long decimalNumber)
{
    char hexadecimalNumber[MAX_SIZE];
    int i = 0, rem = 0;

    while (decimalNumber != 0)
    {
        rem = decimalNumber % 16;

        if (rem < 10)
        {
            hexadecimalNumber[i] = rem + 48;
        }
        else
        {
            hexadecimalNumber[i] = rem + 55;
        }

        i++;
        decimalNumber /= 16;
    }

    printf("Hexadecimal number is: ");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexadecimalNumber[j]);
    }
}

void convertToDecimal(const char* hexaDecimalNumber)
{
    long decimalNumber = 0;
    int length = strlen(hexaDecimalNumber);
    int base = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        if (hexaDecimalNumber[i] >= '0' && hexaDecimalNumber[i] <= '9')
        {
            decimalNumber += (hexaDecimalNumber[i] - 48) * base;
            base *= 16;
        }
        
        else if (hexaDecimalNumber[i] >= 'A' && hexaDecimalNumber[i] <= 'F')
        {
            decimalNumber += (hexaDecimalNumber[i] - 55) * base;
            base *= 16;
        }
        
        else if (hexaDecimalNumber[i] >= 'a' && hexaDecimalNumber[i] <= 'f')
        {
            decimalNumber += (hexaDecimalNumber[i] - 87) * base;
            base *= 16;
        }
    }

    printf("Decimal number is: %ld", decimalNumber);
}