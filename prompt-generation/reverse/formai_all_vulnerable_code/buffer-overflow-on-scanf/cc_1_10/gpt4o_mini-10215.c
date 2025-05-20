//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void displayBitwiseOperation(int a, int b) {
    printf("Detective's Note:\n");
    printf("Number A (in binary): ");
    for (int i = sizeof(a) * 8 - 1; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");

    printf("Number B (in binary): ");
    for (int i = sizeof(b) * 8 - 1; i >= 0; i--) {
        printf("%d", (b >> i) & 1);
    }
    printf("\n");
}

int main() {
    int a, b;
    printf("Ah, Watson! Let us embark on a thrilling mathematical investigation of bitwise operations.\n");
    printf("Please provide two integers for our analysis:\n");
    
    printf("Input integer A: ");
    scanf("%d", &a);
    
    printf("Input integer B: ");
    scanf("%d", &b);
    
    displayBitwiseOperation(a, b);
    
    int bitwiseAnd = a & b;
    int bitwiseOr = a | b;
    int bitwiseXor = a ^ b;
    int bitwiseNotA = ~a;
    int bitwiseNotB = ~b;
    
    printf("\nUpon further scrutiny, we observe the following results:\n");
    
    printf("1. Bitwise AND (A & B): %d\n", bitwiseAnd);
    printf("2. Bitwise OR (A | B): %d\n", bitwiseOr);
    printf("3. Bitwise XOR (A ^ B): %d\n", bitwiseXor);
    printf("4. Bitwise NOT (~A): %d\n", bitwiseNotA);
    printf("5. Bitwise NOT (~B): %d\n", bitwiseNotB);
    
    printf("\nNow, let us analyze the operations conjectured:\n\n");

    printf("In the context of bitwise AND, if both bits are 1, the result is 1 otherwise 0:\n");
    printf("So, examining A (%d) AND B (%d):\n", a, b);
    for (int i = sizeof(a) * 8 - 1; i >= 0; i--) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        printf("Bit %d: %d AND %d = %d\n", i, bitA, bitB, (bitA & bitB));
    }
    
    printf("\nNow shifting our attention to bitwise OR:\n");
    printf("With OR, if at least one of the bits is 1, the result is 1.\n");
    for (int i = sizeof(a) * 8 - 1; i >= 0; i--) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        printf("Bit %d: %d OR %d = %d\n", i, bitA, bitB, (bitA | bitB));
    }
    
    printf("\nNext, we delve into the curious realm of XOR:\n");
    printf("XOR states that if the bits are different, the result is 1:\n");
    for (int i = sizeof(a) * 8 - 1; i >= 0; i--) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        printf("Bit %d: %d XOR %d = %d\n", i, bitA, bitB, (bitA ^ bitB));
    }

    printf("\nFinally, let us contemplate the NOT operation:\n");
    printf("For NOT, we merely flip the bits:\n");
    printf("A = %d, ~A = %d\n", a, bitwiseNotA);
    printf("B = %d, ~B = %d\n", b, bitwiseNotB);
    
    printf("\nIt appears, dear Watson, our investigation into the mysterious world of bitwise operations has yielded fruitful results. Until next time!\n");
    
    return 0;
}