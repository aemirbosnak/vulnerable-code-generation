//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GAME_TIME 10

struct game {
    int score;
    int time_remaining;
};

void init_game(struct game* game) {
    srand(time(NULL));
    game->score = 0;
    game->time_remaining = MAX_GAME_TIME;
}

void display_score(struct game* game) {
    printf("Score: %d\n", game->score);
}

int main() {
    struct game game;
    init_game(&game);

    while (game.time_remaining > 0) {
        int choice;
        printf("What would you like to do?\n1. Play a game\n2. Quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int points_earned = rand() % 10 + 1;
            game.score += points_earned;
            game.time_remaining--;

            printf("You earned %d points!\n", points_earned);
            display_score(&game);

            if (game.time_remaining == 0) {
                printf("Game over! Your final score is %d.\n", game.score);
                break;
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}