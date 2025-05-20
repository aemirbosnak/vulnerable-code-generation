//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>
#include <stdint.h>

// Function to perform bitwise operations
void bitwise_operations(uint32_t num1, uint32_t num2, int operation) {
    switch (operation) {
        case 0: // AND operation
            // Perform bitwise AND operation on num1 and num2
            printf("Result of AND operation: %d\n", num1 & num2);
            break;
        case 1: // OR operation
            // Perform bitwise OR operation on num1 and num2
            printf("Result of OR operation: %d\n", num1 | num2);
            break;
        case 2: // XOR operation
            // Perform bitwise XOR operation on num1 and num2
            printf("Result of XOR operation: %d\n", num1 ^ num2);
            break;
        case 3: // NOT operation
            // Perform bitwise NOT operation on num1
            printf("Result of NOT operation: %d\n", ~num1);
            break;
        case 4: // Left shift operation
            // Perform left shift operation on num1
            printf("Result of left shift operation: %d\n", num1 << 2);
            break;
        case 5: // Right shift operation
            // Perform right shift operation on num1
            printf("Result of right shift operation: %d\n", num1 >> 2);
            break;
        default:
            printf("Invalid operation selected.\n");
            break;
    }
}

int main() {
    uint32_t num1 = 0b10101010;
    uint32_t num2 = 0b01010101;
    int operation = 0;

    // Prompt user to select the operation to perform
    printf("Select the operation to perform:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. Left shift\n");
    printf("6. Right shift\n");
    scanf("%d", &operation);

    // Perform bitwise operation on num1 and num2
    bitwise_operations(num1, num2, operation);

    return 0;
}