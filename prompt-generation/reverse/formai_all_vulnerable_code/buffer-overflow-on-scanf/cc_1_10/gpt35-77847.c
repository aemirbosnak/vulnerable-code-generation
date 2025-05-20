//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include<stdio.h>

// A function to convert decimal to binary
void decimalToBinary(int x) {
    int binaryNum[32];
    int i = 0;
    while (x > 0) {
        binaryNum[i] = x % 2;
        x = x / 2;
        i++;
    }
    printf("\nThe binary representation is: ");
    // Printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main() {
    int a, b;

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    // Performing bitwise operations
    int XOR = a ^ b;
    int OR = a | b;
    int AND = a & b;
    int NOTa = ~a;
    int NOTb = ~b;
    int leftShift = a << 1;
    int rightShift = a >> 1;

    // Printing the results
    printf("\nXOR: %d", XOR);
    printf("\nOR: %d", OR);
    printf("\nAND: %d", AND);
    printf("\nNOT a: %d", NOTa);
    printf("\nNOT b: %d", NOTb);
    printf("\nLeft shift of a: %d", leftShift);
    printf("\nRight shift of a: %d", rightShift);

    // Converting decimal to binary
    decimalToBinary(XOR);
    decimalToBinary(OR);
    decimalToBinary(AND);
    decimalToBinary(NOTa);
    decimalToBinary(NOTb);
    decimalToBinary(leftShift);
    decimalToBinary(rightShift);

    return 0;
}