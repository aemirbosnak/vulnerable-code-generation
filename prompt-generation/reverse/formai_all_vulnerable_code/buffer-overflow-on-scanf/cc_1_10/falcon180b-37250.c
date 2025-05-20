//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Define some bitwise operations
#define SET_BIT(var, pos) (var) |= (1 << pos)
#define CLEAR_BIT(var, pos) (var) &= ~(1 << pos)
#define TOGGLE_BIT(var, pos) (var) ^= (1 << pos)
#define CHECK_BIT(var, pos) ((var) & (1 << pos))

// Function for counting number of set bits in a given integer
int count_bits(int n) {
    int count = 0;
    while (n) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

// Function for converting integer to binary string
char* int_to_binary(int n) {
    char* binary = (char*) malloc(33 * sizeof(char));
    sprintf(binary, "%032b", n);
    return binary;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Display number of set bits
    printf("Number of set bits: %d\n", count_bits(num));

    // Display binary representation of number
    printf("Binary representation: %s\n", int_to_binary(num));

    // Perform bitwise operations
    printf("Enter position to set a bit: ");
    scanf("%d", &num);
    SET_BIT(num, num);
    printf("Number after setting bit: %d\n", num);

    printf("Enter position to clear a bit: ");
    scanf("%d", &num);
    CLEAR_BIT(num, num);
    printf("Number after clearing bit: %d\n", num);

    printf("Enter position to toggle a bit: ");
    scanf("%d", &num);
    TOGGLE_BIT(num, num);
    printf("Number after toggling bit: %d\n", num);

    printf("Enter position to check for set bit: ");
    scanf("%d", &num);
    if (CHECK_BIT(num, num)) {
        printf("Bit is set\n");
    } else {
        printf("Bit is not set\n");
    }

    return 0;
}