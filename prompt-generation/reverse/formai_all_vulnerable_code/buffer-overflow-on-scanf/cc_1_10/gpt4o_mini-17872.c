//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include <stdio.h>
#include <stdint.h>

void displayBits(uint32_t num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

uint32_t bitwiseAND(uint32_t a, uint32_t b) {
    return a & b;
}

uint32_t bitwiseOR(uint32_t a, uint32_t b) {
    return a | b;
}

uint32_t bitwiseXOR(uint32_t a, uint32_t b) {
    return a ^ b;
}

uint32_t bitwiseNOT(uint32_t a) {
    return ~a;
}

uint32_t leftShift(uint32_t a, int shift) {
    return a << shift;
}

uint32_t rightShift(uint32_t a, int shift) {
    return a >> shift;
}

void menu() {
    printf("\nBitwise Operation Menu:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
}

int main() {
    uint32_t a, b;
    int choice, shift;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) break;

        switch (choice) {
            case 1:
                printf("Enter two numbers (a b): ");
                scanf("%u %u", &a, &b);
                printf("AND Operation:\n");
                displayBits(a);
                displayBits(b);
                printf("Result:\n");
                displayBits(bitwiseAND(a, b));
                break;
            case 2:
                printf("Enter two numbers (a b): ");
                scanf("%u %u", &a, &b);
                printf("OR Operation:\n");
                displayBits(a);
                displayBits(b);
                printf("Result:\n");
                displayBits(bitwiseOR(a, b));
                break;
            case 3:
                printf("Enter two numbers (a b): ");
                scanf("%u %u", &a, &b);
                printf("XOR Operation:\n");
                displayBits(a);
                displayBits(b);
                printf("Result:\n");
                displayBits(bitwiseXOR(a, b));
                break;
            case 4:
                printf("Enter a number (a): ");
                scanf("%u", &a);
                printf("NOT Operation:\n");
                displayBits(a);
                printf("Result:\n");
                displayBits(bitwiseNOT(a));
                break;
            case 5:
                printf("Enter a number (a) and number of shifts: ");
                scanf("%u %d", &a, &shift);
                printf("Left Shift Operation:\n");
                displayBits(a);
                printf("Result:\n");
                displayBits(leftShift(a, shift));
                break;
            case 6:
                printf("Enter a number (a) and number of shifts: ");
                scanf("%u %d", &a, &shift);
                printf("Right Shift Operation:\n");
                displayBits(a);
                printf("Result:\n");
                displayBits(rightShift(a, shift));
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    printf("Exiting the program. Goodbye!\n");
    return 0;
}