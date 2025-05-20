//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2, char operation)
{
    int result;

    switch(operation)
    {
        case '&': // Bitwise AND
            result = num1 & num2;
            printf("Result of bitwise AND: %d\n", result);
            break;

        case '|': // Bitwise OR
            result = num1 | num2;
            printf("Result of bitwise OR: %d\n", result);
            break;

        case '^': // Bitwise XOR
            result = num1 ^ num2;
            printf("Result of bitwise XOR: %d\n", result);
            break;

        case '~': // Bitwise NOT
            result = ~num1;
            printf("Result of bitwise NOT: %d\n", result);
            break;

        case '<<': // Left Shift
            result = num1 << num2;
            printf("Result of left shift: %d\n", result);
            break;

        case '>>': // Right Shift
            result = num1 >> num2;
            printf("Result of right shift: %d\n", result);
            break;

        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main()
{
    int num1, num2;
    char operation;

    // Get input from user
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter the operation you want to perform:\n");
    printf("1. Bitwise AND (&)\n");
    printf("2. Bitwise OR (|)\n");
    printf("3. Bitwise XOR (^)\n");
    printf("4. Bitwise NOT (~)\n");
    printf("5. Left Shift (<<)\n");
    printf("6. Right Shift (>>)\n");
    scanf("%c", &operation);

    // Perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}