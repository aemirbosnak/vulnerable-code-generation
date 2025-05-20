//FormAI DATASET v1.0 Category: Chess engine ; Style: recursive
#include <stdio.h>

// Function to check if move is valid
int isValidMove(char board[][8], int i, int j, int x, int y) {
    if (!(i >= 0 && i <= 7 && j >= 0 && j <= 7 && x >= 0 && x <= 7 && y >= 0 && y <= 7))
        return 0;

    if (x-i == 2 && y-j == 1 && board[i+1][j] == 'N')
        return 0;

    if (x-i == 2 && y-j == -1 && board[i+1][j] == 'N')
        return 0;

    if (x-i == -2 && y-j == 1 && board[i-1][j] == 'N')
        return 0;

    if (x-i == -2 && y-j == -1 && board[i-1][j] == 'N')
        return 0;

    if (x-i == 1 && y-j == 2 && board[i][j+1] == 'N')
        return 0;

    if (x-i == -1 && y-j == 2 && board[i][j+1] == 'N')
        return 0;

    if (x-i == 1 && y-j == -2 && board[i][j-1] == 'N')
        return 0;

    if (x-i == -1 && y-j == -2 && board[i][j-1] == 'N')
        return 0;

    return 1;
}

// Recursive function to solve the problem
int solve(char board[][8], int i, int j, int count) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8)
        return 0;

    board[i][j] = 'Q';

    if (count == 8)
        return 1;

    int x, y;
    for (x=0; x<8; x++) {
        for (y=0; y<8; y++) {
            if (board[x][y] != 'Q' && board[x][y] != 'N' && isValidMove(board, i, j, x, y)) {
                int success = solve(board, x, y, count + 1);
                if (success)
                    return 1;
            }
        }
    }

    board[i][j] = '.';
    return 0;
}

int main() {
    char board[8][8] = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}
    };

    printf("Enter the position of the knight (row column): ");
    int row, col;
    scanf("%d %d", &row, &col);

    // Place knight on board
    board[row-1][col-1] = 'N';

    // Solve the problem recursively
    int success = 0;
    int i, j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (board[i][j] != 'Q' && board[i][j] != 'N') {
                success = solve(board, i, j, 1);
                if (success)
                    break;
            }
        }
        if (success)
            break;
    }

    // Print the solution
    printf("\n");
    int k, l;
    for (k=0; k<8; k++) {
        for (l=0; l<8; l++) {
            printf("%c ", board[k][l]);
        }
        printf("\n");
    }

    return 0;
}