//FormAI DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>

void decimalToBinary(int num) {
    int binary[32];
    int i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

void binaryToDecimal(long long num) {
    int dec = 0, base = 1, rem;
    while (num > 0) {
        rem = num % 10;
        dec = dec + rem * base;
        num = num / 10;
        base = base * 2;
    }
    printf("%d", dec);
}

int main() {
    int choice;
    int num;
    long long binaryNum;
    printf("Welcome to the Binary Converter!\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter a decimal number: ");
        scanf("%d", &num);
        printf("Binary equivalent is: ");
        decimalToBinary(num);
    } else if (choice == 2) {
        printf("Enter a binary number: ");
        scanf("%lld", &binaryNum);
        printf("Decimal equivalent is: ");
        binaryToDecimal(binaryNum);
    } else {
        printf("Invalid choice!");
    }
    return 0;
}