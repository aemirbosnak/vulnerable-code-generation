//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to perform bitwise operations
void bitwise_operations(int num1, int num2, int operation) {
    int result = 0;

    // perform bitwise operation based on the given operation
    switch (operation) {
        case 1: // bitwise AND
            result = num1 & num2;
            break;
        case 2: // bitwise OR
            result = num1 | num2;
            break;
        case 3: // bitwise XOR
            result = num1 ^ num2;
            break;
        case 4: // bitwise NOT
            result = ~num1;
            break;
        case 5: // bitwise left shift
            result = num1 << num2;
            break;
        case 6: // bitwise right shift
            result = num1 >> num2;
            break;
        default:
            printf("Invalid operation!\n");
            exit(1);
    }

    // print the result
    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, operation;

    // get input from user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter operation (1: bitwise AND, 2: bitwise OR, 3: bitwise XOR, 4: bitwise NOT, 5: bitwise left shift, 6: bitwise right shift): ");
    scanf("%d", &operation);

    // perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}