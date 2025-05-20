//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    // Add a to b
    int c = a + b;
    printf("The sum of %d and %d is %d\n", a, b, c);

    // Subtract b from a
    int d = a - b;
    printf("%d minus %d is %d\n", a, b, d);

    // Multiply a and b
    int e = a * b;
    printf("The product of %d and %d is %d\n", a, b, e);

    // Divide b by a
    int f = b / a;
    printf("%d divided by %d is %d\n", b, a, f);

    // Modulo of a and b
    int g = b % a;
    printf("The remainder of %d divided by %d is %d\n", b, a, g);

    // Increment a by 1
    int h = ++a;
    printf("After incrementing, a is now %d\n", h);

    // Decrement b by 1
    int i = --b;
    printf("After decrementing, b is now %d\n", i);

    // Bitwise AND of a and b
    int j = a & b;
    printf("The bitwise AND of %d and %d is %d\n", a, b, j);

    // Bitwise OR of a and b
    int k = a | b;
    printf("The bitwise OR of %d and %d is %d\n", a, b, k);

    // Bitwise XOR of a and b
    int l = a ^ b;
    printf("The bitwise XOR of %d and %d is %d\n", a, b, l);

    // Bitwise NOT of a
    int m = ~a;
    printf("The bitwise NOT of %d is %d\n", a, m);

    // Left shift a by 2 bits
    int n = a << 2;
    printf("Shifting %d left by 2 bits results in %d\n", a, n);

    // Right shift b by 2 bits
    int o = b >> 2;
    printf("Shifting %d right by 2 bits results in %d\n", b, o);

    // Square of a
    int p = a * a;
    printf("The square of %d is %d\n", a, p);

    // Cube of b
    int q = b * b * b;
    printf("The cube of %d is %d\n", b, q);

    // Maximum of a and b
    int r = a > b ? a : b;
    printf("The maximum of %d and %d is %d\n", a, b, r);

    // Minimum of a and b
    int s = a < b ? a : b;
    printf("The minimum of %d and %d is %d\n", a, b, s);

    // Absolute value of d
    int t = abs(d);
    printf("The absolute value of %d is %d\n", d, t);

    // Negate e
    int u = -e;
    printf("Negating %d results in %d\n", e, u);

    // Bitwise left rotation of a by 1
    int v = (a << 1) | (a >> (sizeof(a) * 8 - 1));
    printf("Rotating %d left by 1 bit results in %d\n", a, v);

    // Bitwise right rotation of b by 1
    int w = (b >> 1) | (b << (sizeof(b) * 8 - 1));
    printf("Rotating %d right by 1 bit results in %d\n", b, w);

    return 0;
}