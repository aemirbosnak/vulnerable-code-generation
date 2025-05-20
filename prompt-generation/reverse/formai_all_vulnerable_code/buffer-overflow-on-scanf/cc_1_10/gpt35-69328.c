//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>

#define MAX_HEX_LENGTH 100

void decimalToHex(int decimalNumber)
{
    char hex[MAX_HEX_LENGTH];
    int remainder, quotient;
    int i = 0;

    while(decimalNumber != 0)
    {
        remainder = decimalNumber % 16;
        if(remainder < 10)
            hex[i++] = 48 + remainder;
        else
            hex[i++] = 55 + remainder;

        decimalNumber /= 16;
    }

    printf("Hexadecimal equivalent is: ");
    for(int j = i - 1; j >=0; j--)
        printf("%c", hex[j]);
    printf("\n");
}

void hexToDecimal(char *hexNumber)
{
    int decimalNumber = 0;
    int index = 0;
    while(hexNumber[index] != '\0')
    {
        if(hexNumber[index] >= '0' && hexNumber[index] <= '9')
        {
            decimalNumber = decimalNumber * 16 + (hexNumber[index] - '0');
        }
        else if(hexNumber[index] >= 'A' && hexNumber[index] <= 'F')
        {
            decimalNumber = decimalNumber * 16 + (hexNumber[index] - 'A' + 10);
        }
        else if(hexNumber[index] >= 'a' && hexNumber[index] <= 'f')
        {
            decimalNumber = decimalNumber * 16 + (hexNumber[index] - 'a' + 10);
        }
        else
        {
            printf("%c is an invalid hexadecimal digit\n", hexNumber[index]);
            return;
        }

        index++;
    }

    printf("Decimal equivalent is: %d\n", decimalNumber);
}

int main()
{
    printf("Welcome to the Hexadecimal Converter program!\n");
    printf("Enter 1 to convert decimal to hexadecimal\n");
    printf("Enter 2 to convert hexadecimal to decimal\n");

    int choice;
    scanf("%d", &choice);
    fflush(stdin);

    if(choice == 1)
    {
        printf("Enter a decimal number: ");
        int decimalNumber;
        scanf("%d", &decimalNumber);
        fflush(stdin);
        decimalToHex(decimalNumber);
    }
    else if(choice == 2)
    {
        char hexNumber[MAX_HEX_LENGTH];
        printf("Enter a hexadecimal number: ");
        scanf("%s", hexNumber);
        fflush(stdin);
        hexToDecimal(hexNumber);
    }
    else
    {
        printf("Invalid choice! The program will now terminate.\n");
    }

    return 0;
}