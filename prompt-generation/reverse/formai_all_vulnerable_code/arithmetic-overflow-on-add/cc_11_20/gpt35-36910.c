//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Error Handling Math Program!\n");

    // Get user inputs for calculation
    printf("Enter two integers separated by a space: ");
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "Invalid input. Please enter two integers separated by a space.\n");
        exit(1);
    }

    // Check for division by zero error
    if (num2 == 0) {
        fprintf(stderr, "Error: Division by zero is undefined.\n");
        exit(1);
    }

    // Calculate results and check for overflow error
    int sum = num1 + num2;
    if ((num1 > 0 && num2 > 0 && sum < 0) || (num1 < 0 && num2 < 0 && sum > 0)) {
        fprintf(stderr, "Error: Overflow detected in integer addition.\n");
        exit(1);
    }

    int diff = num1 - num2;
    if ((num1 > 0 && num2 < 0 && diff < 0) || (num1 < 0 && num2 > 0 && diff > 0)) {
        fprintf(stderr, "Error: Overflow detected in integer subtraction.\n");
        exit(1);
    }

    int prod = num1 * num2;
    if (num1 != 0 && abs(prod) / abs(num1) != abs(num2)) {
        fprintf(stderr, "Error: Overflow detected in integer multiplication.\n");
        exit(1);
    }

    double quotient = (double)num1 / (double)num2;
    if (isnan(quotient)) {
        fprintf(stderr, "Error: Not a number detected in division.\n");
        exit(1);
    }

    // Output results
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, diff);
    printf("%d * %d = %d\n", num1, num2, prod);
    printf("%d / %d = %.2f\n", num1, num2, quotient);

    return 0;
}