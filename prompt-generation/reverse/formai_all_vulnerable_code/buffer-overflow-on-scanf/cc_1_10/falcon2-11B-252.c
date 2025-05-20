//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GAME_ROUNDS 10
#define MIN_NUM 1
#define MAX_NUM 10

int main() {
    int num;
    int guess;
    int game_round;
    int correct_guess;
    int game_won;

    srand(time(NULL));

    printf("Welcome to the Number Guessing Game!\n");

    game_won = 0;

    while (game_won == 0) {
        game_round = 0;
        while (game_round < MAX_GAME_ROUNDS) {
            num = rand() % (MAX_NUM - MIN_NUM) + MIN_NUM;
            printf("Guess a number between %d and %d: ", MIN_NUM, MAX_NUM);
            scanf("%d", &guess);

            if (guess > num) {
                printf("Too high!\n");
            } else if (guess < num) {
                printf("Too low!\n");
            } else {
                correct_guess = 1;
                game_won = 1;
                break;
            }

            game_round++;
        }

        if (game_won == 0) {
            printf("You lose!\n");
        } else {
            printf("You win!\n");
        }

        printf("Do you want to play again? (Y/N)");
        scanf("%c", &game_won);
    }

    return 0;
}