//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    printf("Welcome to the Arithmetic Adventure!\n");

    // Initialize variables
    num1 = rand() % 100;
    num2 = rand() % 100;
    sum = 0;
    diff = 0;
    mult = 1;
    div = 1;

    // Display the first numbers
    printf("Your first number is: %d\n", num1);
    printf("Your second number is: %d\n", num2);

    // Ask the user for the operation
    printf("What is your operation? (a/add, s/subtract, m/multiply, d/divide): ");
    scanf("%c", &op);

    // Perform the operation
    if (op == 'a' || op == 'A') {
        sum = num1 + num2;
    } else if (op == 's' || op == 'S') {
        diff = num1 - num2;
    } else if (op == 'm' || op == 'M') {
        mult = num1 * num2;
    } else if (op == 'd' || op == 'D') {
        div = num1 / num2;
    }

    // Display the results
    printf("Your result is: %d\n", sum);
    printf("Your result is: %d\n", diff);
    printf("Your result is: %d\n", mult);
    printf("Your result is: %d\n", div);

    // Check for magic numbers
    if (sum == MAGIC_NUMBER || diff == MAGIC_NUMBER || mult == MAGIC_NUMBER || div == MAGIC_NUMBER) {
        printf("Congratulations! You found a magic number!\n");
    }

    return 0;
}