//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    float result;

    printf("Welcome to the magical world of mathematics! \n");

    // Exercise 1: Addition
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    sum = num1 + num2;
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    // Exercise 2: Subtraction
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    difference = num1 - num2;
    printf("The difference of %d and %d is %d.\n", num1, num2, difference);

    // Exercise 3: Multiplication
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    product = num1 * num2;
    printf("The product of %d and %d is %d.\n", num1, num2, product);

    // Exercise 4: Division
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("The quotient of %d and %d is %d, with a remainder of %d.\n", num1, num2, quotient, remainder);

    // Exercise 5: Modulus
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    result = fmod(num1, num2);
    printf("The modulus of %d and %d is %f.\n", num1, num2, result);

    // Exercise 6: Randomness
    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;
    printf("Here are two random numbers: %d and %d.\n", num1, num2);

    return 0;
}