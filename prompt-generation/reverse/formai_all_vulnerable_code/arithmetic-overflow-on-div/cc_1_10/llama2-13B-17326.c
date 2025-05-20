//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2, sum, diff, mult, div;
    float average;
    char op;

    printf("Welcome to the Math Exercise Program!\n");

    // Exercise 1: Addition
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    sum = num1 + num2;
    printf("The sum is: %d\n", sum);

    // Exercise 2: Subtraction
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    diff = num1 - num2;
    printf("The difference is: %d\n", diff);

    // Exercise 3: Multiplication
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    mult = num1 * num2;
    printf("The product is: %d\n", mult);

    // Exercise 4: Division
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    div = num1 / num2;
    printf("The quotient is: %d\n", div);

    // Exercise 5: Average
    printf("Enter three numbers: ");
    scanf("%d%d%f", &num1, &num2, &average);
    average = (num1 + num2) / 2;
    printf("The average is: %f\n", average);

    // Exercise 6: Factorial
    printf("Enter a positive integer: ");
    scanf("%d", &num1);
    if (num1 == 0) {
        printf("The factorial of 0 is 1.\n");
    } else {
        int factorial = 1;
        for (int i = 1; i <= num1; i++) {
            factorial *= i;
        }
        printf("The factorial of %d is %d.\n", num1, factorial);
    }

    return 0;
}