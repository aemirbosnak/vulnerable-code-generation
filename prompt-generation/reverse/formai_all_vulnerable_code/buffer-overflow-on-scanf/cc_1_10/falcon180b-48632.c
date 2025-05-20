//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int a, b, c, d, e, f;
    double x, y, z, w, v, u;

    // Prompt user for input
    printf("Enter six numbers: ");
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

    // Calculate sum of all numbers
    x = a + b + c + d + e + f;

    // Calculate average of all numbers
    y = x / 6;

    // Calculate product of all numbers
    z = a * b * c * d * e * f;

    // Calculate factorial of each number
    for (int i = 1; i <= 6; i++) {
        w = 1;
        for (int j = 1; j <= i; j++) {
            w *= j;
        }
        printf("Factorial of %d is %d\n", i, w);
    }

    // Calculate GCD of all numbers
    for (int i = 1; i <= 6; i++) {
        v = i;
        for (int j = 2; j <= 6; j++) {
            if (i % j == 0) {
                v = j;
            }
        }
        printf("GCD of %d and %d is %d\n", a, v, v);
    }

    // Calculate LCM of all numbers
    for (int i = 1; i <= 6; i++) {
        u = i;
        for (int j = 2; j <= 6; j++) {
            if (i % j == 0) {
                u *= j;
            }
        }
        printf("LCM of %d and %d is %d\n", a, u, u);
    }

    return 0;
}