//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include <stdio.h>

// Function to display Tic Tac Toe board
void display(char board[3][3]) {
    printf("---Tic Tac Toe---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2)
                printf("|");
        }
        printf("\n");
        if (i != 2)
            printf("---|---|---\n");
    }
}

// Function to check win condition
int check_win(char board[3][3], char player) {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    // Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

// Function to play the game
void play(char board[3][3]) {
    char players[2] = {'X', 'O'};
    int player = 0;
    int moves = 0;
    int row, col;
    while (moves < 9) {
        display(board);
        // Player's turn
        printf("\nPlayer %c's turn.\n", players[player]);
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        // Check input validity
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            printf("Invalid input. Try again.\n");
            continue;
        }
        // Make move
        board[row-1][col-1] = players[player];
        moves++;
        // Check win condition
        if (check_win(board, players[player])) {
            display(board);
            printf("Congratulations! Player %c wins!\n", players[player]);
            return;
        }
        // Next player's turn
        player = (player + 1) % 2;
    }
    display(board);
    printf("It's a tie!\n");
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    play(board);
    return 0;
}