//FormAI DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>

// Converts decimal to binary recursively
void decimal_to_binary(int n) {
    if (n > 0) {
        decimal_to_binary(n / 2);
        printf("%d", n % 2);
    }
}

// Converts binary to decimal
int binary_to_decimal(int n) {
    int decimal = 0, base = 1;
    while (n > 0) {
        int last_digit = n % 10;
        n /= 10;
        decimal += last_digit * base;
        base *= 2;
    }
    return decimal;
}

int main() {
    int choice;
    do {
        printf("Please select an option:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Binary equivalent: ");
                decimal_to_binary(decimal);
                printf("\n");
                break;
            }
            case 2: {
                int binary;
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                printf("Decimal equivalent: %d\n", binary_to_decimal(binary));
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}