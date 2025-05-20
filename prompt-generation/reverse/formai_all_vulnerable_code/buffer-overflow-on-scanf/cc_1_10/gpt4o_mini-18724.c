//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void printBits(unsigned n)
{
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--)
    {
        putchar((n & (1u << i)) ? '1' : '0');
    }
    printf("\n");
}

unsigned funnyBitwiseOperations(unsigned a, unsigned b)
{
    printf("Let's get ready to rumble with some bitwise nonsense!\n");
    printf("The two contenders are: A = %u and B = %u\n", a, b);
    printf("In binary, they look like this:\nA: ");
    printBits(a);
    printf("B: ");
    printBits(b);

    unsigned andResult = a & b;
    unsigned orResult = a | b;
    unsigned xorResult = a ^ b;
    unsigned notA = ~a;
    unsigned notB = ~b;

    printf("\nAnd the results come tumbling down!\n");
    printf("A AND B: %u (In binary: ", andResult);
    printBits(andResult);
    printf(")\n");

    printf("A OR B: %u (In binary: ", orResult);
    printBits(orResult);
    printf(")\n");

    printf("A XOR B: %u (In binary: ", xorResult);
    printBits(xorResult);
    printf(")\n");

    printf("NOT A: %u (In binary: ", notA);
    printBits(notA);
    printf(")\n");

    printf("NOT B: %u (In binary: ", notB);
    printBits(notB);
    printf(")\n");

    unsigned leftShiftA = a << 1;
    unsigned rightShiftA = a >> 1;

    printf("Now, let’s do some wacky shifting!\n");
    printf("A left shifted by 1: %u (In binary: ", leftShiftA);
    printBits(leftShiftA);
    printf(")\n");

    printf("A right shifted by 1: %u (In binary: ", rightShiftA);
    printBits(rightShiftA);
    printf(")\n");

    return andResult;  // I know I'm supposed to return something, so here's the AND! 
}

int main()
{
    unsigned a, b;

    printf("Welcome to the Bitwise Funfair!\n");
    printf("Please enter two unsigned integers (A and B) separated by spaces: ");
    scanf("%u %u", &a, &b);

    printf("\nThe mighty bitwise operations commence!\n");
    funnyBitwiseOperations(a, b);

    printf("\nThanks for joining us at the Bitwise Funfair!\n");
    printf("We hope you had a binary blast!\n");

    return 0;
}