//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

void bitwiseAND(int a, int b) {
    printf("Bitwise AND of %d and %d is: %d\n", a, b, a & b);
}

void bitwiseOR(int a, int b) {
    printf("Bitwise OR of %d and %d is: %d\n", a, b, a | b);
}

void bitwiseXOR(int a, int b) {
    printf("Bitwise XOR of %d and %d is: %d\n", a, b, a ^ b);
}

void bitwiseNOT(int a) {
    printf("Bitwise NOT of %d is: %d\n", a, ~a);
}

void leftShift(int a, int positions) {
    printf("Left shift %d by %d positions: %d\n", a, positions, a << positions);
}

void rightShift(int a, int positions) {
    printf("Right shift %d by %d positions: %d\n", a, positions, a >> positions);
}

int main() {
    int num1, num2, shiftPositions;
    char choice;

    printf("Welcome to the Bitwise Operations Program!\n");
    
    do {
        printf("\nChoose two integers for bitwise operations:\n");
        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);

        printf("\nHere are the results of bitwise operations on %d and %d:\n", num1, num2);
        bitwiseAND(num1, num2);
        bitwiseOR(num1, num2);
        bitwiseXOR(num1, num2);
        bitwiseNOT(num1);
        bitwiseNOT(num2);

        printf("Enter the number of positions to shift: ");
        scanf("%d", &shiftPositions);
        leftShift(num1, shiftPositions);
        rightShift(num1, shiftPositions);

        printf("Do you want to perform more operations? (y/n): ");
        scanf(" %c", &choice); // notice the space before %c to consume any newline character
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Bitwise Operations Program!\n");
    return 0;
}