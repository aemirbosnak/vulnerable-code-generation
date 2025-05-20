//FormAI DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>

int main() {
    int num1, num2, sum, difference, product, quotient;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The difference of %d and %d is %d.\n", num1, num2, difference);
    printf("The product of %d and %d is %d.\n", num1, num2, product);
    printf("The quotient of %d and %d is %d.\n", num1, num2, quotient);

    if (num1 % num2 == 0) {
        printf("%d is a multiple of %d.\n", num1, num2);
    } else {
        printf("%d is not a multiple of %d.\n", num1, num2);
    }

    if (num1 > 0 && num2 > 0) {
        printf("Both numbers are positive.\n");
    } else if (num1 < 0 && num2 < 0) {
        printf("Both numbers are negative.\n");
    } else {
        printf("One number is positive and one number is negative.\n");
    }

    printf("The absolute value of %d is %d.\n", num1, abs(num1));
    printf("The absolute value of %d is %d.\n", num2, abs(num2));

    int gcd = findGCD(num1, num2);
    printf("The greatest common divisor of %d and %d is %d.\n", num1, num2, gcd);

    return 0;
}

int findGCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}