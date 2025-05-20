//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SQRT_MAX 1000

int main() {
    int num1, num2, sum, diff, mult, div;
    char str1[50], str2[50];
    char operation[5];

    printf("Welcome to the Complex Arithmetic Program!\n");

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);
    gets(str1); // get the string representation of the first number

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);
    gets(str2); // get the string representation of the second number

    // Ask the user for the operation
    printf("Enter the operation (+, -, *, /, or ^): ");
    scanf("%s", operation);

    // Perform the operation
    if (strcmp(operation, "+") == 0) {
        sum = num1 + num2;
    } else if (strcmp(operation, "-") == 0) {
        diff = num1 - num2;
    } else if (strcmp(operation, "*") == 0) {
        mult = num1 * num2;
    } else if (strcmp(operation, "/") == 0) {
        div = num1 / num2;
    } else if (strcmp(operation, "^") == 0) {
        int power = num1;
        for (int i = 0; i < num2; i++) {
            power *= num1;
        }
        printf("The result of %d^%d is %d\n", num1, num2, power);
    } else {
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Check if the result is a square
    if (diff == 0) {
        printf("The result is a square: %d^2 = %d\n", num1, diff);
    }

    // Check if the result is a perfect square
    if (sqrt(diff) == diff) {
        printf("The result is a perfect square: %d^2 = %d\n", num1, diff);
    }

    // Check if the result is a power of 2
    if (num1 == 0 || (num1 & (num1 - 1)) == 0) {
        printf("The result is a power of 2: %d^%d = %d\n", num1, num2, mult);
    }

    // Print the result
    printf("The result of %s %s %s is %d\n", str1, operation, str2, sum);

    return 0;
}