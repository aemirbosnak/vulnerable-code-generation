//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>
#include <stdint.h>

#define MAX_NUMBERS 64 // Maximum size of the numbers array
#define BITWISE_AND   1
#define BITWISE_OR    2
#define BITWISE_XOR   3
#define BITWISE_NOT   4

// Function to perform bitwise operations
void bitwise_operations(int operation, uint64_t *numbers, int size) {
    uint64_t result = (operation == BITWISE_NOT) ? ~numbers[0] : numbers[0];

    for (int i = 1; i < size; i++) {
        switch (operation) {
            case BITWISE_AND:
                result &= numbers[i];
                break;
            case BITWISE_OR:
                result |= numbers[i];
                break;
            case BITWISE_XOR:
                result ^= numbers[i];
                break;
            case BITWISE_NOT:
                // NOT operation is unary and only applied to numbers[0]
                break;
            default:
                printf("Invalid operation.\n");
                return;
        }
    }

    printf("Result of operation %d: %llu\n", operation, result);
}

// Function to display binary representation of a number
void display_binary(uint64_t number) {
    for (int i = 63; i >= 0; i--) {
        printf("%llu", (number >> i) & 1);
        if (i % 4 == 0) printf(" "); // Add space for readability
    }
    printf("\n");
}

int main() {
    uint64_t numbers[MAX_NUMBERS];
    int count;

    printf("Bitwise Operations Program\n");
    printf("Enter the number of values (Max %d): ", MAX_NUMBERS);
    scanf("%d", &count);

    if (count <= 0 || count > MAX_NUMBERS) {
        printf("Invalid number of values. Exiting.\n");
        return 1;
    }

    printf("Enter %d integers:\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%llu", &numbers[i]);
    }

    // Display the entered numbers in binary
    printf("\nEntered numbers in binary:\n");
    for (int i = 0; i < count; i++) {
        printf("Number %d: ", i + 1);
        display_binary(numbers[i]);
    }

    // Perform AND operation
    printf("\nPerforming Bitwise AND operation:\n");
    bitwise_operations(BITWISE_AND, numbers, count);

    // Perform OR operation
    printf("\nPerforming Bitwise OR operation:\n");
    bitwise_operations(BITWISE_OR, numbers, count);

    // Perform XOR operation
    printf("\nPerforming Bitwise XOR operation:\n");
    bitwise_operations(BITWISE_XOR, numbers, count);

    // Perform NOT operation on the first number
    printf("\nPerforming Bitwise NOT operation on the first number (%llu):\n", numbers[0]);
    bitwise_operations(BITWISE_NOT, numbers, 1);

    return 0;
}