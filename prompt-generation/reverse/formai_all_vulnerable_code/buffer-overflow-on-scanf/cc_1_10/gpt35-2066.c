//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int decimal_to_binary(int decimal_number);
int binary_to_decimal(int binary_number);

int main() {
    int choice, number;
    printf("Choose an option:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &number);
            printf("Binary number: %d\n", decimal_to_binary(number));
            break;
        case 2:
            printf("Enter binary number: ");
            scanf("%d", &number);
            printf("Decimal number: %d\n", binary_to_decimal(number));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

int decimal_to_binary(int decimal_number) {
    int binary_number = 0, base = 1;
    while (decimal_number > 0) {
        binary_number = binary_number + (decimal_number % 2) * base;
        decimal_number = decimal_number / 2;
        base = base * 10;
    }
    return binary_number;
}

int binary_to_decimal(int binary_number) {
    int decimal_number = 0, base = 1;
    while (binary_number > 0) {
        decimal_number = decimal_number + (binary_number % 10) * base;
        binary_number = binary_number / 10;
        base = base * 2;
    }
    return decimal_number;
}