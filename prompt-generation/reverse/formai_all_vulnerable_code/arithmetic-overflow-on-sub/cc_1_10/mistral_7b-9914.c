//MISTRAL-7B DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 10
#define NUM_TRIES 5

typedef struct {
    int number;
    int tries_left;
} Game;

void generate_random_number(Game *game) {
    game->number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

int compare_guess_to_number(int guess, int number) {
    if (guess < number) {
        return -1;
    } else if (guess > number) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    Game game;
    generate_random_number(&game);

    printf("Welcome to the Treasure Hunt game!\n");
    printf("You have %d tries to guess the number between %d and %d.\n", NUM_TRIES, MIN_NUMBER, MAX_NUMBER);

    int guess;
    for (int i = 0; i < NUM_TRIES; i++) {
        scanf("%d", &guess);

        int comparison_result = compare_guess_to_number(guess, game.number);

        switch (comparison_result) {
            case -1:
                printf("Your guess is too low. Try again.\n");
                break;
            case 0:
                printf("Congratulations! You found the treasure!\n");
                return 0;
            case 1:
                printf("Your guess is too high. Try again.\n");
                break;
            default:
                printf("Error: unrecognized comparison result.\n");
                return 1;
        }

        game.tries_left--;
        printf("You have %d tries left.\n", game.tries_left);
    }

    printf("Game over. The treasure was at %d.\n", game.number);
    return 0;
}