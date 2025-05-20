//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

// A function to print the binary representation of the given number
void printBinary(unsigned int num){
    int bits[32];
    int index = 0;
    // Converting the number into binary representation
    for(int i=0; i<32; i++){
        bits[i] = num & 1;
        num >>= 1;
    }
    // Printing the binary representation
    printf("Binary Representation: ");
    for(int i=31; i>=0; i--){
        printf("%d", bits[i]);
        if(i%8 == 0) printf(" "); // Add space every 8 bits
    }
    printf("\n");
}

int main(){
    unsigned int num1, num2, result;
    printf("Enter first number: ");
    scanf("%u", &num1);
    printf("Enter second number: ");
    scanf("%u", &num2);
    printf("\nFirst number: %u\nSecond number: %u\n", num1, num2);

    // Bitwise AND operation
    printf("\n-- Bitwise AND --\n");
    result = num1 & num2;
    printf("%u & %u = %u\n", num1, num2, result);
    printBinary(result);

    // Bitwise OR operation
    printf("\n-- Bitwise OR --\n");
    result = num1 | num2;
    printf("%u | %u = %u\n", num1, num2, result);
    printBinary(result);

    // Bitwise XOR operation
    printf("\n-- Bitwise XOR --\n");
    result = num1 ^ num2;
    printf("%u ^ %u = %u\n", num1, num2, result);
    printBinary(result);

    // Bitwise NOT operation
    printf("\n-- Bitwise NOT --\n");
    result = ~num1;
    printf("~%u = %u\n", num1, result);
    printBinary(result);

    // Bitwise Left Shift operation
    int shift;
    printf("\nEnter a number to Left Shift: ");
    scanf("%d", &shift);
    printf("%u << %d = %u\n", num1, shift, num1<<shift);
    printBinary(num1<<shift);

    // Bitwise Right Shift operation
    printf("\nEnter a number to Right Shift: ");
    scanf("%d", &shift);
    printf("%u >> %d = %u\n", num1, shift, num1>>shift);
    printBinary(num1>>shift);

    return 0;
}