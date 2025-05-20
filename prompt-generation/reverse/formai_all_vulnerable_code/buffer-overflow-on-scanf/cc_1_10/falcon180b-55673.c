//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int a, b, c;
    float x, y, z;
    char ch;

    // Prompt user for input
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Enter a character: ");
    scanf(" %c", &ch);

    printf("Enter two floating-point numbers: ");
    scanf("%f %f", &x, &y);

    // Basic arithmetic operations
    c = a + b;
    printf("The sum of %d and %d is %d.\n", a, b, c);

    c = a - b;
    printf("The difference between %d and %d is %d.\n", a, b, c);

    c = a * b;
    printf("The product of %d and %d is %d.\n", a, b, c);

    c = a / b;
    printf("The quotient of %d and %d is %d.\n", a, b, c);

    c = a % b;
    printf("The remainder of %d divided by %d is %d.\n", a, b, c);

    // Character arithmetic
    c = ch + 'A';
    printf("The ASCII value of '%c' is %d.\n", ch, c);

    // Floating-point arithmetic
    z = x + y;
    printf("The sum of %f and %f is %f.\n", x, y, z);

    z = x - y;
    printf("The difference between %f and %f is %f.\n", x, y, z);

    z = x * y;
    printf("The product of %f and %f is %f.\n", x, y, z);

    z = x / y;
    printf("The quotient of %f and %f is %f.\n", x, y, z);

    return 0;
}