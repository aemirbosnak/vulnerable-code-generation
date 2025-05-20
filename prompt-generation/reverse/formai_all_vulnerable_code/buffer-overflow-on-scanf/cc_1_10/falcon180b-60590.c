//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/* Function to count the number of bits set in an integer */
int count_bits(int n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n - 1);
    }
    return count;
}

/* Function to reverse the bits in an integer */
int reverse_bits(int n) {
    int reversed = 0;
    while (n) {
        reversed = (reversed << 1) | (n & 1);
        n >>= 1;
    }
    return reversed;
}

/* Function to check if two integers have the same number of bits set */
int same_bits(int a, int b) {
    return (a ^ b) & (a | b) == 0;
}

int main() {
    int num;

    /* Prompt user for input */
    printf("Enter an integer: ");
    scanf("%d", &num);

    /* Count the number of bits set in the input */
    int num_bits = count_bits(num);

    /* Reverse the bits in the input */
    int reversed_num = reverse_bits(num);

    /* Check if the input has the same number of bits set as its reverse */
    int same = same_bits(num, reversed_num);

    /* Print the results */
    printf("Number of bits set: %d\n", num_bits);
    printf("Reversed number: %d\n", reversed_num);
    printf("Same number of bits set: %s\n", same? "Yes" : "No");

    return 0;
}