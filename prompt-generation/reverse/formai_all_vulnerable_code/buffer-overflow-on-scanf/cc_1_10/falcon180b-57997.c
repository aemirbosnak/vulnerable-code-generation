//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10
#define MAX_BITS 32

int main() {
    int num_of_numbers, i, j, bit_position, bitwise_operation;
    int numbers[MAX_NUMBERS];
    int bitwise_result;

    // Get the number of integers from the user
    printf("Enter the number of integers: ");
    scanf("%d", &num_of_numbers);

    // Get the integers from the user
    printf("Enter the integers:\n");
    for (i = 0; i < num_of_numbers; i++) {
        scanf("%d", &numbers[i]);
    }

    // Get the bitwise operation from the user
    printf("Enter the bitwise operation (0 = AND, 1 = OR, 2 = XOR, 3 = NOT): ");
    scanf("%d", &bitwise_operation);

    // Get the bit position from the user
    printf("Enter the bit position: ");
    scanf("%d", &bit_position);

    // Perform the bitwise operation on all the integers
    for (i = 0; i < num_of_numbers; i++) {
        bitwise_result = 0;

        // Clear the bitwise_result variable
        for (j = 0; j < MAX_BITS; j++) {
            if (j == bit_position) {
                bitwise_result |= (1 << j);
            }
        }

        // Perform the bitwise operation
        switch (bitwise_operation) {
            case 0: // AND
                numbers[i] &= bitwise_result;
                break;
            case 1: // OR
                numbers[i] |= bitwise_result;
                break;
            case 2: // XOR
                numbers[i] ^= bitwise_result;
                break;
            case 3: // NOT
                numbers[i] ^= ((1 << bit_position) - 1);
                break;
            default:
                printf("Invalid bitwise operation!\n");
                exit(1);
        }
    }

    // Print the results
    printf("Results:\n");
    for (i = 0; i < num_of_numbers; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}