//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
// Let's create a circus of bitwise operations!

#include <stdio.h>

int main() {

    unsigned int a, b, c, d;

    printf("Welcome to our Bitwise Circus! Get ready to be amazed!\n\n");

    printf("Enter the first number (unsigned): ");
    scanf("%u", &a);

    printf("Enter the second number (unsigned): ");
    scanf("%u", &b);

    printf("Enter the third number (unsigned): ");
    scanf("%u", &c);

    printf("Enter the fourth number (unsigned): ");
    scanf("%u", &d);

    printf("\n\nLet the show begin!!!\n\n");

    printf("First trick: AND operation without the AND operator!\n");
    printf("%d AND %d = %d\n\n", a, b, a - (a | b));

    printf("Second trick: OR operation without the OR operator!\n");
    printf("%d OR %d = %d\n\n", a, b, a + b - (a & b));

    printf("Third trick: XOR operation without the XOR operator!\n");
    printf("%d XOR %d = %d\n\n", a, b, ~(~(a & ~b) & ~(~a & b)));

    printf("Fourth trick: NOT operation without the NOT operator!\n");
    printf("NOT %d = %d\n\n", a, ~a + 1);

    printf("Fifth trick: Shift Right operation without the Shift Right operator!\n");
    printf("%d Shift Right 2 = %d\n\n", a, a / (1 << 2));

    printf("Sixth trick: Shift Left operation without the Shift Left operator!\n");
    printf("%d Shift Left 3 = %d\n\n", a, a * (1 << 3));

    printf("Seventh trick: Rotate Right operation without the Rotate Right operator!\n");
    printf("%d Rotate Right 1 = %d\n\n", a, (a >> 1) | (a << ((sizeof(a) * 8) - 1)));

    printf("Eighth trick: Rotate Left operation without the Rotate Left operator!\n");
    printf("%d Rotate Left 1 = %d\n\n", a, (a << 1) | (a >> ((sizeof(a) * 8) - 1)));

    printf("Ninth trick: Swapping two numbers with XOR!\n");
    printf("Before: a = %d, b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After: a = %d, b = %d\n\n", a, b);

    printf("Tenth trick: Count number of bits that are set!\n");
    printf("Number of bits set in %d = %d\n\n", a, __builtin_popcount(a));

    printf("Eleventh trick: Count number of leading zeros!\n");
    printf("Number of leading zeros in %d = %d\n\n", a, __builtin_clz(a));

    printf("Twelfth trick: Count number of trailing zeros!\n");
    printf("Number of trailing zeros in %d = %d\n\n", a, __builtin_ctz(a));

    printf("Thank you for joining our Bitwise Circus! We hope you had fun!\n");

    return 0;
}