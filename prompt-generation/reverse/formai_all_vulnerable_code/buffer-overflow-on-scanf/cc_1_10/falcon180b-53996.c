//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2, char operation) {
    int result;
    int i;

    switch(operation) {
        case '&': // bitwise AND
            result = num1 & num2;
            printf("Bitwise AND: %d\n", result);
            break;
        case '|': // bitwise OR
            result = num1 | num2;
            printf("Bitwise OR: %d\n", result);
            break;
        case '^': // bitwise XOR
            result = num1 ^ num2;
            printf("Bitwise XOR: %d\n", result);
            break;
        case '~': // bitwise NOT
            result = ~num1;
            printf("Bitwise NOT: %d\n", result);
            break;
        case '<<': // left shift
            i = num2;
            result = num1 << i;
            printf("Left shift by %d: %d\n", i, result);
            break;
        case '>>': // right shift
            i = num2;
            result = num1 >> i;
            printf("Right shift by %d: %d\n", i, result);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

int main() {
    int num1, num2;
    char operation;

    // Get user input
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter operation (AND, OR, XOR, NOT, left shift, right shift): ");
    scanf(" %c", &operation);

    // Perform bitwise operations
    bitwise_operations(num1, num2, operation);

    return 0;
}