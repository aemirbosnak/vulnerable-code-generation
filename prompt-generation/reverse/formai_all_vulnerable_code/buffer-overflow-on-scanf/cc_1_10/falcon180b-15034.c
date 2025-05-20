//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE_LENGTH 32
#define MAX_BINARY_LENGTH 9

unsigned char GetChar(char *value, int index)
{
    if (index >= strlen(value))
    {
        printf("Error: Invalid value\n");
        exit(1);
    }

    return (unsigned char)value[index];
}

void ConvertBinaryToDecimal(char *binary, int binaryLength, char *decimal)
{
    int decimalValue = 0;
    int power = 0;

    for (int i = binaryLength - 1; i >= 0; i--)
    {
        int bitValue = GetChar(binary, i) - '0';
        decimalValue += bitValue * (int)pow(2, power);
        power++;
    }

    sprintf(decimal, "%d", decimalValue);
}

void ConvertDecimalToBinary(int decimal, char *binary)
{
    int binaryValue = 0;
    int power = 0;

    while (decimal > 0)
    {
        int bitValue = decimal % 2;
        binaryValue += bitValue * (int)pow(2, power);
        decimal /= 2;
        power++;
    }

    sprintf(binary, "%d", binaryValue);
}

int main()
{
    char value[MAX_VALUE_LENGTH];
    char binary[MAX_BINARY_LENGTH];
    char decimal[MAX_VALUE_LENGTH];

    printf("Enter a value to convert:\n");
    scanf("%s", value);

    if (strlen(value) > MAX_VALUE_LENGTH)
    {
        printf("Error: Value is too long\n");
        exit(1);
    }

    ConvertDecimalToBinary(strtoul(value, NULL, 10), binary);
    ConvertBinaryToDecimal(binary, strlen(binary), decimal);

    printf("Decimal: %s\n", decimal);
    printf("Binary: %s\n", binary);

    return 0;
}