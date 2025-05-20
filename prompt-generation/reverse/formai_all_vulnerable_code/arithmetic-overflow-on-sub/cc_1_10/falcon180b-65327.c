//Falcon-180B DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void drawBoard(int board[3][3]) {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == -1) {
                printf("O ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int checkWin(int board[3][3], int player) {
    // check horizontal
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // check vertical
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // check diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int turn = 0;
    int choice;

    do {
        system("clear");
        drawBoard(board);
        printf("\nPlayer 1's turn (X). Enter your choice: ");
        scanf("%d", &choice);
        choice--;

        if (board[choice / 3][choice % 3]!= 0) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[choice / 3][choice % 3] = 1;
        turn++;

        if (checkWin(board, 1)) {
            printf("\nPlayer 1 wins!\n");
            break;
        } else if (turn == 9) {
            printf("\nIt's a draw.\n");
            break;
        }

    } while (1);

    return 0;
}