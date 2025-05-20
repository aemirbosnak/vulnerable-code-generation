//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBinary(int num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void mysteryOperation(int a, int b) {
    printf("Performing mysterious operations on: A: %d, B: %d\n", a, b);
    printf("A in binary: ");
    printBinary(a);
    printf("\nB in binary: ");
    printBinary(b);
    printf("\n");

    int andResult = a & b;
    int orResult = a | b;
    int xorResult = a ^ b;
    int notA = ~a;
    int leftShiftA = a << 1;
    int rightShiftB = b >> 1;

    printf("A & B = %d (Binary: ", andResult);
    printBinary(andResult);
    printf(")\n");
    
    printf("A | B = %d (Binary: ", orResult);
    printBinary(orResult);
    printf(")\n");

    printf("A ^ B = %d (Binary: ", xorResult);
    printBinary(xorResult);
    printf(")\n");

    printf("~A = %d (Binary: ", notA);
    printBinary(notA);
    printf(")\n");

    printf("A << 1 = %d (Binary: ", leftShiftA);
    printBinary(leftShiftA);
    printf(")\n");

    printf("B >> 1 = %d (Binary: ", rightShiftB);
    printBinary(rightShiftB);
    printf(")\n");
}

int main() {
    printf("Welcome to the mysterious world of bitwise operations!\n");
    printf("Tonight, we shall uncover the truth hidden behind the numbers.\n");

    int num1, num2;
    char input1[20], input2[20];

    // Sherlock's initial instructions
    printf("Please enter the first integer (the enigma): ");
    fgets(input1, sizeof(input1), stdin);
    num1 = atoi(input1);

    printf("Now, enter the second integer (the counterpart): ");
    fgets(input2, sizeof(input2), stdin);
    num2 = atoi(input2);

    printf("\nAh, we have two integers: %d and %d.\n", num1, num2);
    printf("Let us perform some analysis...\n");

    mysteryOperation(num1, num2);

    printf("\nOh! One must always remember: the truth is in the details!\n");
    
    // An advanced demonstration of bit masking
    printf("\nNow, let us experiment with a mysterious mask...\n");
    
    int mask = 0x0F; // Mask that selects the lower nibble
    printf("Using a mask: %X (Binary: ", mask);
    printBinary(mask);
    printf(")\n");

    int maskedNum1 = num1 & mask;
    int maskedNum2 = num2 & mask;

    printf("Masked value of A: %d (Binary: ", maskedNum1);
    printBinary(maskedNum1);
    printf(")\n");

    printf("Masked value of B: %d (Binary: ", maskedNum2);
    printBinary(maskedNum2);
    printf(")\n");

    // Final conclusion
    printf("\nAs we conclude this rare exploration,\n");
    printf("Remember: In the world of logic and numbers, every bit tells a story!\n");
    
    return 0;
}