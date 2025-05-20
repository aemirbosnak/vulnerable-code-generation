//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to count the number of set bits in an integer
int count_set_bits(unsigned int num) {
    int count = 0;
    while (num!= 0) {
        count++;
        num &= (num - 1);
    }
    return count;
}

int main() {
    int num1, num2;

    // Get input from user
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Perform bitwise operations
    unsigned int result = num1 & num2; // Bitwise AND
    unsigned int result1 = num1 | num2; // Bitwise OR
    unsigned int result2 = num1 ^ num2; // Bitwise XOR
    unsigned int result3 = num1 << 2; // Left shift by 2
    unsigned int result4 = num2 >> 2; // Right shift by 2
    unsigned int result5 = ~num1; // Bitwise NOT

    // Print results
    printf("Bitwise AND: %u\n", result);
    printf("Bitwise OR: %u\n", result1);
    printf("Bitwise XOR: %u\n", result2);
    printf("Left shift by 2: %u\n", result3);
    printf("Right shift by 2: %u\n", result4);
    printf("Bitwise NOT: %u\n", result5);

    // Perform bit manipulation
    unsigned int num3 = 0b10101010;
    num3 = num3 | (num3 << 8); // Set the 9th bit
    num3 = num3 & ~(1 << 7); // Clear the 8th bit
    printf("After bit manipulation: %u\n", num3);

    // Count set bits in an integer
    int set_bits = count_set_bits(num1);
    printf("Number of set bits in %d: %d\n", num1, set_bits);

    return 0;
}