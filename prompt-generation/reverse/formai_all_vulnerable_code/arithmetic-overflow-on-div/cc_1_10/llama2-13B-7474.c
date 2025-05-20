//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INT 2147483647
#define MAX_STRlen 100

int main() {
    int num1, num2, sum = 0;
    char str1[MAX_STRlen], str2[MAX_STRlen];
    printf("Welcome to the Arithmetic Playground!\n");

    printf("Please enter your first number: ");
    scanf("%d", &num1);
    printf("Please enter your second number: ");
    scanf("%d", &num2);

    printf("Now, let's play some arithmetic games! \n");

    // Game 1: Guess My Number
    do {
        int guess = 0;
        printf("I'm thinking of a number between 1 and %d. Can you guess it? ", MAX_INT);
        scanf("%d", &guess);
        if (guess < num1) {
            printf("Too low! The number I'm thinking of is higher than %d.\n", guess);
        } else if (guess > num1) {
            printf("Too high! The number I'm thinking of is lower than %d.\n", guess);
        } else {
            printf("You guessed it! The number I'm thinking of was %d.\n", num1);
            break;
        }
    } while (1);

    // Game 2: Addition
    printf("Now, let's play a game of addition! \n");
    printf("I'll think of two numbers, and you have to add them up. Can you do it? ");
    scanf("%d%d", &num1, &num2);
    sum = num1 + num2;
    printf("Great job! The sum of %d and %d is %d.\n", num1, num2, sum);

    // Game 3: Subtraction
    printf("Now, let's play a game of subtraction! \n");
    printf("I'll think of two numbers, and you have to subtract the second number from the first. Can you do it? ");
    scanf("%d%d", &num1, &num2);
    sum = num1 - num2;
    printf("Excellent! The difference of %d and %d is %d.\n", num1, num2, sum);

    // Game 4: Multiplication
    printf("Now, let's play a game of multiplication! \n");
    printf("I'll think of two numbers, and you have to multiply them together. Can you do it? ");
    scanf("%d%d", &num1, &num2);
    sum = num1 * num2;
    printf("Well done! The product of %d and %d is %d.\n", num1, num2, sum);

    // Game 5: Division
    printf("Now, let's play a game of division! \n");
    printf("I'll think of two numbers, and you have to divide the second number into the first. Can you do it? ");
    scanf("%d%d", &num1, &num2);
    sum = num1 / num2;
    printf("Great job! The result of %d divided by %d is %d.\n", num1, num2, sum);

    return 0;
}