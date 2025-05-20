//FormAI DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>

char board[3][3];

// initialize the game board
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// print the game board
void print_board() {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// check if the game is over
char check_game_over() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
        return board[2][0];
    }
    // check tie
    int empty_spots = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                empty_spots++;
            }
        }
    }
    if (empty_spots == 0) {
        return 'T';
    }
    // game not over
    return ' ';
}

int main() {
    init_board();
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 (X) - Player 2 (O)\n");
    int player = 1;
    char symbol = ' ';
    while (check_game_over() == ' ') {
        printf("\nPlayer %d's turn:\n", player);
        symbol = (player == 1) ? 'X' : 'O';
        int row = 0, col = 0;
        do {
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
        } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ');
        board[row-1][col-1] = symbol;
        print_board();
        player = (player == 1) ? 2 : 1;
    }
    char result = check_game_over();
    if (result == 'T') {
        printf("It's a tie!\n");
    } else {
        printf("Player %d (%c) wins!\n", (player == 1) ? 2 : 1, result);
    }
    return 0;
}