//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>
#include <stdint.h>

void printBits(uint32_t num) {
    printf("Binary representation: ");
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

uint32_t bitwiseAnd(uint32_t a, uint32_t b) {
    return a & b;
}

uint32_t bitwiseOr(uint32_t a, uint32_t b) {
    return a | b;
}

uint32_t bitwiseXor(uint32_t a, uint32_t b) {
    return a ^ b;
}

uint32_t bitwiseNot(uint32_t a) {
    return ~a;
}

uint32_t leftShift(uint32_t a, int positions) {
    return a << positions;
}

uint32_t rightShift(uint32_t a, int positions) {
    return a >> positions;
}

void displayOptions() {
    printf("Choose a bitwise operation:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. LEFT SHIFT\n");
    printf("6. RIGHT SHIFT\n");
    printf("7. Exit\n");
}

int main() {
    uint32_t num1, num2;
    int choice, positions;

    printf("Welcome to the Bitwise Operations Game!\n");
    printf("Let's play with some numbers...\n");

    while (1) {
        displayOptions();
        printf("Select an option (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers (num1 num2): ");
                scanf("%u %u", &num1, &num2);
                printf("Performing AND on %u and %u...\n", num1, num2);
                printBits(num1);
                printBits(num2);
                printBits(bitwiseAnd(num1, num2));
                break;
                
            case 2:
                printf("Enter two numbers (num1 num2): ");
                scanf("%u %u", &num1, &num2);
                printf("Performing OR on %u and %u...\n", num1, num2);
                printBits(num1);
                printBits(num2);
                printBits(bitwiseOr(num1, num2));
                break;
                
            case 3:
                printf("Enter two numbers (num1 num2): ");
                scanf("%u %u", &num1, &num2);
                printf("Performing XOR on %u and %u...\n", num1, num2);
                printBits(num1);
                printBits(num2);
                printBits(bitwiseXor(num1, num2));
                break;
                
            case 4:
                printf("Enter a number (num): ");
                scanf("%u", &num1);
                printf("Performing NOT on %u...\n", num1);
                printBits(num1);
                printBits(bitwiseNot(num1));
                break;
                
            case 5:
                printf("Enter a number (num) and positions to shift (positions): ");
                scanf("%u %d", &num1, &positions);
                printf("Performing left shift on %u by %d positions...\n", num1, positions);
                printBits(num1);
                printBits(leftShift(num1, positions));
                break;

            case 6:
                printf("Enter a number (num) and positions to shift (positions): ");
                scanf("%u %d", &num1, &positions);
                printf("Performing right shift on %u by %d positions...\n", num1, positions);
                printBits(num1);
                printBits(rightShift(num1, positions));
                break;

            case 7:
                printf("Exiting the game. See you next time!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}