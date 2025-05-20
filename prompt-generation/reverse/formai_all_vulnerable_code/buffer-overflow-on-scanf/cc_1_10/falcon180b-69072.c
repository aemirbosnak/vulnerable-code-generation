//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include <stdio.h>

// Define a function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, int operation)
{
    unsigned int result = 0;

    // Perform the specified operation
    switch(operation)
    {
        case 0: // Bitwise AND
            result = num1 & num2;
            break;
        case 1: // Bitwise OR
            result = num1 | num2;
            break;
        case 2: // Bitwise XOR
            result = num1 ^ num2;
            break;
        case 3: // Left shift
            result = num1 << num2;
            break;
        case 4: // Right shift
            result = num1 >> num2;
            break;
        case 5: // Bitwise NOT
            result = ~num1;
            break;
        default:
            printf("Invalid operation!\n");
            return;
    }

    printf("Result: %u\n", result);
}

// Main function
int main()
{
    unsigned int num1, num2;
    int operation;

    // Get user input
    printf("Enter two unsigned integers:\n");
    scanf("%u %u", &num1, &num2);

    printf("Select a bitwise operation:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Left shift\n");
    printf("5. Right shift\n");
    printf("6. Bitwise NOT\n");
    scanf("%d", &operation);

    // Perform the selected operation
    bitwise_operations(num1, num2, operation);

    return 0;
}