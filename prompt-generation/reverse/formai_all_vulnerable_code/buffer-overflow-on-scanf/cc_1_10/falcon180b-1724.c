//Falcon-180B DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int rollDice(void);
void displayBoard(int board[3][3]);
int checkForWin(int board[3][3]);

int main(void) {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int i, j;

    srand(time(0));

    do {
        system("clear");
        printf("Player 1: X, Player 2: O\n\n");
        displayBoard(board);

        printf("Player %d's turn.\n", player);
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);

        i = choice / 3;
        j = choice % 3;

        if (board[i][j]!= 0) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[i][j] = (player == 1)? 1 : 2;
        player = (player == 1)? 2 : 1;

        if (checkForWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player++;
    } while (1);

    return 0;
}

int rollDice(void) {
    return rand() % 6 + 1;
}

void displayBoard(int board[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkForWin(int board[3][3]) {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0]!= 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j]!= 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0]!= 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2]!= 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}