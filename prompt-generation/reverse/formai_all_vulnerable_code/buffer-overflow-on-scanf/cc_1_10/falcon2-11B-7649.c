//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdbool.h>

typedef struct board {
    int board[3][3];
    bool winner;
} Board;

Board initialize_board(void) {
    Board board;
    board.winner = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board.board[i][j] = 0;
        }
    }
    return board;
}

void print_board(Board board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board.board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_winner(Board board, int player) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (board.board[i][0] == player && board.board[i][1] == player && board.board[i][2] == player) {
            count++;
        }
        if (board.board[0][i] == player && board.board[1][i] == player && board.board[2][i] == player) {
            count++;
        }
        if (board.board[0][0] == player && board.board[1][1] == player && board.board[2][2] == player) {
            count++;
        }
        if (board.board[0][2] == player && board.board[1][1] == player && board.board[2][0] == player) {
            count++;
        }
    }
    if (count == 3) {
        return true;
    }
    return false;
}

bool is_full(Board board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void make_move(Board *board, int player, int row, int col) {
    if (is_full(*board)) {
        return;
    }
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return;
    }
    board->board[row][col] = player;
    if (is_winner(*board, player)) {
        board->winner = true;
    }
}

int main(void) {
    Board board;
    int player;
    int row, col;
    printf("Welcome to Tic Tac Toe!\n");
    print_board(board);
    player = 0;
    while (!is_full(board) &&!is_winner(board, player)) {
        printf("Player %d, please enter row and column for your move: ", player + 1);
        scanf("%d%d", &row, &col);
        make_move(&board, player, row, col);
        printf("Player %d, please enter row and column for your move: ", (player + 1) % 2);
        scanf("%d%d", &row, &col);
        make_move(&board, (player + 1) % 2, row, col);
        print_board(board);
        if (is_winner(board, player)) {
            printf("%d wins!\n", player + 1);
            break;
        }
        if (is_winner(board, (player + 1) % 2)) {
            printf("%d wins!\n", (player + 1) % 2);
            break;
        }
        if (is_full(board)) {
            printf("It's a tie!\n");
            break;
        }
        player++;
    }
    if (is_winner(board, player)) {
        printf("%d wins!\n", player + 1);
    } else if (is_winner(board, (player + 1) % 2)) {
        printf("%d wins!\n", (player + 1) % 2);
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}