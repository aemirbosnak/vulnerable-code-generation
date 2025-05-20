//FormAI DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// function to convert binary to decimal
int binaryToDecimal(int n) {
    int decimalNum = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        decimalNum += rem * pow(2, i);
        ++i;
    }
    return decimalNum;
}

int main() {
    int choice, n;

    printf("Please select an option:\n");
    printf("1: Decimal to Binary\n");
    printf("2: Binary to Decimal\n");

    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter a decimal number: ");
        scanf("%d", &n);
        printf("Binary representation of %d is ", n);
        decimalToBinary(n);
    } else if (choice == 2) {
        printf("Enter a binary number: ");
        scanf("%d", &n);
        printf("Decimal representation of %d is %d", n, binaryToDecimal(n));
    } else {
        printf("Invalid choice. Please try again.");
    }

    return 0;
}