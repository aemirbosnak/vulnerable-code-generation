//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>

int binaryToDecimal(int binary)
{
    int decimal = 0, base = 1;

    while (binary > 0)
    {
        int rem = binary % 10;
        decimal += rem * base;
        binary /= 10;
        base *= 2;
     }

    return decimal;
}

int decimalToBinary(int decimal)
{
    int binary = 0, base = 1;

    while (decimal > 0)
    {
        int rem = decimal % 2;
        binary += rem * base;
        decimal /= 2;
        base *= 10;
    }

    return binary;
}

int main()
{
    int choice;
    printf("Welcome to the Binary Converter!\n");
    printf("1. Convert Binary to Decimal\n");
    printf("2. Convert Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            {
                int binary;
                printf("Enter the binary number to convert: ");
                scanf("%d", &binary);
                printf("Decimal equivalent of %d is %d", binary, binaryToDecimal(binary));
                break;
            }
        case 2:
            {
                int decimal;
                printf("Enter the decimal number to convert: ");
                scanf("%d", &decimal);
                printf("Binary equivalent of %d is %d", decimal, decimalToBinary(decimal));
                break;
            }
        default:
            printf("Invalid choice! Please try again.");
    }

    return 0;
}