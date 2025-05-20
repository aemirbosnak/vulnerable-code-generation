//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    float average;

    printf("Welcome to the Math Playground!\n");

    // Exercise 1: Addition
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    sum = num1 + num2;
    printf("The sum is: %d\n", sum);

    // Exercise 2: Subtraction
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    difference = num1 - num2;
    printf("The difference is: %d\n", difference);

    // Exercise 3: Multiplication
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    product = num1 * num2;
    printf("The product is: %d\n", product);

    // Exercise 4: Division
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("The quotient is: %d\n", quotient);
    printf("The remainder is: %d\n", remainder);

    // Exercise 5: Modulus
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    remainder = num1 % num2;
    printf("The modulus is: %d\n", remainder);

    // Exercise 6: Average
    printf("Enter two numbers: ");
    scanf("%f%f", &num1, &num2);
    average = (num1 + num2) / 2;
    printf("The average is: %f\n", average);

    return 0;
}