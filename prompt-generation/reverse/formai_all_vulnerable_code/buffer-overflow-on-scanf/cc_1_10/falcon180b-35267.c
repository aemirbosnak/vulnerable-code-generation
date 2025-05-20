//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the factorial of a number
long long factorial(int n) {
    long long result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the power of a number
double power(double base, int exponent) {
    double result = 1.0;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int num1, num2;
    char operator;

    // Prompt the user to enter two numbers and an operator
    printf("Please enter two numbers and an operator (+, -, *, /):\n");
    scanf("%d %c %d", &num1, &operator, &num2);

    // Perform the arithmetic operation
    switch(operator) {
        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("%d / %d = %.2f\n", num1, num2, (double)num1 / (double)num2);
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    // Generate a random number between 1 and 100
    int random_num = rand_num(1, 100);

    // Calculate the factorial of the random number
    long long factorial_result = factorial(random_num);

    // Calculate the power of the random number
    double power_result = power(random_num, 2);

    // Print the results
    printf("Random number: %d\n", random_num);
    printf("Factorial of %d: %lld\n", random_num, factorial_result);
    printf("%.2f raised to the power of 2: %.2f\n", random_num, power_result);

    return 0;
}