//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator

    int score = 0;
    int lives = 3;

    printf("Welcome to the game!\n");
    printf("You have 3 lives.\n");

    while (lives > 0) {
        int enemy = rand() % 10 + 1;
        int user = rand() % 10 + 1;

        printf("Enemy: %d\n", enemy);
        printf("You: %d\n", user);

        if (user > enemy) {
            printf("You win!\n");
            score++;
        } else if (user < enemy) {
            printf("You lose a life!\n");
            lives--;
        }

        printf("Score: %d\n", score);
        printf("Lives: %d\n", lives);
        printf("-----------------\n");

        if (lives <= 0) {
            printf("Game over!\n");
            break;
        }

        char input;
        printf("Enter 'Q' to quit, anything else to continue: ");
        scanf(" %c", &input);
        if (input == 'Q') {
            break;
        }
    }

    if (score > 0) {
        printf("You won with a score of %d!\n", score);
    } else {
        printf("You lost!\n");
    }

    return 0;
}