//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define SWAP(x, y) do { uint32_t t = (x); (x) = (y); (y) = t; } while (0)

typedef struct {
    uint32_t a;
    uint32_t b;
} BitwiseOperators;

void print_binary(uint32_t value) {
    int i;
    for (i = 31; i >= 0; i--) {
        putchar(value & (1 << i) ? '1' : '0');
    }
    putchar('\n');
}

void perform_bitwise_operation(BitwiseOperators *operators, char op) {
    switch (op) {
        case '&':
            operators->a &= operators->b;
            break;
        case '|':
            operators->a |= operators->b;
            break;
        case '^':
            operators->a ^= operators->b;
            break;
        case '~':
            operators->a ^= ~operators->b;
            break;
        case '<<':
            operators->a <<= operators->b & 31;
            break;
        case '>>':
            operators->a >>= operators->b & 31;
            break;
        default:
            fprintf(stderr, "Invalid operator: %c\n", op);
            exit(1);
    }
}

int main() {
    BitwiseOperators operators = { 0x55555555, 0xAAAAAAAAL };
    char operation;

    printf("Operands before operation:\n");
    print_binary(operators.a);
    print_binary(operators.b);

    printf("Enter operation symbol (&, |, ^, ~, <<, >>): ");
    scanf(" %c", &operation);

    perform_bitwise_operation(&operators, operation);

    printf("Operands after operation:\n");
    print_binary(operators.a);
    print_binary(operators.b);

    return 0;
}