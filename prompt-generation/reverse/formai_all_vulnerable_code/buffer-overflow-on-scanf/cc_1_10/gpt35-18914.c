//FormAI DATASET v1.0 Category: Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num1, num2, guess;
    char response;
    srand(time(NULL));
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of two numbers between 1 and 10.\n");
    printf("Can you guess both numbers in five or fewer attempts?\n");

    for(int i = 1; i <= 5; i++) {
        printf("Attempt %d: \n", i);
        printf("Guess the first number: ");
        scanf("%d", &guess);

        if (guess == num1) {
            printf("Correct! You guessed the first number!\n");
            printf("Now guess the second number: ");
            scanf("%d", &guess);

            if(guess == num2) {
                printf("Congratulations! You guessed both numbers!\n");
                printf("Want to play again? (y/n): ");
                scanf(" %c", &response);
                if(response == 'y') {
                    num1 = rand() % 10 + 1;
                    num2 = rand() % 10 + 1;
                    i = 0;
                    continue;
                } else {
                    printf("Thanks for playing! Goodbye!\n");
                    return 0;
                }
            } else {
                printf("Sorry, %d is not the second number. Try again!\n", guess);
            }
        } else {
            printf("Sorry, %d is not the first number. Try again!\n", guess);
        }
    }

    printf("Sorry, you did not guess both numbers in 5 attempts or fewer!\n");
    printf("The first number was %d and the second number was %d.\n", num1, num2);
    printf("Want to play again? (y/n): ");
    scanf(" %c", &response);

    if(response == 'y') {
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;
        main();
    } else {
        printf("Thanks for playing! Goodbye!\n");
        return 0;
    }
}