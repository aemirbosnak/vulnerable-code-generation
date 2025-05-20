//FormAI DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Convert binary number to decimal
int binaryToDecimal(int binaryNum)
{
    int decimalNum = 0, power = 0;
    
    while(binaryNum != 0)
    {
        int digit = binaryNum % 10;
        decimalNum += digit * pow(2, power++);
        binaryNum /= 10;
    }

    return decimalNum;
}

// Convert decimal number to binary
int decimalToBinary(int decimalNum)
{
    int binaryNum = 0, placeValue = 1;
    
    while(decimalNum != 0)
    {
        int rem = decimalNum % 2;
        binaryNum += rem * placeValue;
        placeValue *= 10;
        decimalNum /= 2;
    }

    return binaryNum;
}

int main()
{
    int choice, num;

    printf("Binary Converter Menu:\n");
    printf("1. Convert binary to decimal\n");
    printf("2. Convert decimal to binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a binary number: ");
            scanf("%d", &num);

            printf("Decimal equivalent of %d is %d\n", num, binaryToDecimal(num));
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &num);

            printf("Binary equivalent of %d is %d\n", num, decimalToBinary(num));
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}