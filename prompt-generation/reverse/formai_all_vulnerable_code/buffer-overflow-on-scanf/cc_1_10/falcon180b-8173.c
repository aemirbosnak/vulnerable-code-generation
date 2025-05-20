//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2, char operation) {
    int result;
    switch(operation) {
        case '&':
            result = num1 & num2;
            printf("Result of %d & %d is %d\n", num1, num2, result);
            break;
        case '|':
            result = num1 | num2;
            printf("Result of %d | %d is %d\n", num1, num2, result);
            break;
        case '^':
            result = num1 ^ num2;
            printf("Result of %d ^ %d is %d\n", num1, num2, result);
            break;
        case '~':
            result = ~num1;
            printf("Result of ~%d is %d\n", num1, result);
            break;
        case '<<':
            result = num1 << num2;
            printf("Result of %d << %d is %d\n", num1, num2, result);
            break;
        case '>>':
            result = num1 >> num2;
            printf("Result of %d >> %d is %d\n", num1, num2, result);
            break;
        default:
            printf("Invalid operation!\n");
    }
}

int main() {
    int num1, num2;
    char operation;

    // Get user input for two numbers and bitwise operation
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the bitwise operation (&, |, ^, ~, <<, >>): ");
    scanf(" %c", &operation);

    // Perform bitwise operation and display result
    bitwise_operations(num1, num2, operation);

    return 0;
}