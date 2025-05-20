//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBERS 10
#define MAX_BITS 32

int main() {
    int num_of_numbers;
    int numbers[MAX_NUMBERS];
    int i, j, k, bit_length, bit_position;
    bool is_valid = true;

    // Get the number of integers from the user
    printf("Enter the number of integers (up to %d): ", MAX_NUMBERS);
    scanf("%d", &num_of_numbers);

    // Get the integers from the user
    printf("Enter %d integers:\n", num_of_numbers);
    for (i = 0; i < num_of_numbers; i++) {
        scanf("%d", &numbers[i]);
    }

    // Get the bit length from the user
    printf("Enter the bit length (up to %d): ", MAX_BITS);
    scanf("%d", &bit_length);

    // Get the bit position from the user
    printf("Enter the bit position (0 to %d): ", bit_length - 1);
    scanf("%d", &bit_position);

    // Validate the input
    if (num_of_numbers <= 0 || num_of_numbers > MAX_NUMBERS || bit_length <= 0 || bit_length > MAX_BITS || bit_position < 0 || bit_position >= bit_length) {
        printf("Invalid input!\n");
        is_valid = false;
    }

    // Perform the bitwise operation
    if (is_valid) {
        for (i = 0; i < num_of_numbers; i++) {
            int num = numbers[i];

            // Set the bit at the given position to 1
            num |= (1 << bit_position);

            // Print the result
            printf("%d: %d\n", i + 1, num);
        }
    }

    return 0;
}