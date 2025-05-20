//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
// Program to convert hexadecimal to decimal or binary
// Written in Donald Knuth style

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100 // Maximum length of hexadecimal input

int convertHexToDec(char hex[], int length)
{
    int decimalValue = 0;
    int base = 1;
    int i;
    for (i = length - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimalValue += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimalValue += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return decimalValue;
}

void convertHexToBin(char hex[], int length, char binary[])
{
    int i;
    for (i = 0; i < length; i++)
    {
        switch (hex[i])
        {
            case '0':
                strcat(binary, "0000");
                break;
            case '1':
                strcat(binary, "0001");
                break;
            case '2':
                strcat(binary, "0010");
                break;
            case '3':
                strcat(binary, "0011");
                break;
            case '4':
                strcat(binary, "0100");
                break;
            case '5':
                strcat(binary, "0101");
                break;
            case '6':
                strcat(binary, "0110");
                break;
            case '7':
                strcat(binary, "0111");
                break;
            case '8':
                strcat(binary, "1000");
                break;
            case '9':
                strcat(binary, "1001");
                break;
            case 'A':
                strcat(binary, "1010");
                break;
            case 'B':
                strcat(binary, "1011");
                break;
            case 'C':
                strcat(binary, "1100");
                break;
            case 'D':
                strcat(binary, "1101");
                break;
            case 'E':
                strcat(binary, "1110");
                break;
            case 'F':
                strcat(binary, "1111");
                break;
            default:
                printf("Invalid input.\n");
                return;
        }
    }
}

int main()
{
    char hex[MAX_LENGTH];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    int length = strlen(hex);
    int decimalValue = convertHexToDec(hex, length);
    printf("The decimal value of %s is: %d\n", hex, decimalValue);

    char binary[MAX_LENGTH];
    binary[0] = '\0';
    convertHexToBin(hex, length, binary);
    printf("The binary value of %s is: %s\n", hex, binary);

    return 0;
}