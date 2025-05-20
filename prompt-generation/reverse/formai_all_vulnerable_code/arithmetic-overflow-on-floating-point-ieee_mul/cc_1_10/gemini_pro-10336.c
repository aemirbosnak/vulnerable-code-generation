//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main() {
    // Let's play with some numbers!
    int x = 10;
    double y = 2.5;
    printf("Meet our math buddies X and Y!\n");

    // Addition: Let's combine them
    int sum = x + y;
    printf("X + Y = %d (Integer addition)\n", sum);

    // Subtraction: Let's see the difference
    double diff = x - y;
    printf("X - Y = %f (Double subtraction)\n", diff);

    // Multiplication: Multiplying the fun
    int product = x * y;
    printf("X * Y = %d (Care for some integer multiplication?)\n", product);

    // Division: Let's make a fraction
    double quotient = x / y;
    printf("X / Y = %f (Double division, with decimal treat!)\n", quotient);

    // Modulo: Find the remainder
    int remainder = x % 3;
    printf("X %% 3 = %d (Modulo gives you the leftovers)\n", remainder);

    // Exponents: Raising the power
    double powResult = pow(y, 2);
    printf("Y^2 = %f (Let's square Y!)\n", powResult);

    // Trigonometry: Let's get geometrical
    double sinValue = sin(y);
    printf("sin(Y) = %f (Sine of Y, anyone?)\n", sinValue);

    // Bitwise operators: Let's play with bits
    int bitwiseAnd = x & 3;
    int bitwiseOr = x | 3;
    int bitwiseXor = x ^ 3;
    printf("Bitwise AND: X & 3 = %d\n", bitwiseAnd);
    printf("Bitwise OR: X | 3 = %d\n", bitwiseOr);
    printf("Bitwise XOR: X ^ 3 = %d\n", bitwiseXor);

    // Increment and decrement: Counting up and down
    printf("Before increment: X = %d\n", x);
    x++; // Increment by 1
    printf("After increment: X = %d\n", x);

    printf("Before decrement: Y = %f\n", y);
    y--; // Decrement by 1
    printf("After decrement: Y = %f\n", y);

    // Assignment operators: Let's do some shorthand
    x += 5; // Equivalent to x = x + 5
    y -= 1.2; // Equivalent to y = y - 1.2
    printf("X after += 5: %d\n", x);
    printf("Y after -= 1.2: %f\n", y);

    // Conditional operators: Let's make decisions based on values
    int result = (x > y) ? x : y;
    printf("Max between X and Y: %d\n", result);

    // Operators, operators everywhere!
    printf("All the fun with arithmetic operators!\n");

    return 0;
}