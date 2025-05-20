//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    char op;
    clock_t start, end;

    printf("Welcome to the Synchronous Arithmetic Program!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (default is +)
    printf("Enter the operation (+, -, x, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        difference = num1 - num2;
    } else if (op == '*') {
        product = num1 * num2;
    } else if (op == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    }

    // Display the results
    printf("The result of %d + %d is %d\n", num1, num2, sum);
    printf("The result of %d - %d is %d\n", num1, num2, difference);
    printf("The result of %d x %d is %d\n", num1, num2, product);
    printf("The result of %d / %d is %d with a remainder of %d\n", num1, num2, quotient, remainder);

    // Display the magic number
    printf("The magic number is %d\n", MAGIC_NUMBER);

    // Calculate the execution time
    clock_t now = clock();
    double execution_time = (double)(now - start) / CLOCKS_PER_SEC;
    printf("The execution time is %f seconds\n", execution_time);

    return 0;
}