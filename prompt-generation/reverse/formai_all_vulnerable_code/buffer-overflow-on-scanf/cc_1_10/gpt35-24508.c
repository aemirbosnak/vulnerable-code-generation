//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int guess, num1, num2, result, score = 0;

    // Instructions
    printf("Welcome to the C Table Game!\n\n");
    printf("Instructions:\n");
    printf("1. You will be given two random numbers between 1-10.\n");
    printf("2. You have to guess the result of multiplying those two numbers.\n");
    printf("3. You will be given 3 chances to guess the correct answer.\n");
    printf("4. For each correct answer, you will get 1 point.\n");
    printf("5. The game will end after 10 rounds.\n\n");

    // Loop for 10 rounds
    for (int i = 1; i <= 10; i++) {
        printf("Round %d\n", i);

        // Generate two random numbers
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // Calculate the correct result
        result = num1 * num2;

        // Loop for 3 guesses
        for (int j = 1; j <= 3; j++) {
            printf("Guess #%d: ", j);
            scanf("%d", &guess);

            if (guess == result) { // correct guess
                printf("Correct!\n");
                score++;
                break;
            }
            else if (j == 3) { // out of guesses
                printf("Sorry, the correct answer was %d\n", result);
            }
            else { // incorrect guess
                printf("Incorrect! You have %d more chance(s).\n", 3 - j);
            }
        }
    }

    printf("\nGame Over!\n");
    printf("Your final score is %d\n", score);

    return 0;
}