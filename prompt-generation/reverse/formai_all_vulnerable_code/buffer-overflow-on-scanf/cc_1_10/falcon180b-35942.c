//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// function to perform bitwise operations
void bitwise_operations(int operand1, int operand2, char operation) {
    int result;

    // perform the operation based on the input
    switch(operation) {
        case '&':
            result = operand1 & operand2;
            break;
        case '|':
            result = operand1 | operand2;
            break;
        case '^':
            result = operand1 ^ operand2;
            break;
        case '~':
            result = ~operand1;
            break;
        case '<<':
            result = operand1 << operand2;
            break;
        case '>>':
            result = operand1 >> operand2;
            break;
        default:
            printf("Invalid operation!\n");
            exit(0);
    }

    // display the result
    printf("Result: %d\n", result);
}

int main() {
    int operand1, operand2;
    char operation;

    // get input from user
    printf("Enter the first operand: ");
    scanf("%d", &operand1);
    printf("Enter the second operand: ");
    scanf("%d", &operand2);
    printf("Enter the operation (+, -, *, /, %, &, |, ^, ~, <<, >>): ");
    scanf(" %c", &operation);

    // perform the bitwise operation
    bitwise_operations(operand1, operand2, operation);

    return 0;
}