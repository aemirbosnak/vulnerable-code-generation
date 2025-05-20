//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void print_binary(unsigned int n) {
    int i = 0;
    while (n > 0) {
        printf("%d", n & 1);
        n >>= 1;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

// Function to count number of bits set in a number
int count_bits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned int num1, num2, result;

    // Get two numbers from user
    printf("Enter first number: ");
    scanf("%u", &num1);
    printf("Enter second number: ");
    scanf("%u", &num2);

    // Perform bitwise operations on the numbers
    result = num1 | num2; // Bitwise OR
    printf("Bitwise OR: ");
    print_binary(result);

    result = num1 & num2; // Bitwise AND
    printf("\nBitwise AND: ");
    print_binary(result);

    result = num1 ^ num2; // Bitwise XOR
    printf("\nBitwise XOR: ");
    print_binary(result);

    result = ~num1; // Bitwise NOT
    printf("\nBitwise NOT: ");
    print_binary(result);

    result = num1 << 2; // Left shift
    printf("\nLeft shift by 2: ");
    print_binary(result);

    result = num1 >> 2; // Right shift
    printf("\nRight shift by 2: ");
    print_binary(result);

    // Count number of bits set in the numbers
    printf("\nNumber of bits set in %u: %d\n", num1, count_bits(num1));
    printf("Number of bits set in %u: %d\n", num2, count_bits(num2));

    return 0;
}