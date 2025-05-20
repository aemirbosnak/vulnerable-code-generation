//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>

int main() {
    int num1, num2, add, sub, mul, div, rem;
    float num3, num4, addf, subf, mulf, divf;

    // Inputs
    printf("Enter two integer values: ");
    scanf("%d %d", &num1, &num2);

    // Addition
    add = num1 + num2;
    printf("Addition of %d and %d is %d\n", num1, num2, add);

    // Subtraction
    sub = num1 - num2;
    printf("Subtraction of %d and %d is %d\n", num1, num2, sub);

    // Multiplication
    mul = num1 * num2;
    printf("Multiplication of %d and %d is %d\n", num1, num2, mul);

    // Division
    div = num1 / num2;
    printf("Division of %d and %d is %d\n", num1, num2, div);

    // Remainder
    rem = num1 % num2;
    printf("Remainder of %d and %d is %d\n", num1, num2, rem);

    // Inputs
    printf("Enter two floating point values: ");
    scanf("%f %f", &num3, &num4);

    // Addition
    addf = num3 + num4;
    printf("Addition of %f and %f is %f\n", num3, num4, addf);

    // Subtraction
    subf = num3 - num4;
    printf("Subtraction of %f and %f is %f\n", num3, num4, subf);

    // Multiplication
    mulf = num3 * num4;
    printf("Multiplication of %f and %f is %f\n", num3, num4, mulf);

    // Division
    divf = num3 / num4;
    printf("Division of %f and %f is %f\n", num3, num4, divf);

    return 0;
}