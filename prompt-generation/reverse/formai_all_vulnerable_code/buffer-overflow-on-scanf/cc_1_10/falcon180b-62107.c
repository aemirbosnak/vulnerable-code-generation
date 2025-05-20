//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

// Function to count the number of set bits in an integer
int count_bits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n &= (n - 1);
    }
    return count;
}

int main() {
    int num, i, j, k;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Convert decimal to binary
    char binary[100];
    int binary_length = 0;
    while (num > 0) {
        binary[binary_length++] = '0' + (num % 2);
        num >>= 1;
    }
    binary[binary_length] = '\0';
    printf("Binary representation of %d: %s\n", num, binary);

    // Count the number of set bits in the binary representation
    int set_bits = count_bits(num);
    printf("Number of set bits in the binary representation: %d\n", set_bits);

    // Swap the values of two variables without using a temporary variable
    i = 5;
    j = 10;
    printf("Before swapping, i = %d, j = %d\n", i, j);
    i = i ^ j;
    j = i ^ j;
    i = i ^ j;
    printf("After swapping, i = %d, j = %d\n", i, j);

    // Check if a number is a power of 2
    k = 8;
    if (k > 0 && (k & (k - 1)) == 0) {
        printf("%d is a power of 2\n", k);
    } else {
        printf("%d is not a power of 2\n", k);
    }

    return 0;
}