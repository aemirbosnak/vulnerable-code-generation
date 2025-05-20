//FormAI DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include <stdio.h>

int convertToBinary(int decimal) {
    int binary = 0, base = 1;
    while(decimal) {
        binary += (decimal%2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

int main() {
    
    // Welcome message
    printf("Welcome to the Medieval bitwise operation challenge!\n");
    
    // User input
    int num1, num2;
    printf("Enter two decimal numbers between 1 and 255: ");
    scanf("%d%d", &num1, &num2);
    
    // Convert to binary
    int binary1 = convertToBinary(num1);
    int binary2 = convertToBinary(num2);
    
    // Display binary form
    printf("%d in binary form is %d\n", num1, binary1);
    printf("%d in binary form is %d\n", num2, binary2);
    
    // Bitwise AND
    int result_and = num1 & num2;
    int result_and_binary = convertToBinary(result_and);
    printf("The result of bitwise AND between %d and %d is %d in binary form: %d\n", num1, num2, result_and, result_and_binary);
    
    // Bitwise OR
    int result_or = num1 | num2;
    int result_or_binary = convertToBinary(result_or);
    printf("The result of bitwise OR between %d and %d is %d in binary form: %d\n", num1, num2, result_or, result_or_binary);
    
    // Bitwise XOR
    int result_xor = num1 ^ num2;
    int result_xor_binary = convertToBinary(result_xor);
    printf("The result of bitwise XOR between %d and %d is %d in binary form: %d\n", num1, num2, result_xor, result_xor_binary);
    
    // Bitwise NOT
    int result_not = ~num1;
    int result_not_binary = convertToBinary(result_not);
    printf("The result of bitwise NOT on %d is %d in binary form: %d\n", num1, result_not, result_not_binary);
    
    return 0;
}