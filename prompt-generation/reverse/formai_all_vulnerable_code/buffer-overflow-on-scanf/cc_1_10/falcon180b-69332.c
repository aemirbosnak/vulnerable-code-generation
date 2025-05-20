//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>

// Function to count the number of set bits in an integer
int count_set_bits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    int n, m;
    printf("Enter an integer: ");
    scanf("%d", &n);
    m = n;

    // Count the number of set bits in the integer
    int num_set_bits = count_set_bits(n);
    printf("Number of set bits: %d\n", num_set_bits);

    // Find the largest power of 2 that divides the integer
    int largest_power_of_two = 1;
    while (largest_power_of_two <= m) {
        if (m % largest_power_of_two == 0) {
            m /= largest_power_of_two;
        } else {
            largest_power_of_two *= 2;
        }
    }
    printf("Largest power of 2 that divides the integer: %d\n", largest_power_of_two);

    // Check if the integer is a power of 2
    int is_power_of_two = 0;
    while (m > 1) {
        if (m % 2 == 1) {
            is_power_of_two = 0;
            break;
        }
        m /= 2;
    }
    if (is_power_of_two) {
        printf("The integer is a power of 2.\n");
    } else {
        printf("The integer is not a power of 2.\n");
    }

    return 0;
}