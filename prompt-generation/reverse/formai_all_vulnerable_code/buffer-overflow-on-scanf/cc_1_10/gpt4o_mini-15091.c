//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 32

// Function to perform bitwise operations
void perform_bitwise_operations(unsigned int *arr, unsigned int size) {
    unsigned int and_result = arr[0];
    unsigned int or_result = arr[0];
    unsigned int xor_result = arr[0];
    unsigned int not_result = ~arr[0];
    
    for (unsigned int i = 1; i < size; i++) {
        and_result &= arr[i];
        or_result |= arr[i];
        xor_result ^= arr[i];
        not_result = ~arr[i];
    }

    printf("Bitwise AND of elements: %u\n", and_result);
    printf("Bitwise OR of elements: %u\n", or_result);
    printf("Bitwise XOR of elements: %u\n", xor_result);
    printf("Bitwise NOT of the last element: %u\n", not_result);
}

// Function to print binary representation of a number
void print_binary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Main function
int main() {
    unsigned int arr[MAX_ELEMENTS];
    unsigned int size;
    
    printf("Enter the number of elements (Max %d): ", MAX_ELEMENTS);
    scanf("%u", &size);
    
    if (size > MAX_ELEMENTS) {
        printf("Error: Maximum number of elements allowed is %d.\n", MAX_ELEMENTS);
        return EXIT_FAILURE;
    }

    // Input elements from the user
    printf("Enter %u elements (0-255):\n", size);
    for (unsigned int i = 0; i < size; i++) {
        printf("Element %u: ", i + 1);
        scanf("%u", &arr[i]);
        
        if(arr[i] > 255) {
            printf("Error: Please enter a value between 0 and 255.\n");
            return EXIT_FAILURE;
        }
    }

    // Show input in binary format
    printf("\nInput values in binary:\n");
    for (unsigned int i = 0; i < size; i++) {
        printf("Value %u: ", arr[i]);
        print_binary(arr[i]);
    }

    // Perform and display bitwise operations
    printf("\nPerforming bitwise operations...\n");
    perform_bitwise_operations(arr, size);

    // Additional functionality - Shift operations
    printf("\nLeft Shift and Right Shift Results:\n");
    for (unsigned int i = 0; i < size; i++) {
        printf("Left shift of %u: ", arr[i]);
        print_binary(arr[i] << 1);
        printf("Right shift of %u: ", arr[i]);
        print_binary(arr[i] >> 1);
    }

    // Count number of set bits in each number
    printf("\nCounting set bits in each number:\n");
    for (unsigned int i = 0; i < size; i++) {
        unsigned int count = 0;
        unsigned int temp = arr[i];
        while (temp) {
            count += (temp & 1);
            temp >>= 1;
        }
        printf("Number of set bits in %u: %u\n", arr[i], count);
    }

    return EXIT_SUCCESS;
}