//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

int binaryToDecimal(long long n);
long long decimalToBinary(int n);

int main()
{
    int choice, decimal;
    long long binary;

    printf("Choose an option:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            printf("%d in decimal is %lld in binary.\n", decimal, decimalToBinary(decimal));
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%lld", &binary);
            printf("%lld in binary is %d in decimal.\n", binary, binaryToDecimal(binary));
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

int binaryToDecimal(long long n)
{
    int decimal = 0, i = 0, remainder;

    while(n != 0)
    {
        remainder = n % 10;
        n /= 10;
        decimal += remainder * pow(2,i);
        ++i;
    }

    return decimal;
}

long long decimalToBinary(int n)
{
    long long binary = 0;
    int remainder, i = 1;

    while(n != 0)
    {
        remainder = n % 2;
        n /= 2;
        binary += remainder * i;
        i *= 10;
    }

    return binary;
}