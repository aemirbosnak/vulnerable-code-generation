//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print binary representation of a number
void printBinary(int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num % 2);
        num /= 2;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

// Function to perform bitwise operations
void bitwiseOperations(int num1, int num2) {
    printf("\nBitwise operations on %d and %d:\n", num1, num2);

    // Bitwise OR
    printf("Bitwise OR: ");
    printf("%d | %d = ", num1, num2);
    printf("%d\n", num1 | num2);

    // Bitwise AND
    printf("Bitwise AND: ");
    printf("%d & %d = ", num1, num2);
    printf("%d\n", num1 & num2);

    // Bitwise XOR
    printf("Bitwise XOR: ");
    printf("%d ^ %d = ", num1, num2);
    printf("%d\n", num1 ^ num2);

    // Bitwise NOT
    printf("Bitwise NOT of %d: ", num1);
    printf("%d\n", ~num1);

    // Bitwise left shift
    printf("Bitwise left shift of %d by 2: ", num1);
    printf("%d\n", num1 << 2);

    // Bitwise right shift
    printf("Bitwise right shift of %d by 2: ", num1);
    printf("%d\n", num1 >> 2);
}

int main() {
    int num1, num2;

    // Get input from user
    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    // Print binary representation of input numbers
    printf("\nBinary representation of %d: ", num1);
    printBinary(num1);
    printf("\nBinary representation of %d: ", num2);
    printBinary(num2);

    // Perform bitwise operations
    bitwiseOperations(num1, num2);

    return 0;
}