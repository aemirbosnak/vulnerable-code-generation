//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Wacky Game!\n");
    printf("You will be playing against the computer.\n");

    srand(time(NULL));

    int userScore = 0, compScore = 0;
    int userGuess, compGuess;

    while (userScore < 10 && compScore < 10) {
        printf("Enter your guess (1-5): ");
        scanf("%d", &userGuess);

        if (userGuess > 5 || userGuess < 1) {
            printf("Oh no! That's not a valid guess.\n");
            printf("You lose your turn!\n");
        } else {
            compGuess = rand() % 5 + 1;
            printf("Computer's guess is: %d\n", compGuess);

            if (userGuess == compGuess) {
                printf("It's a tie! Nobody gets a point.\n");
            } else if ((userGuess == 1 && compGuess == 5) || 
                    (userGuess == 2 && compGuess == 1) ||
                    (userGuess == 3 && compGuess == 2) ||
                    (userGuess == 4 && compGuess == 3) ||
                    (userGuess == 5 && compGuess == 4)) {
                printf("You win this round!\n");
                userScore += 1;
            } else {
                printf("Computer wins this round!\n");
                compScore += 1;
            }
        }
    }

    printf("Final score:\n");
    printf("You: %d\n", userScore);
    printf("Computer: %d\n", compScore);

    if (userScore > compScore) {
        printf("Congratulations! You're the wacky winner!\n");
    } else {
        printf("Oops! The computer outwackied you this time.\n");
    }

    return 0;
}