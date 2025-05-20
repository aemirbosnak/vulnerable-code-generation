//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

void displayBinary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; --i) {
        printf("%d", (num & (1 << i)) ? 1 : 0);
        if (i % 4 == 0) {
            printf(" "); // Space for readability
        }
    }
    printf("\n");
}

unsigned int bitwiseAnd(unsigned int a, unsigned int b) {
    return a & b;
}

unsigned int bitwiseOr(unsigned int a, unsigned int b) {
    return a | b;
}

unsigned int bitwiseXor(unsigned int a, unsigned int b) {
    return a ^ b;
}

unsigned int bitwiseNot(unsigned int a) {
    return ~a;
}

unsigned int leftShift(unsigned int a, unsigned int shift) {
    return a << shift;
}

unsigned int rightShift(unsigned int a, unsigned int shift) {
    return a >> shift;
}

int main() {
    unsigned int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%u", &num1);
    
    printf("Enter the second number: ");
    scanf("%u", &num2);
    
    printf("\nLet's play with bitwise operations!\n");
    printf("You entered:\n");
    printf("Num1: %u in binary: ", num1);
    displayBinary(num1);
    printf("Num2: %u in binary: ", num2);
    displayBinary(num2);

    printf("\nPerforming AND operation...\n");
    unsigned int andResult = bitwiseAnd(num1, num2);
    printf("%u AND %u = %u in binary: ", num1, num2, andResult);
    displayBinary(andResult);

    printf("\nPerforming OR operation...\n");
    unsigned int orResult = bitwiseOr(num1, num2);
    printf("%u OR %u = %u in binary: ", num1, num2, orResult);
    displayBinary(orResult);

    printf("\nPerforming XOR operation...\n");
    unsigned int xorResult = bitwiseXor(num1, num2);
    printf("%u XOR %u = %u in binary: ", num1, num2, xorResult);
    displayBinary(xorResult);

    printf("\nPerforming NOT operation on Num1...\n");
    unsigned int notResult1 = bitwiseNot(num1);
    printf("NOT %u = %u in binary: ", num1, notResult1);
    displayBinary(notResult1);

    printf("\nPerforming NOT operation on Num2...\n");
    unsigned int notResult2 = bitwiseNot(num2);
    printf("NOT %u = %u in binary: ", num2, notResult2);
    displayBinary(notResult2);
    
    int shift;
    printf("\nHow much would you like to shift Num1 to the left? (Enter a number): ");
    scanf("%d", &shift);
    unsigned int leftShiftResult = leftShift(num1, shift);
    printf("Num1 << %d = %u in binary: ", shift, leftShiftResult);
    displayBinary(leftShiftResult);
    
    printf("\nHow much would you like to shift Num1 to the right? (Enter a number): ");
    scanf("%d", &shift);
    unsigned int rightShiftResult = rightShift(num1, shift);
    printf("Num1 >> %d = %u in binary: ", shift, rightShiftResult);
    displayBinary(rightShiftResult);

    printf("\nThanks for playing with bitwise operations! Keep coding and have fun!\n");
    return 0;
}