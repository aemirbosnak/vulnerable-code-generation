//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise operations
int bitwiseOperations(unsigned int num1, unsigned int num2) {
    // Perform bitwise AND operation
    unsigned int resultAND = num1 & num2;

    // Perform bitwise OR operation
    unsigned int resultOR = num1 | num2;

    // Perform bitwise XOR operation
    unsigned int resultXOR = num1 ^ num2;

    // Perform bitwise NOT operation on num1
    unsigned int resultNOT = ~num1;

    // Perform bitwise left shift operation
    unsigned int resultLSHIFT = num1 << 2;

    // Perform bitwise right shift operation
    unsigned int resultRSHIFT = num1 >> 2;

    // Print the results
    printf("Binary representation of %d: ", num1);
    printBinary(num1);
    printf("Binary representation of %d: ", num2);
    printBinary(num2);
    printf("AND: %d\n", resultAND);
    printf("OR: %d\n", resultOR);
    printf("XOR: %d\n", resultXOR);
    printf("NOT: %d\n", resultNOT);
    printf("LSHIFT: %d\n", resultLSHIFT);
    printf("RSHIFT: %d\n", resultRSHIFT);

    return 0;
}

int main() {
    // Get two numbers from the user
    unsigned int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Perform bitwise operations on the two numbers
    bitwiseOperations(num1, num2);

    return 0;
}