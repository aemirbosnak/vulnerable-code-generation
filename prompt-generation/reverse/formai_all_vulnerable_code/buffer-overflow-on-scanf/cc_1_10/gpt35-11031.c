//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>

/* Function to convert decimal to hexadecimal */
void DecToHex(int decimal_number)
{
    char hexaDecimal[100];
    int index = 0;

    while(decimal_number > 0)
    {
        int remainder = decimal_number % 16;

        if(remainder < 10)
        {
            hexaDecimal[index++] = remainder + 48;
        }
        else
        {
            hexaDecimal[index++] = remainder + 55;
        }

        decimal_number /= 16;
    }

    printf("Hexadecimal Equivalent: ");
    for(int i = index - 1; i >= 0; i--)
    {
        printf("%c", hexaDecimal[i]);
    }
}

/* Function to convert hexadecimal to decimal */
void HexToDec(char hexaDecimal[])
{
    int decimal_number = 0;
    int base = 1;

    int len = strlen(hexaDecimal);

    for(int i = len - 1; i >= 0; i--)
    {
        if(hexaDecimal[i] >= '0' && hexaDecimal[i] <= '9')
        {
            decimal_number += (hexaDecimal[i] - 48) * base;
            base *= 16;
        }
        else if(hexaDecimal[i] >= 'A' && hexaDecimal[i] <= 'F')
        {
            decimal_number += (hexaDecimal[i] - 55) * base;
            base *= 16;
        }
    }

    printf("Decimal Equivalent: %d", decimal_number);
}

int main()
{
    int choice, decimal_number;
    char hexaDecimal[100];

    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimal_number);

            DecToHex(decimal_number);
            break;

        case 2:
            printf("Enter hexadecimal number: ");
            scanf("%s", hexaDecimal);

            HexToDec(hexaDecimal);
            break;

        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}