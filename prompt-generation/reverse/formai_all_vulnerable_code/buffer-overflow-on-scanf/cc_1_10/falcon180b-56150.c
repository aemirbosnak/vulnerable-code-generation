//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to count the number of set bits in an integer
int count_set_bits(unsigned int num) {
    int count = 0;
    while (num) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}

// Function to reverse the bits in an integer
unsigned int reverse_bits(unsigned int num) {
    int i, j;
    unsigned int reversed = 0;
    for (i = 0, j = 31; i < 32; i++, j--) {
        if (num & (1 << i)) {
            reversed |= (1 << j);
        }
    }
    return reversed;
}

// Function to check if an integer is a power of two
int is_power_of_two(unsigned int num) {
    while (num > 1) {
        if (num % 2!= 0) {
            return 0;
        }
        num /= 2;
    }
    return 1;
}

int main() {
    int num, i, j;
    unsigned int reversed;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Count the number of set bits in the integer
    printf("Number of set bits: %d\n", count_set_bits(num));

    // Reverse the bits in the integer
    reversed = reverse_bits(num);
    printf("Reversed bits: %u\n", reversed);

    // Check if the integer is a power of two
    if (is_power_of_two(num)) {
        printf("The number is a power of two\n");
    } else {
        printf("The number is not a power of two\n");
    }

    // Print the binary representation of the integer
    printf("Binary representation: ");
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}