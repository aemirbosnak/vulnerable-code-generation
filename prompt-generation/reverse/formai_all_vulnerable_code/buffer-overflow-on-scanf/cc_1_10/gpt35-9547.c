//FormAI DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// function to convert binary to decimal
int binaryToDecimal(int n)
{
    int decimal = 0, base = 1, rem;
    while (n > 0) {
        rem = n % 10;
        decimal += rem * base;
        n /= 10;
        base *= 2;
    }
    return decimal;
}

int main()
{
    printf("\nBinary Converter\n");
    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion\n");

    int choice;
    printf("\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        // decimal to binary conversion
        printf("\nEnter the decimal number: ");
        int decNum;
        scanf("%d", &decNum);
        printf("Binary equivalent is: ");
        decimalToBinary(decNum);
        break;

    case 2:
        // binary to decimal conversion
        printf("\nEnter the binary number: ");
        int binNum;
        scanf("%d", &binNum);
        int dec = binaryToDecimal(binNum);
        printf("Decimal equivalent is: %d\n", dec);
        break;

    default:
        printf("\nInvalid choice. Try again!\n");
    }

    return 0;
}