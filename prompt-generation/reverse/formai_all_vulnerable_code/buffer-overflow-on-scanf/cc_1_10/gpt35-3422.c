//FormAI DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <math.h>

// function to convert binary to decimal
int binaryToDecimal(int binary)
{
    int decimal = 0, power = 0;
    while (binary != 0)
    {
        int digit = binary % 10;
        decimal += digit * pow(2, power);
        ++power;
        binary /= 10;
    }
    return decimal;
}

// function to convert decimal to binary
long long decimalToBinary(int decimal)
{
    long long binary = 0;
    int remainder, i = 1;
    while (decimal != 0)
    {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

int main()
{
    int option;
    printf("Welcome to the Binary Converter Program!\n");
    printf("Please choose an option:\n1. Convert Binary to Decimal\n2. Convert Decimal to Binary\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
    {
        int binary;
        printf("Please enter a binary number: ");
        scanf("%d", &binary);
        printf("The decimal equivalent of %d is %d.\n", binary, binaryToDecimal(binary));
        break;
    }
    case 2:
    {
        int decimal;
        printf("Please enter a decimal number: ");
        scanf("%d", &decimal);
        printf("The binary equivalent of %d is %lld.\n", decimal, decimalToBinary(decimal));
        break;
    }
    default:
        printf("Invalid option selected!\n");
        break;
    }
    return 0;
}