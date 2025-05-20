//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT 2147483647
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;

    printf("Welcome to the Curious Arithmetic Adventure! \n");

    // Let's start with a random number...
    srand(time(NULL));
    num1 = rand() % MAX_INT;
    printf("Here's your first number: %d\n", num1);

    do {
        // Now, let's ask you to enter an operation...
        printf("Enter an operation (+, -, x, /, or %c): ", '\0');
        scanf("%c", &op);

        // Perform the operation...
        switch (op) {
            case '+':
                num2 = rand() % MAX_INT;
                sum = num1 + num2;
                printf("Here's the result of adding %d and %d: %d\n", num1, num2, sum);
                break;

            case '-':
                num2 = rand() % MAX_INT;
                diff = num1 - num2;
                printf("Here's the result of subtracting %d from %d: %d\n", num1, num2, diff);
                break;

            case '*':
                num2 = rand() % MAX_INT;
                mult = num1 * num2;
                printf("Here's the result of multiplying %d by %d: %d\n", num1, num2, mult);
                break;

            case '/':
                num2 = rand() % MAX_INT;
                if (num2 == 0) {
                    printf("Oh no! Division by zero! The answer is undefined.\n");
                } else {
                    div = num1 / num2;
                    printf("Here's the result of dividing %d by %d: %d\n", num1, num2, div);
                }
                break;

            case ' ':
                printf("I don't understand that operation. Let's try again.\n");
                continue;

            default:
                printf("Error: invalid operation. Please try again.\n");
                break;
        }
    } while (1);

    // Finally, let's play a little game with the magic number 42...
    printf("Hey, look! The number 42 appears in the result of one of our operations! Can you find it?\n");
    for (int i = 0; i < 10; i++) {
        num2 = rand() % MAX_INT;
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
            default:
                continue;
        }
        if (sum == MAGIC_NUMBER || diff == MAGIC_NUMBER || mult == MAGIC_NUMBER || div == MAGIC_NUMBER) {
            printf("Aha! The magic number %d appears in the result of operation %c and %d!\n", MAGIC_NUMBER, op, num2);
        }
    }

    return 0;
}