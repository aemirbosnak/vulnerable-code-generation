//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int bitwise_and(int a, int b);
int bitwise_or(int a, int b);
int bitwise_xor(int a, int b);
int bitwise_not(int a);
int left_shift(int a, int shift);
int right_shift(int a, int shift);
void display_bits(int n);

int main() {
    int choice, a, b, shift;

    printf("Welcome to the Bitwise Operations Program!\n");
    printf("Choose an operation:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Display bits of an integer\n");
    printf("8. Exit\n");

    while (1) {
        printf("\nEnter your choice (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two integers (a b): ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", bitwise_and(a, b));
                break;
            case 2:
                printf("Enter two integers (a b): ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", bitwise_or(a, b));
                break;
            case 3:
                printf("Enter two integers (a b): ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", bitwise_xor(a, b));
                break;
            case 4:
                printf("Enter an integer (a): ");
                scanf("%d", &a);
                printf("Result: %d\n", bitwise_not(a));
                break;
            case 5:
                printf("Enter an integer (a) and number of bits to shift: ");
                scanf("%d %d", &a, &shift);
                printf("Result: %d\n", left_shift(a, shift));
                break;
            case 6:
                printf("Enter an integer (a) and number of bits to shift: ");
                scanf("%d %d", &a, &shift);
                printf("Result: %d\n", right_shift(a, shift));
                break;
            case 7:
                printf("Enter an integer (a): ");
                scanf("%d", &a);
                printf("Bits of %d: ", a);
                display_bits(a);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

int bitwise_and(int a, int b) {
    return a & b;
}

int bitwise_or(int a, int b) {
    return a | b;
}

int bitwise_xor(int a, int b) {
    return a ^ b;
}

int bitwise_not(int a) {
    return ~a;
}

int left_shift(int a, int shift) {
    return a << shift;
}

int right_shift(int a, int shift) {
    return a >> shift;
}

void display_bits(int n) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}