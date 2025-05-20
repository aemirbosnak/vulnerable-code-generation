//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define some bitwise operators as macros
#define SET_BIT(var, pos) (var |= (1 << pos))
#define CLEAR_BIT(var, pos) (var &= ~(1 << pos))
#define TOGGLE_BIT(var, pos) (var ^= (1 << pos))
#define CHECK_BIT(var, pos) ((var & (1 << pos))!= 0)

// Function to print the binary representation of a number
void print_binary(int num) {
    char bin_str[33];
    int i, j;
    sprintf(bin_str, "%32s", "");
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            bin_str[i] = '1';
        } else {
            bin_str[i] = '0';
        }
    }
    printf("%s\n", bin_str);
}

// Example usage of bitwise operators
int main() {
    int num1 = 0b10101010;
    int num2 = 0b11010011;
    int result;

    // Set the 3rd bit of num1
    SET_BIT(num1, 2);
    print_binary(num1);

    // Clear the 5th bit of num1
    CLEAR_BIT(num1, 4);
    print_binary(num1);

    // Toggle the 7th bit of num1
    TOGGLE_BIT(num1, 6);
    print_binary(num1);

    // Check if the 2nd bit of num1 is set
    if (CHECK_BIT(num1, 1)) {
        printf("The 2nd bit of num1 is set\n");
    } else {
        printf("The 2nd bit of num1 is not set\n");
    }

    // Perform bitwise AND, OR, XOR, and NOT operations on num1 and num2
    result = num1 & num2;
    print_binary(result);

    result = num1 | num2;
    print_binary(result);

    result = num1 ^ num2;
    print_binary(result);

    result = ~num1;
    print_binary(result);

    return 0;
}