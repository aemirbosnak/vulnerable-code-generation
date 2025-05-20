//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_ELEMENTS 16

// Function to perform bitwise AND
void bitwise_and(int arr1[], int arr2[], int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] & arr2[i];
    }
}

// Function to perform bitwise OR
void bitwise_or(int arr1[], int arr2[], int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] | arr2[i];
    }
}

// Function to perform bitwise XOR
void bitwise_xor(int arr1[], int arr2[], int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] ^ arr2[i];
    }
}

// Function to perform bitwise NOT
void bitwise_not(int arr[], int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = ~arr[i];
    }
}

// Function to display the binary representation of an integer
void print_binary(int num) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

// Function to compute the Hamming Distance
int hamming_distance(int a, int b) {
    return __builtin_popcount(a ^ b);
}

// Function to generate random integers for demonstration
void generate_random_integers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 256;  // Generate numbers between 0 and 255
    }
}

// Main function to demonstrate bitwise operations
int main() {
    int arr1[NUM_ELEMENTS];
    int arr2[NUM_ELEMENTS];
    int and_result[NUM_ELEMENTS];
    int or_result[NUM_ELEMENTS];
    int xor_result[NUM_ELEMENTS];
    int not_arr1[NUM_ELEMENTS];
    int not_arr2[NUM_ELEMENTS];
    
    // Seed the random number generator
    srand(time(NULL));

    // Step 1: Generate random integers
    generate_random_integers(arr1, NUM_ELEMENTS);
    generate_random_integers(arr2, NUM_ELEMENTS);

    // Display the generated arrays
    printf("Array 1:\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        print_binary(arr1[i]);
    }

    printf("Array 2:\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        print_binary(arr2[i]);
    }

    // Step 2: Perform bitwise operations
    bitwise_and(arr1, arr2, and_result, NUM_ELEMENTS);
    bitwise_or(arr1, arr2, or_result, NUM_ELEMENTS);
    bitwise_xor(arr1, arr2, xor_result, NUM_ELEMENTS);
    bitwise_not(arr1, not_arr1, NUM_ELEMENTS);
    bitwise_not(arr2, not_arr2, NUM_ELEMENTS);

    // Step 3: Display results of bitwise operations
    printf("\nBitwise AND Result:\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        print_binary(and_result[i]);
    }

    printf("\nBitwise OR Result:\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        print_binary(or_result[i]);
    }

    printf("\nBitwise XOR Result:\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        print_binary(xor_result[i]);
    }

    printf("\nBitwise NOT Result for Array 1:\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        print_binary(not_arr1[i]);
    }

    printf("\nBitwise NOT Result for Array 2:\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        print_binary(not_arr2[i]);
    }

    // Step 4: Calculate and display Hamming distances
    printf("\nHamming Distances between corresponding elements of both arrays:\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int distance = hamming_distance(arr1[i], arr2[i]);
        printf("Hamming Distance between ");
        print_binary(arr1[i]);
        printf("and ");
        print_binary(arr2[i]);
        printf("is: %d\n", distance);
    }

    return 0;
}