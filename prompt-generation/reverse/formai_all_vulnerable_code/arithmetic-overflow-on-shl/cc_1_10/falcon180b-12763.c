//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

// Function to print binary representation of a number
void print_binary(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main() {
    unsigned char input1[MAX_SIZE];
    unsigned char input2[MAX_SIZE];
    unsigned char output[MAX_SIZE];

    printf("Enter the first binary number: ");
    fgets(input1, MAX_SIZE, stdin);

    printf("Enter the second binary number: ");
    fgets(input2, MAX_SIZE, stdin);

    // Convert input strings to unsigned integers
    unsigned int num1 = 0, num2 = 0;
    int i;
    for (i = 0; i < strlen(input1); i++) {
        num1 |= (input1[i] - '0') << (strlen(input1) - i - 1);
    }

    for (i = 0; i < strlen(input2); i++) {
        num2 |= (input2[i] - '0') << (strlen(input2) - i - 1);
    }

    // Perform bitwise operations
    unsigned int result = num1 & num2;
    result |= num1 | num2;
    result ^= num1 ^ num2;

    // Convert result to binary string
    char binary_result[MAX_SIZE];
    sprintf(binary_result, "%b", result);

    // Print results
    printf("Binary representation of the first number: ");
    print_binary(num1);
    printf("\n");

    printf("Binary representation of the second number: ");
    print_binary(num2);
    printf("\n");

    printf("Binary representation of the result: ");
    print_binary(result);
    printf("\n");

    return 0;
}