//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct board {
    int player;
    int empty;
    int x;
    int y;
    int win;
} board;

int main() {
    board board1 = {0, 0, 0, 0, 0};
    board board2 = {0, 0, 0, 0, 0};
    board board3 = {0, 0, 0, 0, 0};
    board board4 = {0, 0, 0, 0, 0};
    board board5 = {0, 0, 0, 0, 0};

    printf("Welcome to Tic Tac Toe!\n");
    printf("Enter your name: ");
    scanf("%s", &board1.player);
    printf("Welcome, %s!\n", board1.player);

    printf("Choose your position: \n");
    for(int i = 0; i < 9; i++) {
        printf("%d. ", i + 1);
    }
    scanf("%d", &board1.x);
    scanf("%d", &board1.y);

    if (board1.x > 8 || board1.y > 8) {
        printf("Invalid position. Please try again.\n");
        main();
    } else {
        board1.win = 0;
        board1.empty = 1;
        board1.player = 1;
        board2.win = 0;
        board2.empty = 1;
        board2.player = 2;
        board3.win = 0;
        board3.empty = 1;
        board3.player = 1;
        board4.win = 0;
        board4.empty = 1;
        board4.player = 2;
        board5.win = 0;
        board5.empty = 1;
        board5.player = 1;

        if (board1.x == board2.x && board1.y == board2.y) {
            board2.win = 1;
        } else if (board1.x == board3.x && board1.y == board3.y) {
            board3.win = 1;
        } else if (board1.x == board4.x && board1.y == board4.y) {
            board4.win = 1;
        } else if (board1.x == board5.x && board1.y == board5.y) {
            board5.win = 1;
        }

        if (board2.win == 1 || board3.win == 1 || board4.win == 1 || board5.win == 1) {
            if (board1.player == 1) {
                printf("Player 1 wins!\n");
            } else {
                printf("Player 2 wins!\n");
            }
        } else if (board1.empty == 0) {
            printf("Draw!\n");
        } else {
            printf("Game not over.\n");
        }
    }

    return 0;
}