//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Watson's Arithmetic Assistant

int main()
{
    // Watson greets Sherlock
    printf("Good morning, Mr. Holmes.\n");
    printf("I have been working on a new arithmetic assistant program.\n");

    // Sherlock responds
    printf("Indeed, Watson. I am intrigued.\n");

    // Watson explains the program
    printf("This program can perform a variety of arithmetic operations, including addition, subtraction, multiplication, and division.\n");
    printf("It can also calculate the square root of a number and the factorial of a number.\n");

    // Sherlock is impressed
    printf("That is quite impressive, Watson.\n");

    // Watson asks Sherlock for a test case
    printf("Would you like to try it out?\n");

    // Sherlock agrees
    printf("Very well, Watson.\n");

    // Watson enters a test case
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Watson performs the arithmetic operations
    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    float quotient = (float)a / b;
    int square_root = sqrt(a);
    int factorial = 1;

    for (int i = 1; i <= a; i++)
    {
        factorial *= i;
    }

    // Watson prints the results
    printf("The sum of the two numbers is %d.\n", sum);
    printf("The difference of the two numbers is %d.\n", difference);
    printf("The product of the two numbers is %d.\n", product);
    printf("The quotient of the two numbers is %.2f.\n", quotient);
    printf("The square root of the first number is %d.\n", square_root);
    printf("The factorial of the first number is %d.\n", factorial);

    // Sherlock is satisfied
    printf("Excellent work, Watson.\n");
    printf("This program is quite useful.\n");

    // Watson is pleased
    printf("I am glad you approve, Mr. Holmes.\n");

    return 0;
}