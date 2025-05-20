//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
/* Hexadecimal Converter */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Prototype Declarations */
int HexToDec(char *hexNum, int len);
void DecToHex(int decNum);

int main()
{
    char hexNum[10];
    int decimal = 0, len = 0;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexNum);
    
    /* Validate Input */
    len = strlen(hexNum);
    for (int i = 0; i < len; i++)
    {
        hexNum[i] = toupper(hexNum[i]);
        if (!(hexNum[i] >= '0' && hexNum[i] <= '9') && !(hexNum[i] >= 'A' && hexNum[i] <= 'F'))
        {
            printf("Invalid Input. Please enter a valid hexadecimal number.\n");
            exit(1);
        }
    }

    /* Call HexToDec Function */
    decimal = HexToDec(hexNum, len);
    printf("Decimal Conversion: %d\n", decimal);

    /* Call DecToHex Function */
    printf("Hexadecimal Conversion: ");
    DecToHex(decimal);
    printf("\n");

    return 0;
}

/* HexToDec Function */
int HexToDec(char *hexNum, int len)
{
    int decimal = 0, base = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (hexNum[i] >= '0' && hexNum[i] <= '9')
        {
            decimal += (hexNum[i] - '0') * base;
            base *= 16;
        }
        else if (hexNum[i] >= 'A' && hexNum[i] <= 'F')
        {
            decimal += (hexNum[i] - 55) * base;
            base *= 16;
        }
    }
    return decimal;
}

/* DecToHex Function */
void DecToHex(int decNum)
{
    char hexNum[10];
    int rem, len = 0;

    while (decNum != 0)
    {
        rem = decNum % 16;
        if (rem < 10)
            hexNum[len++] = 48 + rem;
        else
            hexNum[len++] = 55 + rem;
        decNum = decNum / 16;
    }

    /* Print Hexadecimal Number */
    for (int i = len - 1; i >= 0; i--)
        printf("%c", hexNum[i]);
}