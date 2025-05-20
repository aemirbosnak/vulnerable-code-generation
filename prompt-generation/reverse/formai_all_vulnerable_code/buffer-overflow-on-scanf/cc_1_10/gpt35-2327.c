//FormAI DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decToBin(int num)
{
    int binaryNum[32];
    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// Function to convert binary to decimal
void binToDec(char *binaryNum)
{
    int decimalNum = 0;
    for (int i = 0; binaryNum[i] != '\0'; i++) {
        decimalNum = decimalNum * 2 + binaryNum[i] - '0';
    }
    printf("%d", decimalNum);
}

int main()
{
    int choice, num;
    char binaryNum[32];

    printf("Enter your choice:\n");
    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Enter the Decimal Number: ");
        scanf("%d", &num);
        printf("Binary Conversion: ");
        decToBin(num);
        break;
    case 2:
        printf("Enter the Binary Number: ");
        scanf("%s", binaryNum);
        printf("Decimal Conversion: ");
        binToDec(binaryNum);
        break;
    default:
        printf("Invalid Choice!");
    }
    return 0;
}