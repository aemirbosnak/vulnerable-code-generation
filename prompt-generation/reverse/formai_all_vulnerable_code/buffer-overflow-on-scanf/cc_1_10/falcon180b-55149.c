//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>
#include <stdint.h>

// Function to perform bitwise operations on two numbers
void bitwise_operations(uint32_t num1, uint32_t num2, uint8_t operation)
{
    switch(operation)
    {
        case 1: // AND operation
            printf("AND operation result: %u\n", num1 & num2);
            break;
        case 2: // OR operation
            printf("OR operation result: %u\n", num1 | num2);
            break;
        case 3: // XOR operation
            printf("XOR operation result: %u\n", num1 ^ num2);
            break;
        case 4: // NOT operation
            printf("NOT operation result: %u\n", ~num1);
            break;
        case 5: // Left shift operation
            printf("Left shift operation result: %u\n", num1 << num2);
            break;
        case 6: // Right shift operation
            printf("Right shift operation result: %u\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main()
{
    uint32_t num1, num2;

    // Get input from user
    printf("Enter two numbers: ");
    scanf("%u %u", &num1, &num2);

    // Get operation choice from user
    printf("Enter operation choice:\n1. AND\n2. OR\n3. XOR\n4. NOT\n5. Left shift\n6. Right shift\n");
    uint8_t operation;
    scanf("%u", &operation);

    // Perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}