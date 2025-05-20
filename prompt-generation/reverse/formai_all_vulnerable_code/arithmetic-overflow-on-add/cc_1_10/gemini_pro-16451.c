//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2;
    char op;

    // Get user input
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform calculation
    switch (op) {
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
            if (num2 == 0) {
                printf("Division by zero is undefined.\n");
            } else {
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    // Calculate the factorial of a number
    int num, i, factorial;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    factorial = 1;
    for (i = 1; i <= num; i++) {
        factorial *= i;
    }
    printf("The factorial of %d is %d.\n", num, factorial);

    // Find the sum of all numbers from 1 to n
    int n, sum;
    printf("Enter a number to find the sum of all numbers from 1 to that number: ");
    scanf("%d", &n);
    sum = 0;
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    printf("The sum of all numbers from 1 to %d is %d.\n", n, sum);

    return 0;
}