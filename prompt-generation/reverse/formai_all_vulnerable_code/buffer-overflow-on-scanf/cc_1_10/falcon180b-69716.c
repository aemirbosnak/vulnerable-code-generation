//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

typedef struct {
    int x;
    int y;
} Point;

void generateBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2? 'X' : 'O';
        }
    }
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    generateBoard(board);
    printf("Welcome to the C Table Game!\n");
    printBoard(board);
    int player = 1;
    Point p;
    while (1) {
        printf("Player %d's turn.\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%d", &p.x, &p.y);
        if (p.x < 0 || p.x > 2 || p.y < 0 || p.y > 2) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[p.x][p.y]!= 'X' && board[p.x][p.y]!= 'O') {
            board[p.x][p.y] = (player % 2 == 0)? 'X' : 'O';
            if (checkWin(board)) {
                printf("Player %d wins!\n", player);
                break;
            }
            player++;
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}