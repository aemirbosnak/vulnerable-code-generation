//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>

void print_board(char board[3][3]) {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

char check_win(char board[3][3]) {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

int get_move(char board[3][3]) {
    int row, col;

    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter column (1-3): ");
    scanf("%d", &col);

    // Convert input to zero-indexed coordinates
    row--;
    col--;

    // Check if move is valid
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move, try again\n");
        return get_move(board);
    }
    if (board[row][col] != ' ') {
        printf("That space is already taken, try again\n");
        return get_move(board);
    }

    return row * 3 + col;
}

int minimax(char board[3][3], char player) {
    char winner = check_win(board);
    if (winner != ' ') {
        // Game is over
        if (winner == player) {
            // Player won
            return 1;
        } else {
            // Player lost
            return -1;
        }
    } else {
        // Game is not over
        int i, j, score, best_score;
        if (player == 'X') {
            // Maximize score
            best_score = -2;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] = player;
                        score = minimax(board, 'O');
                        board[i][j] = ' ';
                        if (score > best_score) {
                            best_score = score;
                        }
                    }
                }
            }
        } else {
            // Minimize score
            best_score = 2;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] = player;
                        score = minimax(board, 'X');
                        board[i][j] = ' ';
                        if (score < best_score) {
                            best_score = score;
                        }
                    }
                }
            }
        }
        return best_score;
    }
}

void play_game(char board[3][3], char player) {
    char winner = check_win(board);
    int move;

    if (winner != ' ') {
        // Game is over
        printf("Winner: %c\n", winner);
        return;
    } else if (player == 'X') {
        // Player's turn
        print_board(board);
        move = get_move(board);
        board[move / 3][move % 3] = player;
        play_game(board, 'O');
    } else {
        // Computer's turn
        printf("Computer's turn\n");
        int i, j, score, best_score = -2;
        int best_row = 0, best_col = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = player;
                    score = minimax(board, 'X');
                    board[i][j] = ' ';
                    if (score > best_score) {
                        best_score = score;
                        best_row = i;
                        best_col = j;
                    }
                }
            }
        }
        board[best_row][best_col] = player;
        play_game(board, 'X');
    }
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    play_game(board, 'X');

    return 0;
}