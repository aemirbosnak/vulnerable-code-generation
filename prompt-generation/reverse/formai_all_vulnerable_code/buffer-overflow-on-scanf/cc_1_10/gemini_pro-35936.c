//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decToBin(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

// Function to convert binary to decimal
int binToDec(int n)
{
    int decimal = 0, i = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

// Driver code
int main()
{
    int choice, number;
    printf("1. Decimal to Binary\n2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            printf("Binary representation of %d: ", number);
            decToBin(number);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%d", &number);
            printf("Decimal representation of %d: %d", number, binToDec(number));
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}