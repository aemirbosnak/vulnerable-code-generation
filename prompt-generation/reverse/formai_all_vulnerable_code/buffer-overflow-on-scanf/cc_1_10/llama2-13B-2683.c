//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    // Part 1: Guess the number
    printf("Welcome to the C Math Puzzle!\n");
    printf("I have a number in mind. Can you guess it?\n");
    printf("You have 5 chances to guess. Good luck!\n");

    for (int i = 0; i < 5; i++) {
        printf("Guess: ");
        scanf("%d", &num1);

        if (num1 == MAGIC_NUMBER) {
            printf("Congratulations! You guessed it right!\n");
            break;
        }

        printf("Too low... Try again!\n");
    }

    // Part 2: Perform math operations
    printf("Now, I will perform some math operations. Can you guess the result?\n");

    for (int i = 0; i < 3; i++) {
        printf("Op: ");
        scanf(" %c", &op);

        switch (op) {
            case '+':
                num2 = num1 + MAGIC_NUMBER;
                break;
            case '-':
                num2 = num1 - MAGIC_NUMBER;
                break;
            case '*':
                num2 = num1 * MAGIC_NUMBER;
                break;
            case '/':
                num2 = num1 / MAGIC_NUMBER;
                break;
            default:
                printf("Invalid operation. Try again!\n");
                break;
        }

        sum = num1 + num2;
        printf("Result: %d\n", sum);
    }

    return 0;
}