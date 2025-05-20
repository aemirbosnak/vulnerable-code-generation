//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void drawBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                printf("X");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    int player = 1;
    int choice;
    int validInput = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);

        validInput = 0;
        while (!validInput) {
            printf("Enter your move (row and column): ");
            scanf("%d%d", &choice, &choice);
            if (choice < 1 || choice > SIZE) {
                printf("Invalid input. Please try again.\n");
            } else {
                validInput = 1;
            }
        }

        if (board[choice - 1][0] == 0) {
            board[choice - 1][0] = player;
            player++;
        } else {
            printf("Invalid move. Please try again.\n");
        }

        if (player > SIZE * SIZE) {
            printf("Game over! Player %d wins!\n", player - SIZE * SIZE);
            break;
        } else if (player == SIZE * SIZE) {
            printf("Game over! It's a tie!\n");
            break;
        } else {
            player++;
        }
    }

    return 0;
}