//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define NUM_BITS 8

/* Function to print binary representation of an integer */
void print_binary(unsigned int x) {
    char *binary = malloc(NUM_BITS + 1);
    sprintf(binary, "%b", x);
    printf("%s\n", binary);
    free(binary);
}

/* Function to perform bitwise operations */
void bitwise_operations(unsigned int a, unsigned int b, char operation) {
    printf("Input numbers:\n");
    print_binary(a);
    print_binary(b);

    switch (operation) {
        case '&':
            printf("Bitwise AND:\n");
            printf("%b\n", a & b);
            break;
        case '|':
            printf("Bitwise OR:\n");
            printf("%b\n", a | b);
            break;
        case '^':
            printf("Bitwise XOR:\n");
            printf("%b\n", a ^ b);
            break;
        case '~':
            printf("Bitwise NOT:\n");
            printf("%b\n", ~a);
            break;
        case '<<':
            printf("Left shift:\n");
            printf("%b\n", a << b);
            break;
        case '>>':
            printf("Right shift:\n");
            printf("%b\n", a >> b);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    unsigned int num1, num2, operation;

    printf("Enter two numbers:\n");
    scanf("%u %u", &num1, &num2);

    printf("Enter bitwise operation (AND: &, OR: |, XOR: ^, NOT: ~, Left shift: <<, Right shift: >>):\n");
    scanf(" %c", &operation);

    bitwise_operations(num1, num2, operation);

    return 0;
}