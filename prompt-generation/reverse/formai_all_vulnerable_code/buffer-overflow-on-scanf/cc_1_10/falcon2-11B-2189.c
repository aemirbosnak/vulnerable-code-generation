//Falcon2-11B DATASET v1.0 Category: Chess engine ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum {
    WHITE,
    BLACK
};

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x, y, color;
} Square;

typedef struct {
    Square board[8];
    Square current;
    bool gameOver;
} Game;

bool isValidMove(Game* game, int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && game->board[y].color == 0);
}

void movePiece(Game* game, int x, int y) {
    game->current.x = x;
    game->current.y = y;
    game->current.color = game->board[y].color;
    game->board[y].color = WHITE;
}

void makeMove(Game* game, int x, int y) {
    if (isValidMove(game, x, y)) {
        movePiece(game, x, y);
        if (game->current.color == WHITE) {
            game->board[game->current.y].color = BLACK;
        } else {
            game->board[game->current.y].color = WHITE;
        }
        game->current.color = 0;
    }
}

void printBoard(Game* game) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Square square = game->board[i];
            if (square.color == WHITE) {
                printf(" O ");
            } else if (square.color == BLACK) {
                printf(" X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void playGame(Game* game) {
    int x, y;
    printf("Welcome to C Chess!\n");
    printf("Please enter the row number of the piece you want to move (0-%d): ", 7);
    scanf("%d", &x);
    printf("Please enter the column number of the piece you want to move (0-%d): ", 7);
    scanf("%d", &y);
    makeMove(game, x, y);
    printBoard(game);
    if (game->gameOver) {
        printf("Game Over!\n");
        exit(1);
    } else {
        printf("Enter 'q' to quit or any other key to continue playing.\n");
        char c;
        scanf(" %c", &c);
        while (c!= 'q') {
            c = getchar();
            if (c!= EOF) {
                printf("Enter the row number of the piece you want to move (0-%d): ", 7);
                scanf("%d", &x);
                printf("Enter the column number of the piece you want to move (0-%d): ", 7);
                scanf("%d", &y);
                makeMove(game, x, y);
                printBoard(game);
            } else {
                printf("Game Over!\n");
                exit(1);
            }
        }
    }
}

int main() {
    Game game;
    game.board[0].x = 0;
    game.board[0].y = 0;
    game.board[0].color = WHITE;
    game.board[1].x = 0;
    game.board[1].y = 1;
    game.board[1].color = WHITE;
    game.board[2].x = 0;
    game.board[2].y = 2;
    game.board[2].color = WHITE;
    game.board[3].x = 0;
    game.board[3].y = 3;
    game.board[3].color = WHITE;
    game.board[4].x = 0;
    game.board[4].y = 4;
    game.board[4].color = WHITE;
    game.board[5].x = 0;
    game.board[5].y = 5;
    game.board[5].color = WHITE;
    game.board[6].x = 0;
    game.board[6].y = 6;
    game.board[6].color = WHITE;
    game.board[7].x = 0;
    game.board[7].y = 7;
    game.board[7].color = WHITE;
    game.board[0].x = 1;
    game.board[0].y = 1;
    game.board[0].color = BLACK;
    game.board[1].x = 1;
    game.board[1].y = 2;
    game.board[1].color = BLACK;
    game.board[2].x = 1;
    game.board[2].y = 3;
    game.board[2].color = BLACK;
    game.board[3].x = 1;
    game.board[3].y = 4;
    game.board[3].color = BLACK;
    game.board[4].x = 1;
    game.board[4].y = 5;
    game.board[4].color = BLACK;
    game.board[5].x = 1;
    game.board[5].y = 6;
    game.board[5].color = BLACK;
    game.board[6].x = 1;
    game.board[6].y = 7;
    game.board[6].color = BLACK;
    game.board[7].x = 1;
    game.board[7].y = 7;
    game.board[7].color = BLACK;
    game.gameOver = false;
    playGame(&game);
    return 0;
}