//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
/**
*  Wahoo! Let's dive into the world of Bitwise operations!!!
*
*  As a chatbot, I thrive on numbers and mathematical operations. And when it comes to Bitwise
*  operations, I simply can't control my enthusiasm! It is just so amazing to see how a series
*  of bits can represent such complex values and how different bitwise operators can manipulate
*  those bits to get the desired results.
*
*  In this program, let's explore some of the most interesting bitwise operations and see how
*  they work in the C programming language. So, fasten your seatbelts and let's get started!
*/

#include <stdio.h>

void printBinary(int num);

int main() {
    int num1, num2;

    // Let's take two integers as input from the user
    printf("Enter two integers to perform bitwise operations on: ");
    scanf("%d %d", &num1, &num2);

    // Let's print the binary representations of these numbers
    printf("\nBinary representation of %d: ", num1);
    printBinary(num1);

    printf("Binary representation of %d: ", num2);
    printBinary(num2);

    // Let's perform some bitwise operations on these numbers
    int bitwise_and = num1 & num2;
    printf("\nBitwise AND of %d and %d: %d\n", num1, num2, bitwise_and);

    int bitwise_or = num1 | num2;
    printf("Bitwise OR of %d and %d: %d\n", num1, num2, bitwise_or);

    int bitwise_xor = num1 ^ num2;
    printf("Bitwise XOR of %d and %d: %d\n", num1, num2, bitwise_xor);

    int bitwise_complement1 = ~num1;
    printf("Bitwise complement of %d: %d\n", num1, bitwise_complement1);

    int bitwise_complement2 = ~num2;
    printf("Bitwise complement of %d: %d\n", num2, bitwise_complement2);

    int left_shift = num1 << 2;
    printf("Left shift of %d by 2 bits: %d\n", num1, left_shift);

    int right_shift = num2 >> 3;
    printf("Right shift of %d by 3 bits: %d\n", num2, right_shift);

    // That's it folks! 
    printf("\nWow! Bitwise operations are just so cool! Hope you enjoyed this program as much as I did! :)\n");

    return 0;
}

// Function to print the binary representation of a number
void printBinary(int num) {
    for(int i=31; i>=0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}