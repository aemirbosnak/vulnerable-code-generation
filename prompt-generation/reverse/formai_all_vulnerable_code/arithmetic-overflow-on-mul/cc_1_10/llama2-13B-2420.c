//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, result;
    char guess;

    srand(time(NULL));

    printf("Welcome to the Arithmetic Puzzle!\n");

    // Puzzle 1: Guess the Number
    printf("I am thinking of a number between 1 and 100. Can you guess it?\n");
    scanf("%d", &guess);

    if (guess > MAGIC_NUMBER) {
        printf("Too high! Try again...\n");
        guess = -1;
    } else if (guess < MAGIC_NUMBER) {
        printf("Too low! Try again...\n");
        guess = -1;
    } else {
        printf("Congratulations! You guessed it correctly! The number I was thinking of was %d.\n", MAGIC_NUMBER);
    }

    // Puzzle 2: Addition
    printf("Now, I will give you two numbers. Can you add them together in your head?\n");
    scanf("%d%d", &num1, &num2);

    result = num1 + num2;

    printf("Correct! The sum of %d and %d is %d.\n", num1, num2, result);

    // Puzzle 3: Multiplication
    printf("Now, I will give you two numbers. Can you multiply them together in your head?\n");
    scanf("%d%d", &num1, &num2);

    result = num1 * num2;

    printf("Correct! The product of %d and %d is %d.\n", num1, num2, result);

    // Puzzle 4: Subtraction
    printf("Now, I will give you two numbers. Can you subtract the smaller one from the larger one?\n");
    scanf("%d%d", &num1, &num2);

    result = num1 - num2;

    printf("Correct! The difference of %d and %d is %d.\n", num1, num2, result);

    return 0;
}