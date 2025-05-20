//Falcon-180B DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define WIDTH 5
#define HEIGHT 5

void initBoard(int board[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j] = 0;
        }
    }
}

void drawBoard(int board[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void playGame(int board[WIDTH][HEIGHT]) {
    int player = 1;
    int move = 0;
    int x, y;
    while (move < SIZE) {
        printf("Player %d's turn.\n", player);
        printf("Enter your move (x and y coordinates): ");
        scanf("%d %d", &x, &y);
        if (board[x][y] == 0) {
            board[x][y] = player;
            move++;
        } else {
            printf("Invalid move. Try again.\n");
        }
        drawBoard(board);
        if (move == SIZE) {
            printf("Game over! Player %d wins!\n", player);
            break;
        }
        player = (player % 2)? 1 : 2;
    }
}

int main() {
    srand(time(NULL));
    int board[WIDTH][HEIGHT];
    initBoard(board);
    playGame(board);
    return 0;
}