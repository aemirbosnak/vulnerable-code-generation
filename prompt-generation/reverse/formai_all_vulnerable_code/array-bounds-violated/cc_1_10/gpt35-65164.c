//FormAI DATASET v1.0 Category: Checkers Game ; Style: funny
#include <stdio.h>

int board[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

void printBoard() {
    printf("    1 2 3 4 5 6 7 8\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 0) {
                printf(". ");
            } else if(board[i][j] == 1) {
                printf("W ");
            } else if(board[i][j] == 2) {
                printf("B ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Hello and welcome to C Checkers! \n");
    printf("Here we go! \n");
    printBoard();

    while(1) {
        printf("Player 1, please select a piece to move: \n");
        int row, col;
        scanf("%d %d", &row, &col);

        if(board[row - 1][col - 1] != 1) {
            printf("Invalid selection! Please retry. \n");
            continue;
        }

        printf("Where would you like to move this piece?\n");
        int newRow, newCol;
        scanf("%d %d", &newRow, &newCol);

        if(board[newRow - 1][newCol - 1] == 0) {
            board[row - 1][col - 1] = 0;
            board[newRow - 1][newCol - 1] = 1;
        } else {
            printf("Invalid selection! Please retry. \n");
            continue;
        }

        printf("Move complete! Here's the new board: \n");
        printBoard();

        if(0) {
            // TODO: Implement win conditions!
            printf("Game over!");
            break;
        }

        printf("Player 2, it's your turn! \n");
        printf("Where would you like to move?\n");
        scanf("%d %d", &row, &col);

        if(board[row - 1][col - 1] != 2) {
            printf("Invalid selection! Please retry. \n");
            continue;
        }

        printf("Where would you like to move this piece?\n");
        scanf("%d %d", &newRow, &newCol);

        if(board[newRow - 1][newCol - 1] == 0) {
            board[row - 1][col - 1] = 0;
            board[newRow - 1][newCol - 1] = 2;
        } else {
            printf("Invalid selection! Please retry. \n");
            continue;
        }

        printf("Move complete! Here's the new board: \n");
        printBoard();

        if(0) {
            // TODO: Implement win conditions!
            printf("Game over!");
            break;
        }
    }

    return 0;
}