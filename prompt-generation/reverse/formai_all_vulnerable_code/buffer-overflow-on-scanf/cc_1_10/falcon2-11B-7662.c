//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int cards[N][N];
    int turn;
} Game;

void init_game(Game* game) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            game->cards[i][j] = 0;
        }
    }
    game->turn = 0;
}

int main() {
    Game game;
    init_game(&game);

    while (1) {
        int i, j;
        printf("Turn %d:\n", game.turn);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (game.cards[i][j] == 0) {
                    printf("%d ", j + 1);
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("Select two cards:\n");
        int card1, card2;
        scanf("%d %d", &card1, &card2);
        if (card1 >= 1 && card1 <= N && card2 >= 1 && card2 <= N) {
            if (game.cards[card1 - 1][card2 - 1] == 0) {
                game.cards[card1 - 1][card2 - 1] = 1;
                printf("Match!\n");
            } else {
                printf("No match.\n");
            }
            printf("Turn %d:\n", game.turn + 1);
        } else {
            printf("Invalid selection.\n");
        }
    }

    return 0;
}