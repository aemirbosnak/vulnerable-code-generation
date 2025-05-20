//FormAI DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>

void decimal_to_binary(int n);
int binary_to_decimal(int n);

int main() {
    int choice, n;
    printf("Welcome to Binary Converter\n");
    printf("---------------------------\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter decimal number: ");
            scanf("%d", &n);
            printf("Binary conversion of %d is ", n);
            decimal_to_binary(n);
            break;
        case 2:
            printf("\nEnter binary number: ");
            scanf("%d", &n);
            printf("Decimal conversion of %d is %d", n, binary_to_decimal(n));
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}

void decimal_to_binary(int n) {
    int binary_digits[32], i = 0;

    while (n > 0) {
        binary_digits[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary_digits[j]);
}

int binary_to_decimal(int n) {
    int decimal = 0, base = 1, rem;

    while (n > 0) {
        rem = n % 10;
        decimal = decimal + rem * base;
        n = n / 10;
        base = base * 2;
    }

    return decimal;
}