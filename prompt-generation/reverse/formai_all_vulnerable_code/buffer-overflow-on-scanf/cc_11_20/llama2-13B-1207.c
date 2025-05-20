//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCORE 100
#define MIN_SCORE 0

int main() {
    int score = 0;
    int guess = 0;
    int correct = 0;
    int attempts = 0;

    srand(time(NULL)); // initialize random number generator

    printf("Welcome to Math Madness!\n");

    do {
        // generate a random math problem
        int problem = (rand() % 10) + 1;
        int operation = (rand() % 4) + 1;
        int num1 = (rand() % 10) + 1;
        int num2 = (rand() % 10) + 1;

        // display the problem
        printf("Problem %d: %d %s %d = ?\n", attempts + 1, num1, operation == 1 ? "+" : operation == 2 ? "*" : "/", num2);

        // get the user's guess
        scanf("%d", &guess);

        // check if the guess is correct
        if (operation == 1 && guess == num1 + num2) {
            correct++;
            score += 10;
        } else if (operation == 2 && guess == num1 * num2) {
            correct++;
            score += 20;
        } else if (operation == 3 && guess == num1 / num2) {
            correct++;
            score += 30;
        }

        // keep track of attempts
        attempts++;

        // check if the user has won
        if (correct == 5) {
            printf("Congratulations! You have won Math Madness!\n");
            break;
        }

    } while (guess != 0);

    // display the final score
    printf("Your final score is: %d\n", score);

    return 0;
}