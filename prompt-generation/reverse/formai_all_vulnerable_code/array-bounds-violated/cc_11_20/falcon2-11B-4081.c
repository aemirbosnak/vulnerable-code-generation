//Falcon2-11B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>

int main() {
    // Print "Hello World"
    printf("Hello World!\n");

    // Play a game of tic-tac-toe
    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int turn = 0;
    int winner = 0;

    while (winner == 0) {
        // Print the current board state
        printf("Turn %d:\n", turn);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        // Get user input
        int row, col;
        printf("Enter row (0-%d): ", 2);
        scanf("%d", &row);
        if (row < 0 || row > 2) {
            printf("Invalid row! Please try again.\n");
            continue;
        }
        printf("Enter column (0-%d): ", 2);
        scanf("%d", &col);
        if (col < 0 || col > 2) {
            printf("Invalid column! Please try again.\n");
            continue;
        }

        // Update the board and check for a winner
        board[row][col] = turn;
        if (turn == 0) {
            winner = checkHorizontal(board);
            if (winner!= 0) {
                break;
            }
            winner = checkVertical(board);
            if (winner!= 0) {
                break;
            }
            winner = checkDiagonal(board);
            if (winner!= 0) {
                break;
            }
        } else if (turn == 1) {
            winner = checkHorizontal(board);
            if (winner!= 0) {
                break;
            }
            winner = checkVertical(board);
            if (winner!= 0) {
                break;
            }
            winner = checkDiagonal(board);
            if (winner!= 0) {
                break;
            }
        } else if (turn == 2) {
            winner = checkHorizontal(board);
            if (winner!= 0) {
                break;
            }
            winner = checkVertical(board);
            if (winner!= 0) {
                break;
            }
            winner = checkDiagonal(board);
            if (winner!= 0) {
                break;
            }
        }

        // Switch turn
        if (turn == 0) {
            turn = 1;
        } else if (turn == 1) {
            turn = 2;
        } else if (turn == 2) {
            turn = 0;
        }

        // Print the current board state again
        printf("Turn %d:\n", turn);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Print the final board state
    printf("Game over!\n");
    printf("Winner: %d\n", winner);

    // Return 0 to indicate successful program execution
    return 0;
}

// Helper functions
int checkHorizontal(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        int row[3];
        for (int j = 0; j < 3; j++) {
            row[j] = board[i][j];
        }
        int count = 0;
        for (int j = 0; j < 3; j++) {
            if (row[j] == row[j + 1]) {
                count++;
            }
        }
        if (count == 3) {
            return row[0];
        }
    }
    return 0;
}

int checkVertical(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        int row[3];
        for (int j = 0; j < 3; j++) {
            row[j] = board[j][i];
        }
        int count = 0;
        for (int j = 0; j < 3; j++) {
            if (row[j] == row[j + 1]) {
                count++;
            }
        }
        if (count == 3) {
            return row[0];
        }
    }
    return 0;
}

int checkDiagonal(int board[3][3]) {
    int row[3];
    for (int i = 0; i < 3; i++) {
        row[i] = board[i][i];
    }
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (row[i] == row[i + 1]) {
            count++;
        }
    }
    if (count == 3) {
        return row[0];
    }

    row[0] = board[2][0];
    row[1] = board[1][1];
    row[2] = board[0][2];
    count = 0;
    for (int i = 0; i < 3; i++) {
        if (row[i] == row[i + 1]) {
            count++;
        }
    }
    if (count == 3) {
        return row[0];
    }
    return 0;
}