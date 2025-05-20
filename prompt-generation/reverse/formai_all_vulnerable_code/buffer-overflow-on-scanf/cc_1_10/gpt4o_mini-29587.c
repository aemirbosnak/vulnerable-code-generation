//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\nBitwise Operations Menu:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
    printf("Select an operation (1-7): ");
}

unsigned int bitwiseAnd(unsigned int a, unsigned int b) {
    return a & b;
}

unsigned int bitwiseOr(unsigned int a, unsigned int b) {
    return a | b;
}

unsigned int bitwiseXor(unsigned int a, unsigned int b) {
    return a ^ b;
}

unsigned int bitwiseNot(unsigned int a) {
    return ~a;
}

unsigned int leftShift(unsigned int a, int shift) {
    return a << shift;
}

unsigned int rightShift(unsigned int a, int shift) {
    return a >> shift;
}

int main() {
    unsigned int num1, num2, result;
    int operation, shift;

    while (1) {
        displayMenu();
        scanf("%d", &operation);

        if (operation == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (operation) {
            case 1: // Bitwise AND
                printf("Enter two integers (separated by space): ");
                scanf("%u %u", &num1, &num2);
                result = bitwiseAnd(num1, num2);
                printf("Result of %u AND %u = %u\n", num1, num2, result);
                break;

            case 2: // Bitwise OR
                printf("Enter two integers (separated by space): ");
                scanf("%u %u", &num1, &num2);
                result = bitwiseOr(num1, num2);
                printf("Result of %u OR %u = %u\n", num1, num2, result);
                break;

            case 3: // Bitwise XOR
                printf("Enter two integers (separated by space): ");
                scanf("%u %u", &num1, &num2);
                result = bitwiseXor(num1, num2);
                printf("Result of %u XOR %u = %u\n", num1, num2, result);
                break;

            case 4: // Bitwise NOT
                printf("Enter an integer: ");
                scanf("%u", &num1);
                result = bitwiseNot(num1);
                printf("Result of NOT %u = %u\n", num1, result);
                break;

            case 5: // Left Shift
                printf("Enter an integer and shift amount: ");
                scanf("%u %d", &num1, &shift);
                result = leftShift(num1, shift);
                printf("Result of %u left shifted by %d = %u\n", num1, shift, result);
                break;

            case 6: // Right Shift
                printf("Enter an integer and shift amount: ");
                scanf("%u %d", &num1, &shift);
                result = rightShift(num1, shift);
                printf("Result of %u right shifted by %d = %u\n", num1, shift, result);
                break;

            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }
    
    return 0;
}