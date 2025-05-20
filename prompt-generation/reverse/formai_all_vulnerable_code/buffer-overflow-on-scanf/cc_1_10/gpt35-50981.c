//FormAI DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void decimalToBinary(int num) {
    int binary[32];
    int i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (i = i - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary > 0) {
        if (binary % 10 == 1) {
            decimal += base;
        }
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

int main() {
    int choice, num;

    printf("1. Decimal to binary\n");
    printf("2. Binary to decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            decimalToBinary(num);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%d", &num);
            printf("Decimal: %d\n", binaryToDecimal(num));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}