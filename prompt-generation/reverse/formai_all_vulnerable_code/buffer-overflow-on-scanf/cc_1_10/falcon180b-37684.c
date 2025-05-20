//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2, char operation) {
    int result = 0;

    switch (operation) {
        case '&': // Bitwise AND
            result = num1 & num2;
            break;
        case '|': // Bitwise OR
            result = num1 | num2;
            break;
        case '^': // Bitwise XOR
            result = num1 ^ num2;
            break;
        case '~': // Bitwise NOT
            result = ~num1;
            break;
        case '<<': // Left Shift
            result = num1 << num2;
            break;
        case '>>': // Right Shift
            result = num1 >> num2;
            break;
    }

    // Display the result
    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, operation;

    // Prompt user for input
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation (+, -, *, /, ^, &, |, <<, >>): ");
    scanf(" %c", &operation);

    // Perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}