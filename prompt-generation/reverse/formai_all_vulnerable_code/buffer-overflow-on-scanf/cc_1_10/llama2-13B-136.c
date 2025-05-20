//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int n, m;
    char secret;

    // Part 1: Guess the number
    printf("Welcome to the Magic Math Puzzle! \n");
    printf("I am thinking of a number between 1 and 100. Can you guess it?\n");
    printf("You have 5 guesses.\n");

    for (int i = 0; i < 5; i++) {
        printf("Guess: ");
        scanf("%d", &n);

        if (n == MAGIC_NUMBER) {
            printf("Congratulations! You guessed it correctly! \n");
            break;
        } else if (n < MAGIC_NUMBER) {
            printf("Too low! The number is higher than %d. \n", n);
        } else {
            printf("Too high! The number is lower than %d. \n", n);
        }
    }

    // Part 2: Find the secret
    printf("Now, I will reveal the secret: \n");
    secret = getchar();

    // Part 3: Solve the puzzle
    printf("The puzzle is: %c\n", secret);

    // Part 4: Check the solution
    if (secret == 'A' || secret == 'a') {
        printf("Correct! The solution is %c\n", 'A');
    } else if (secret == 'B' || secret == 'b') {
        printf("Correct! The solution is %c\n", 'B');
    } else if (secret == 'C' || secret == 'c') {
        printf("Correct! The solution is %c\n", 'C');
    } else {
        printf("Incorrect. The solution is %c\n", secret);
    }

    return 0;
}