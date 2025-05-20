//FormAI DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
void decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

// function to convert binary to decimal
int binaryToDecimal(long long n) {
    int decimalNum = 0, base = 1, rem;
    while (n > 0) {
        rem = n % 10;
        decimalNum += rem * base;
        n /= 10;
        base *= 2;
    }
    return decimalNum;
}

int main() {
    int choice, decimalNum;
    long long binaryNum;

    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimalNum);
            decimalToBinary(decimalNum);
            break;
        
        case 2:
            printf("Enter binary number: ");
            scanf("%lld", &binaryNum);
            decimalNum = binaryToDecimal(binaryNum);
            printf("Decimal equivalent: %d", decimalNum);
            break;

        default:
            printf("Invalid choice.");
    }

    return 0;
}