//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    char color;
} Square;

typedef struct {
    Square* board;
    Square* current;
    Square* next;
    bool firstMove;
} Game;

int main() {
    Square* board = (Square*) malloc(8 * sizeof(Square));
    Square* current = board;
    Square* next = board + 1;
    Game game;

    game.board = board;
    game.current = current;
    game.next = next;
    game.firstMove = true;

    int moveCount = 0;
    while (true) {
        if (game.firstMove) {
            printf("White moves first.\n");
            game.firstMove = false;
        } else {
            printf("Black moves first.\n");
            game.firstMove = true;
        }

        if (moveCount == 0) {
            printf("First move: ");
            char c;
            scanf(" %c", &c);
            game.current->color = c;
            printf("White moves to (%d, %d) with %c.\n", game.current->x, game.current->y, game.current->color);
            game.current = game.next;
            game.next = game.next + 1;
        } else {
            printf("Move %d: ", moveCount);
            char c;
            scanf(" %c", &c);
            game.current->color = c;
            printf("White moves to (%d, %d) with %c.\n", game.current->x, game.current->y, game.current->color);
            if (game.next->color == 'B') {
                printf("Game over. Black wins.\n");
                break;
            }
            game.current = game.next;
            game.next = game.next + 1;
            moveCount++;
        }
    }

    return 0;
}