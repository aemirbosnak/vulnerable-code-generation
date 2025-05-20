//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>

char board[3][3]; // the game board

void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-'; // set all fields to empty
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]); // print each field
        }
        printf("\n");
    }
}

int check_win() {
    int i;

    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1; // row i wins
        }
    }

    // check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return 1; // column i wins
        }
    }

    // check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1; // diagonal 1 wins
    }
    if (board[2][0] != '-' && board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
        return 1; // diagonal 2 wins
    }

    return 0; // no one wins yet
}

void player_move(int player) {
    int row, col;
    while (1) {
        printf("Player %d, enter row and column (1-3): ", player);
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Try again.\n");
        } else if (board[row-1][col-1] != '-') {
            printf("Field already occupied. Try again.\n");
        } else {
            board[row-1][col-1] = (player == 1) ? 'X' : 'O';
            break;
        }
    }
}

int main() {
    int turn = 1;

    init_board();

    while (1) {
        printf("Turn %d\n", turn);
        print_board();
        player_move(turn);
        if (check_win()) {
            printf("Player %d wins!\n", turn);
            break;
        }
        if (++turn > 2) {
            printf("It's a draw.\n");
            break;
        }
    }

    return 0;
}