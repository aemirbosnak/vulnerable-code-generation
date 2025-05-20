//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

/* Function to perform bitwise AND operation */
int bitwiseAnd(int a, int b) {
    return a & b;
}

/* Function to perform bitwise OR operation */
int bitwiseOr(int a, int b) {
    return a | b;
}

/* Function to perform bitwise XOR operation */
int bitwiseXor(int a, int b) {
    return a ^ b;
}

/* Function to perform bitwise NOT operation */
int bitwiseNot(int a) {
    return ~a;
}

/* Function to perform left shift operation */
int leftShift(int a, int positions) {
    return a << positions;
}

/* Function to perform right shift operation */
int rightShift(int a, int positions) {
    return a >> positions;
}

/* Function to display the binary representation of a number */
void printBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0) printf(" "); // add space for better readability
    }
    printf("\n");
}

/* Function to display a table of results for all bitwise operations */
void displayBitwiseOperations(int a, int b) {
    printf("Bitwise Operations Table:\n");
    printf("--------------------------------------------------\n");
    printf("A: ");
    printBinary(a);
    printf("B: ");
    printBinary(b);
    printf("A & B: ");
    printBinary(bitwiseAnd(a, b));
    printf("A | B: ");
    printBinary(bitwiseOr(a, b));
    printf("A ^ B: ");
    printBinary(bitwiseXor(a, b));
    printf("~A: ");
    printBinary(bitwiseNot(a));
    printf("~B: ");
    printBinary(bitwiseNot(b));
    printf("A << 1: ");
    printBinary(leftShift(a, 1));
    printf("A >> 1: ");
    printBinary(rightShift(a, 1));
    printf("B << 1: ");
    printBinary(leftShift(b, 1));
    printf("B >> 1: ");
    printBinary(rightShift(b, 1));
    printf("--------------------------------------------------\n");
}

int main() {
    int num1, num2;

    printf("Welcome to the Bitwise Operations Example Program!\n");
    printf("Please enter two integers (num1 and num2) to perform bitwise operations:\n");
    
    // Input two integers
    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);

    // Displaying the results of bitwise operations
    displayBitwiseOperations(num1, num2);
    
    // Additional testing with fixed numbers
    printf("Testing with fixed numbers 5 and 3:\n");
    displayBitwiseOperations(5, 3);

    // Testing left shift and right shift variations
    printf("Left shift and Right shift for num1 (10 shift right by 2):\n");
    num1 = 10; // Fixed testing value
    printf("10 << 2: ");
    printBinary(leftShift(num1, 2));
    printf("10 >> 2: ");
    printBinary(rightShift(num1, 2));
    
    printf("Left shift and Right shift for num2 (20 shift right by 3):\n");
    num2 = 20; // Fixed testing value
    printf("20 << 3: ");
    printBinary(leftShift(num2, 3));
    printf("20 >> 3: ");
    printBinary(rightShift(num2, 3));

    return 0;
}