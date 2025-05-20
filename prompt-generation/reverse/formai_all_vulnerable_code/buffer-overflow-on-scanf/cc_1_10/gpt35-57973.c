//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to clear the terminal screen
void clearScreen() {
    system("clear||cls");
}

//function to generate a random number within the given range
int generateRandom(int lower, int upper) {
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    int score = 0;
    int guess, randomNumber, tries;

    printf("Welcome to Guess the Number Game!\n");
    printf("You have 5 tries to guess the number between 1 to 100.\n");
    printf("Every correct guess fetches you 20 points. So, let's begin!\n\n");

    do {
        randomNumber = generateRandom(1, 100);
        tries = 5;
        score = 0;
        clearScreen();
        printf("New number generated. Start guessing!\n\n");

        while (tries > 0) {
            printf("Guess the number: ");
            scanf("%d", &guess);
            tries--;

            if (guess == randomNumber) {
                score += 20;
                printf("Congratulations! Your guess is correct.\n");
                printf("Your score is now %d.\n", score);
                break;
            } else if (tries == 0) {
                printf("Game Over. The correct number was %d.\n", randomNumber);
                printf("Your final score is: %d\n", score);
            } else if (guess < randomNumber) {
                printf("Incorrect guess. Try higher.\n");
            } else if (guess > randomNumber) {
                printf("Incorrect guess. Try lower.\n");
            }
        }

        printf("\n\nDo you want to play again? (0 for No, 1 for Yes)\n");
        int playAgain;
        scanf("%d", &playAgain);

        if (playAgain != 1) {
            break;
        }
    } while (1);

    printf("Thanks for playing the game. Goodbye!\n");
    return 0;
}