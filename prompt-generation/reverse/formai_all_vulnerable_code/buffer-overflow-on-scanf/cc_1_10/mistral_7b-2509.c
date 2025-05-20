//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

typedef struct {
    unsigned int num1, num2;
    unsigned char operation;
} BitwiseOperators;

void PerformOperation(BitwiseOperators *bitwise) {
#ifdef PROTECTED_FUNCTION
    switch (bitwise->operation) {
        case '&':
            bitwise->num1 &= bitwise->num2;
            break;
        case '|':
            bitwise->num1 |= bitwise->num2;
            break;
        case '^':
            bitwise->num1 ^= bitwise->num2;
            break;
        case '~':
            bitwise->num1 ^= ~0;
            bitwise->num1 &= bitwise->num2;
            break;
        case '<<':
            bitwise->num1 <<= bitwise->num2 & (SIZE - 1);
            break;
        case '>>':
            bitwise->num1 >>= bitwise->num2 & (SIZE - 1);
            break;
        default:
            printf("Invalid operation! Please enter a valid bitwise operation.\n");
            exit(EXIT_FAILURE);
    }
#else
    switch (bitwise->operation) {
        case '&':
            bitwise->num1 &= bitwise->num2;
            break;
        case '|':
            bitwise->num1 |= bitwise->num2;
            break;
        case '^':
            bitwise->num1 ^= bitwise->num2;
            break;
        case '~':
            bitwise->num1 ^= ~0;
            bitwise->num1 &= bitwise->num2;
            break;
        case '<<':
            bitwise->num1 <<= bitwise->num2 & (SIZE - 1);
            break;
        case '>>':
            bitwise->num1 >>= bitwise->num2 & (SIZE - 1);
            break;
        default:
            printf("Invalid operation! Please enter a valid bitwise operation.\n");
            exit(EXIT_FAILURE);
    }
#endif
}

int main() {
    BitwiseOperators op;

    printf("Enter first number: ");
    scanf("%d", &op.num1);

    printf("Enter second number: ");
    scanf("%d", &op.num2);

    printf("Enter operation (+, &, |, ^, ~, <<, or >>): ");
    scanf(" %c", &op.operation);

    PerformOperation(&op);

    printf("Result: %d\n", op.num1);

    return 0;
}