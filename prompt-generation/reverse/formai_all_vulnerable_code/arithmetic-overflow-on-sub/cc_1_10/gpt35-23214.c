//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

void print_board(char board[3][3]) {
    printf("   1   2   3\n");
    printf("1 %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("2 %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("3 %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

bool is_valid_move(char board[3][3], int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

bool check_win(char board[3][3], char player) {
    // check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }
    // check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }
    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int evaluate(char board[3][3]) {
    int score = 0;
    // check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == 'X') {
                score -= 10;
            } else if (board[row][0] == 'O') {
                score += 10;
            }
        }
    }
    // check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == 'X') {
                score -= 10;
            } else if (board[0][col] == 'O') {
                score += 10;
            }
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            score -= 10;
        } else if (board[0][0] == 'O') {
            score += 10;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            score -= 10;
        } else if (board[0][2] == 'O') {
            score += 10;
        }
    }
    return score;
}

int minimax(char board[3][3], int depth, bool is_maximizer) {
    // check for terminal state (win/draw)
    if (check_win(board, 'X')) {
        return -10 + depth;
    } else if (check_win(board, 'O')) {
        return 10 - depth;
    } else if (depth == 9) { // board is full
        return 0;
    }

    if (is_maximizer) {
        int max_score = -1000;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (is_valid_move(board, row, col)) {
                    board[row][col] = 'O';
                    int score = minimax(board, depth+1, false);
                    board[row][col] = ' ';
                    if (score > max_score) {
                        max_score = score;
                    }
                }
            }
        }
        return max_score;
    } else {
        int min_score = 1000;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (is_valid_move(board, row, col)) {
                    board[row][col] = 'X';
                    int score = minimax(board, depth+1, true);
                    board[row][col] = ' ';
                    if (score < min_score) {
                        min_score = score;
                    }
                }
            }
        }
        return min_score;
    }
}

void ai_move(char board[3][3]) {
    int best_score = -1000;
    int best_row = -1;
    int best_col = -1;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (is_valid_move(board, row, col)) {
                board[row][col] = 'O';
                int score = minimax(board, 0, false);
                board[row][col] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_row = row;
                    best_col = col;
                }
            }
        }
    }
    board[best_row][best_col] = 'O';
    printf("AI moves: (%d,%d)\n", best_row+1, best_col+1);
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int turn = 0;
    printf("Welcome to the Tic Tac Toe AI Game!\n");
    printf("You will be playing against an AI opponent.\n");
    printf("You are X and the AI is O. Let's begin!\n");

    while (true) {
        print_board(board);
        if (turn % 2 == 0) { // player's turn
            int row, col;
            do {
                printf("Enter row (1-3): ");
                scanf("%d", &row);
                printf("Enter column (1-3): ");
                scanf("%d", &col);
                row--;
                col--;
            } while (!is_valid_move(board, row, col));
            board[row][col] = 'X';
        } else { // AI's turn
            ai_move(board);
        }
        if (check_win(board, 'X')) {
            print_board(board);
            printf("Congratulations! You won!\n");
            break;
        } else if (check_win(board, 'O')) {
            print_board(board);
            printf("Sorry, the AI won. \n");
            break;
        } else if (turn == 8) {
            print_board(board);
            printf("It's a draw!\n");
            break;
        }
        turn++;
    }
    return 0;
}