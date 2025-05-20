//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

// define a function to perform bitwise operations
void bitwise_operations(unsigned char num1, unsigned char num2, int operation) {
    unsigned char result;
    switch(operation) {
        case 0: // AND operation
            result = num1 & num2;
            printf("Result of AND operation: %d\n", result);
            break;
        case 1: // OR operation
            result = num1 | num2;
            printf("Result of OR operation: %d\n", result);
            break;
        case 2: // XOR operation
            result = num1 ^ num2;
            printf("Result of XOR operation: %d\n", result);
            break;
        case 3: // NOT operation
            result = ~num1;
            printf("Result of NOT operation: %d\n", result);
            break;
        case 4: // Left shift operation
            result = num1 << num2;
            printf("Result of Left shift operation: %d\n", result);
            break;
        case 5: // Right shift operation
            result = num1 >> num2;
            printf("Result of Right shift operation: %d\n", result);
            break;
        default:
            printf("Invalid operation selected!\n");
    }
}

// main function
int main() {
    unsigned char num1, num2;
    int operation;

    // prompt user to enter two numbers
    printf("Enter the first number: ");
    scanf("%c", &num1);
    printf("Enter the second number: ");
    scanf("%c", &num2);

    // prompt user to select an operation
    printf("Select an operation:\n1. AND\n2. OR\n3. XOR\n4. NOT\n5. Left shift\n6. Right shift\n");
    scanf("%d", &operation);

    // call the bitwise_operations function
    bitwise_operations(num1, num2, operation);

    return 0;
}