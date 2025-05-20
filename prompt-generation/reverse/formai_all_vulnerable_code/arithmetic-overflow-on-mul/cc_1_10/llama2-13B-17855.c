//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;
    float avg, max, min;
    char name[50];

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;
    avg = 0;
    max = 0;
    min = 0;
    strcpy(name, "");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // Print the results
    printf("The result of %d %c %d is %d\n", num1, op, num2, sum);
    printf("The result of %d %c %d is %d\n", num1, op, num2, diff);
    printf("The result of %d %c %d is %f\n", num1, op, num2, mult);
    printf("The result of %d %c %d is %f\n", num1, op, num2, div);

    // Calculate the average
    avg = (sum + diff + mult + div) / 4;
    printf("The average of %d, %d, %d, and %d is %f\n", num1, num2, mult, div, avg);

    // Find the maximum and minimum
    max = (num1 > num2) ? num1 : num2;
    min = (num1 < num2) ? num1 : num2;
    printf("The maximum is %d and the minimum is %d\n", max, min);

    // Print the name of the user
    printf("Your name is %s\n", name);

    return 0;
}