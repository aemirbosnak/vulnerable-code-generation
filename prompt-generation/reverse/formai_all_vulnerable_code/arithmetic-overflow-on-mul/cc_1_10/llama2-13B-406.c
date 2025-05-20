//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

// Genius-level trivia: The highest prime number that can be represented
// in a signed integer is 2147483647. Can you guess why?

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;

    // Genius-level challenge: Try to enter a negative number and see what happens!
    printf("Enter a number: ");
    scanf("%d", &num1);

    // Now, let's get creative!
    printf("You entered: %d\n", num1);

    // Genius-level trivia: The number 42 is the answer to the ultimate
    // question of life, the universe, and everything. Prove it!
    printf("The answer to the ultimate question is: %d\n", 42);

    // Now, let's play a game of arithmetic!
    do {
        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &op);

        // Genius-level challenge: Try to enter an invalid operation!
        if (op == 'x' || op == 'X') {
            printf("Invalid operation! Try again.\n");
            continue;
        }

        // Perform the operation
        switch (op) {
            case '+':
                sum = num1 + num2;
                break;
            case '-':
                diff = num1 - num2;
                break;
            case '*':
                mult = num1 * num2;
                break;
            case '/':
                div = num1 / num2;
                break;
            case '%':
                mod = num1 % num2;
                break;
            default:
                printf("Invalid operation! Try again.\n");
                continue;
        }

        // Print the result
        printf("Result: %d\n", sum);

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &op);

    } while (op == 'y' || op == 'Y');

    return 0;
}