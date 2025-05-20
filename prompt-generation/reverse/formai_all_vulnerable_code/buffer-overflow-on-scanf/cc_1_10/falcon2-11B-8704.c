//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to convert binary to decimal
int binaryToDecimal(char* binary)
{
    int decimal = 0;
    int i = 0;
    while (binary[i]!= '\0')
    {
        decimal += (binary[i] - '0') * (1 << (i++));
    }
    return decimal;
}

// Function to convert decimal to binary
char* decimalToBinary(int decimal)
{
    int bits = 0;
    int i = 0;
    char* binary = (char*)malloc(sizeof(char) * (decimal + 1));
    while (decimal!= 0)
    {
        bits = decimal % 2;
        binary[i] = bits + '0';
        decimal = decimal / 2;
        i++;
    }
    binary[i] = '\0';
    return binary;
}

int main()
{
    char binary[100];
    int decimal;

    printf("Enter a binary number: ");
    scanf("%s", binary);
    decimal = binaryToDecimal(binary);
    printf("The decimal equivalent of %s is: %d\n", binary, decimal);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    char binaryDecimal[100];
    decimalToBinary(decimal);
    printf("The binary equivalent of %d is: %s\n", decimal, binaryDecimal);

    free(binaryDecimal);
    return 0;
}