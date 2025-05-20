//FormAI DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber) {
    int binaryNumber[32];
    int i = 0;
    // loop through until the decimal number is not zero
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2; // Take reminder by 2
        decimalNumber /= 2; // Divide by 2
        i++;
    }
    // Printing binary number in reverse order
    printf("Binary representation of the given decimal number is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);     
    }
    printf("\n");
}

int main() {
    int number1, number2, bitwiseAnd, bitwiseOr, bitwiseXor, bitwiseComplement, leftShift, rightShift;
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);
    
    // Bitwise AND
    bitwiseAnd = number1 & number2;
    printf("Bitwise AND of %d and %d is: %d \n", number1, number2, bitwiseAnd);

    // Bitwise OR
    bitwiseOr = number1 | number2;
    printf("Bitwise OR of %d and %d is: %d \n", number1, number2, bitwiseOr);

    // Bitwise XOR
    bitwiseXor = number1 ^ number2;
    printf("Bitwise XOR of %d and %d is: %d \n", number1, number2, bitwiseXor);

    // Bitwise complement
    bitwiseComplement = ~number1;
    printf("Bitwise complement of %d is: %d \n", number1, bitwiseComplement);

    // Left shift operator
    leftShift = number1 << 3; // Left shift by 3 bits
    printf("Left shift by 3 bits of %d is: %d \n", number1, leftShift);

    // Right shift operator
    rightShift = number2 >> 2; // Right shift by 2 bits
    printf("Right shift by 2 bits of %d is: %d \n", number2, rightShift);

    // Check if the first number is odd or even using bitwise operation
    if ((number1 & 1) == 0) {
        printf("%d is even\n", number1);
    } else {
        printf("%d is odd\n", number1);
    }

    // Convert the first number from decimal to binary using bitwise operation
    decimalToBinary(number1);

    return 0;
}