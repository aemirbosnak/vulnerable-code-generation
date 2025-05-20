//FormAI DATASET v1.0 Category: Checkers Game ; Style: random
#include<stdio.h>

int board[8][8] = {  //initializing the board with 0s and 1s
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

int currentPlayer = 1;
int selectedPieceRow = -1;
int selectedPieceCol = -1;

void displayBoard() {
    printf("     A   B   C   D   E   F   G   H\n");
    printf("   +---+---+---+---+---+---+---+---+\n");

    for (int row = 0; row < 8; row++) {
        printf(" %d ", row + 1);
        for (int col = 0; col < 8; col++) {
            printf("|");
            if (board[row][col] == 1) {
                printf(" O ");
            } else if (board[row][col] == 2) {
                printf(" X ");
            } else {
                printf("   ");
            }
        }
        printf("| %d\n", row + 1);
        printf("   +---+---+---+---+---+---+---+---+\n");
    }

    printf("     A   B   C   D   E   F   G   H\n");
}

int isValidMove(int row1, int col1, int row2, int col2) {
    if (board[row2][col2] != 0) {
        return 0;
    }

    if (row2 < 0 || row2 > 7 || col2 < 0 || col2 > 7) {
        return 0;
    }

    if (currentPlayer == 1 && row2 > row1) {
        return 0;
    }

    if (currentPlayer == 2 && row2 < row1) {
        return 0;
    }

    if (abs(row2 - row1) == 1 && abs(col2 - col1) == 1) {
        return 1;
    } else if (abs(row2 - row1) == 2 && abs(col2 - col1) == 2) {
        int middleRow = (row1 + row2) / 2;
        int middleCol = (col1 + col2) / 2;

        if (board[middleRow][middleCol] == currentPlayer % 2 + 1) {
            return 1;
        }
    }

    return 0;
}

void selectPiece(int row, int col) {
    if (board[row][col] == currentPlayer) {
        selectedPieceRow = row;
        selectedPieceCol = col;
    }
}

void movePiece(int row, int col) {
    if (isValidMove(selectedPieceRow, selectedPieceCol, row, col)) {
        board[row][col] = currentPlayer;
        board[selectedPieceRow][selectedPieceCol] = 0;

        int distance = abs(row - selectedPieceRow);
        if (distance == 2) {
            int middleRow = (row + selectedPieceRow) / 2;
            int middleCol = (col + selectedPieceCol) / 2;
            board[middleRow][middleCol] = 0;
        }

        currentPlayer = currentPlayer % 2 + 1;  //switch to the other player
    }
}

int main() {
    while (1) {
        displayBoard();
        printf("Player %d's turn\n", currentPlayer);

        if (selectedPieceRow == -1) {
            printf("Select a piece: ");
        } else {
            printf("Move the piece: ");
        }

        char input[10];
        scanf("%s", input);

        if (input[0] >= 'A' && input[0] <= 'H' && input[1] >= '1' && input[1] <= '8') {
            int row = input[1] - '1';
            int col = input[0] - 'A';

            if (selectedPieceRow == -1) {
                selectPiece(row, col);
            } else {
                movePiece(row, col);
                selectedPieceRow = -1; //deselect the piece
                selectedPieceCol = -1;
            }
        }
    }

    return 0;
}