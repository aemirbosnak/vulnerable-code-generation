//FormAI DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include<stdio.h>
#include<math.h>

void convertDecimalToBinary(int decimalNumber) {
    int binaryNumber[32];

    int i = 0;
    while(decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }

    printf("The binary number is: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
    }
}

void convertBinaryToDecimal(int binaryNumber) {
    int decimalNumber = 0;
    int base = 1;

    while(binaryNumber > 0) {
        int lastDigit = binaryNumber % 10;
        binaryNumber = binaryNumber / 10;

        decimalNumber += lastDigit * base;
        base = base * 2;
    }

    printf("The decimal number is: %d", decimalNumber);
}

int main() {
    int choice, number;

    printf("Binary Converter Menu: \n");
    printf("1. Decimal to Binary \n");
    printf("2. Binary to Decimal \n\n");

    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the decimal number to convert: ");
            scanf("%d", &number);
            convertDecimalToBinary(number);
            break;

        case 2:
            printf("Enter the binary number to convert: ");
            scanf("%d", &number);
            convertBinaryToDecimal(number);
            break;

        default:
            printf("Invalid choice. Please enter 1 or 2.");
    }

    return 0;
}