//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int number;
    int guess;
    int attempts;
    char error[100];
} GuessGame;

void generateRandomNumber(GuessGame *game) {
    game->number = rand() % 100 + 1;
}

void checkGuess(GuessGame *game) {
    if (game->guess < 1 || game->guess > 100) {
        sprintf(game->error, "Invalid guess. Please enter a number between 1 and 100.\n");
    } else if (game->guess < game->number) {
        sprintf(game->error, "Too low. Try again.\n");
    } else if (game->guess > game->number) {
        sprintf(game->error, "Too high. Try again.\n");
    } else {
        sprintf(game->error, "Congratulations! You guessed the number correctly.\n");
    }
}

int main() {
    srand(time(NULL));
    GuessGame game;
    generateRandomNumber(&game);
    int playAgain = 1;

    while(playAgain) {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &game.guess);
        checkGuess(&game);
        printf("%s", game.error);
        printf("Attempts: %d\n", game.attempts++);
        if (strcmp(game.error, "Congratulations! You guessed the number correctly.\n") == 0) {
            printf("Do you want to play again? (1 for yes, 0 for no): ");
            scanf("%d", &playAgain);
            if (playAgain == 0) {
                break;
            }
            game.attempts = 0;
            generateRandomNumber(&game);
        }
    }

    return 0;
}