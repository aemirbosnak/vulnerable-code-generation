//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function to count the number of bits set in a given integer
int count_bits(unsigned int n) {
    int count = 0;
    while (n!= 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Find the number of bits set in the input integer
    int num_bits_set = count_bits(n);
    printf("Number of bits set in %d: %d\n", n, num_bits_set);

    // Find the position of the first set bit from the right
    int first_set_bit_pos = 0;
    while ((n & 1) == 0) {
        n >>= 1;
        first_set_bit_pos++;
    }
    printf("Position of the first set bit from the right: %d\n", first_set_bit_pos);

    // Find the position of the last set bit from the left
    int last_set_bit_pos = 0;
    while (n!= 0) {
        n >>= 1;
        last_set_bit_pos++;
    }
    printf("Position of the last set bit from the left: %d\n", last_set_bit_pos);

    // Check if the input integer is a power of 2
    int is_power_of_2 = 0;
    if ((n & (n - 1)) == 0) {
        is_power_of_2 = 1;
    }
    printf("Is %d a power of 2? %s\n", n, is_power_of_2? "Yes" : "No");

    // Convert the input integer from decimal to binary
    char binary[33];
    sprintf(binary, "%032b", n);
    printf("Binary representation of %d: %s\n", n, binary);

    // Convert the input integer from decimal to hexadecimal
    char hex[9];
    sprintf(hex, "%08X", n);
    printf("Hexadecimal representation of %d: %s\n", n, hex);

    return 0;
}