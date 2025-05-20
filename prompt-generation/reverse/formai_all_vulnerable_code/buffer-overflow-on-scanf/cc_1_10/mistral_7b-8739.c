//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

typedef struct {
    int number;
    int attempts_left;
} Game;

void initialize_game(Game *game);
int check_guess(int guess, int number);
void print_game_status(const Game *game);

int main() {
    Game game;
    int guess;

    srand(time(NULL));
    initialize_game(&game);

    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess the number between %d and %d to win.\n", MIN_NUMBER, MAX_NUMBER);

    while (game.attempts_left > 0) {
        print_game_status(&game);
        scanf("%d", &guess);

        if (check_guess(guess, game.number) == 1) {
            printf("Congratulations! You guessed the number.\n");
            break;
        }

        game.attempts_left--;
        printf("Incorrect guess. Try again.\n");
    }

    if (game.attempts_left == 0) {
        printf("Sorry, you lost. The number was %d.\n", game.number);
    }

    return 0;
}

void initialize_game(Game *game) {
    game->number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    game->attempts_left = MAX_TRIES;
}

int check_guess(int guess, int number) {
    if (guess == number) {
        return 1;
    }

    return 0;
}

void print_game_status(const Game *game) {
    printf("Current number: %d\n", game->number);
    printf("Attempts left: %d\n", game->attempts_left);
}