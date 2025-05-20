//FormAI DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>

// This function converts decimal number to binary
void decimalToBinary(int decimalNumber) {
    int binaryNumber[20] = {0};
    int index = 0;
    while(decimalNumber > 0) {
        binaryNumber[index++] = decimalNumber % 2;
        decimalNumber /= 2;
    }
    // Printing the binary number in reverse order
    printf("\nBinary Number: ");
    for(int i=index-1; i>=0; i--) {
        printf("%d", binaryNumber[i]);
    }
}

// This function converts binary number to decimal
void binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, power = 1;
    while(binaryNumber > 0) {
        int bit = binaryNumber % 10;
        decimalNumber += bit * power;
        power *= 2;
        binaryNumber /= 10;
    }
    printf("\nDecimal Number: %d", decimalNumber);
}

int main() {
    int choice, decimalNumber;
    long long binaryNumber;
    printf("Binary Converter\n1. Decimal to Binary\n2. Binary to Decimal\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            decimalToBinary(decimalNumber);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%lld", &binaryNumber);
            binaryToDecimal(binaryNumber);
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}