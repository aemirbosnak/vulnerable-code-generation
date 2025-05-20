//FormAI DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>

void decimalToBinary(int decimalNumber) {
    int binaryNumber[32];
    int i = 0;
    
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
    }
    printf("\n");
}

void binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0;
    int base = 1;
    
    while (binaryNumber > 0) {
        int lastDigit = binaryNumber % 10;
        binaryNumber = binaryNumber / 10;
        decimalNumber += lastDigit * base;
        base = base * 2;
    }
    
    printf("%d\n", decimalNumber);
}

int main() {
    int choice, decimalNumber;
    long long binaryNumber;
    
    printf("Welcome to the Binary Converter Program!\n");
    printf("Please select an option:\n");
    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion\n");
    
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the decimal number you want to convert to binary: ");
            scanf("%d", &decimalNumber);
            printf("The binary conversion of %d is ", decimalNumber);
            decimalToBinary(decimalNumber);
            break;
        case 2:
            printf("Enter the binary number you want to convert to decimal: ");
            scanf("%lld", &binaryNumber);
            printf("The decimal conversion of %lld is ", binaryNumber);
            binaryToDecimal(binaryNumber);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}