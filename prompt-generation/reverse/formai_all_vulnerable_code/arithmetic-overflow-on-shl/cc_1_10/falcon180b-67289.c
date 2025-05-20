//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    int sum = 0;
    int carry = 0;

    printf("Two households, both alike in dignity,\nIn fair Verona, where we lay our scene,\nFrom ancient grudge break to new mutiny,\nWhere civil blood makes civil hands unclean.\n");

    printf("\nEnter the first integer: ");
    scanf("%d", &num1);
    printf("\nEnter the second integer: ");
    scanf("%d", &num2);

    printf("\nAddition:\n");
    sum = num1 + num2;
    printf("Result: %d\n", sum);

    printf("\nSubtraction:\n");
    if (num1 > num2) {
        printf("Result: %d\n", num1 - num2);
    } else {
        printf("Result: %d\n", num2 - num1);
    }

    printf("\nMultiplication:\n");
    int product = num1 * num2;
    printf("Result: %d\n", product);

    printf("\nDivision:\n");
    if (num2 == 0) {
        printf("Result: Cannot divide by zero.\n");
    } else {
        int quotient = num1 / num2;
        int remainder = num1 % num2;
        printf("Quotient: %d\n", quotient);
        printf("Remainder: %d\n", remainder);
    }

    printf("\nBitwise AND:\n");
    int bitwise_and = num1 & num2;
    printf("Result: %d\n", bitwise_and);

    printf("\nBitwise OR:\n");
    int bitwise_or = num1 | num2;
    printf("Result: %d\n", bitwise_or);

    printf("\nBitwise XOR:\n");
    int bitwise_xor = num1 ^ num2;
    printf("Result: %d\n", bitwise_xor);

    printf("\nBitwise NOT:\n");
    int bitwise_not = ~num1;
    printf("Result: %d\n", bitwise_not);

    printf("\nBitwise Left Shift:\n");
    int bitwise_left_shift = num1 << 2;
    printf("Result: %d\n", bitwise_left_shift);

    printf("\nBitwise Right Shift:\n");
    int bitwise_right_shift = num1 >> 2;
    printf("Result: %d\n", bitwise_right_shift);

    return 0;
}