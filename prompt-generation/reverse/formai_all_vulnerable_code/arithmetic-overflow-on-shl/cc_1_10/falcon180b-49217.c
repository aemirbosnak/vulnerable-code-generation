//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

// Define a function to print binary representation of a number
void print_binary(unsigned int num) {
    unsigned int mask = 1 << 31; // 2^31 = 2GB
    while (mask > 0) {
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
    }
}

int main() {
    int num1 = 10; // decimal representation of num1
    int num2 = 20; // decimal representation of num2

    // Convert num1 and num2 to binary
    printf("Binary representation of num1: ");
    print_binary(num1);
    printf("\n");

    printf("Binary representation of num2: ");
    print_binary(num2);
    printf("\n");

    // Perform bitwise AND operation
    int result1 = num1 & num2;
    printf("Bitwise AND of num1 and num2: %d\n", result1);

    // Perform bitwise OR operation
    int result2 = num1 | num2;
    printf("Bitwise OR of num1 and num2: %d\n", result2);

    // Perform bitwise XOR operation
    int result3 = num1 ^ num2;
    printf("Bitwise XOR of num1 and num2: %d\n", result3);

    // Perform bitwise complement operation
    int result4 = ~num1;
    printf("Bitwise complement of num1: %d\n", result4);

    // Perform left shift operation
    int result5 = num1 << 2;
    printf("Left shift of num1 by 2 positions: %d\n", result5);

    // Perform right shift operation
    int result6 = num1 >> 2;
    printf("Right shift of num1 by 2 positions: %d\n", result6);

    return 0;
}