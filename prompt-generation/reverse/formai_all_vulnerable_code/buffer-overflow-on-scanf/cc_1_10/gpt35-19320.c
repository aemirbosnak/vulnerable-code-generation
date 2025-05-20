//FormAI DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>

#define MAX_BITS 8

int bits[MAX_BITS];

void reset_bits() {
    for (int i = 0; i < MAX_BITS; i++) {
        bits[i] = 0;
    }
}

void print_bits() {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
}

void dec_to_bin(int n) {
    reset_bits();

    for (int i = 0; n > 0; i++) {
        bits[i] = n % 2;
        n /= 2;
    }

    print_bits();
}

int bin_to_dec() {
    int n = 0;

    for (int i = 0; i < MAX_BITS; i++) {
        if (bits[i] == 1) {
            n += 1 << i;
        }
    }

    return n;
}

int main() {
    int choice, n;

    while (1) {
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the Decimal number: ");
                scanf("%d", &n);
                printf("Binary: ");
                dec_to_bin(n);
                break;
            case 2:
                printf("Enter the Binary number (8 bit): ");
                for (int i = MAX_BITS - 1; i >= 0; i--) {
                    scanf("%1d", &bits[i]);
                }
                printf("Decimal: %d\n", bin_to_dec());
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}