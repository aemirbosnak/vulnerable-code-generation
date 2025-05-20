//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

// Representation of the board state
typedef struct Board {
    int** cells;
    int empty_count;
} Board;

// Create a new board with all cells initialized to 0 (empty)
Board* new_board() {
    Board* board = (Board*) malloc(sizeof(Board));
    int** cells = (int**) malloc(sizeof(int*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        cells[i] = (int*) calloc(BOARD_SIZE, sizeof(int));
        board->empty_count += BOARD_SIZE;
    }
    board->cells = cells;
    return board;
}

// Free memory used by the board
void free_board(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board->cells[i]);
    }
    free(board->cells);
    free(board);
}

// Check if the board is full (no empty cells)
bool board_full(Board* board) {
    return board->empty_count == 0;
}

// Check if the given row and column are within the board bounds
bool valid_move(Board* board, int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board->cells[row][col] == 0;
}

// Print the current board state to the console
void print_board(Board* board) {
    printf("   0 1 2\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->cells[i][j] == 0 ? '-' : board->cells[i][j] == 1 ? 'X' : 'O');
        }
        printf("\n");
    }
}

// Check if the current board state is a win for the given player
bool check_win(Board* board, int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        bool row_win = true, col_win = true, diag1_win = true, diag2_win = true;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cells[i][j] != player) {
                row_win = false;
            }
            if (board->cells[j][i] != player) {
                col_win = false;
            }
            if (board->cells[j][j] != player) {
                diag1_win = false;
            }
            if (board->cells[j][BOARD_SIZE-1-j] != player) {
                diag2_win = false;
            }
        }
        if (row_win || col_win || diag1_win || diag2_win) {
            return true;
        }
    }
    return false;
}

// Make a move on the board for the given player at the given row and column
void make_move(Board* board, int row, int col, int player) {
    board->cells[row][col] = player;
    board->empty_count--;
}

// Undo a move on the board for the given player at the given row and column
void undo_move(Board* board, int row, int col, int player) {
    board->cells[row][col] = 0;
    board->empty_count++;
}

// Alpha-beta search for the best move for the given player
int alphabeta(Board* board, int player, int depth, int alpha, int beta) {
    if (check_win(board, player)) return 1;
    if (check_win(board, player == 1 ? 2 : 1)) return -1;
    if (board_full(board)) return 0;
    if (depth == 0) return 0;
    int best_score = player == 1 ? -1 : 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (valid_move(board, i, j)) {
                make_move(board, i, j, player);
                int score = alphabeta(board, player == 1 ? 2 : 1, depth-1, alpha, beta);
                undo_move(board, i, j, player);
                if (player == 1) {
                    if (score > best_score) {
                        best_score = score;
                        alpha = score;
                    }
                } else {
                    if (score < best_score) {
                        best_score = score;
                        beta = score;
                    }
                }
                if (beta <= alpha) {
                    return best_score;
                }
            }
        }
    }
    return best_score;
}

// Get a move for the AI player using the alphabeta search
void get_ai_move(Board* board, int player, int* row, int* col) {
    int best_score = player == 1 ? -1 : 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (valid_move(board, i, j)) {
                make_move(board, i, j, player);
                int score = alphabeta(board, player == 1 ? 2 : 1, 6, -1, 1);
                undo_move(board, i, j, player);
                if (player == 1) {
                    if (score > best_score) {
                        best_score = score;
                        *row = i;
                        *col = j;
                    }
                } else {
                    if (score < best_score) {
                        best_score = score;
                        *row = i;
                        *col = j;
                    }
                }
            }
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe AI!\n");
    printf("You are playing against our Donald Knuth-style AI.\n");
    Board* board = new_board();
    int player = 1;
    while (!board_full(board) && !check_win(board, player) && !check_win(board, player == 1 ? 2 : 1)) {
        print_board(board);
        if (player == 1) {
            printf("Your turn: enter row and column (0-2, space-separated): ");
            int row, col;
            scanf("%d %d", &row, &col);
            while (!valid_move(board, row, col)) {
                printf("Invalid move, please try again: ");
                scanf("%d %d", &row, &col);
            }
            make_move(board, row, col, player);
        } else {
            printf("AI's turn: thinking...\n");
            int row, col;
            get_ai_move(board, player, &row, &col);
            make_move(board, row, col, player);
            printf("AI played row %d, column %d\n", row, col);
        }
        player = player == 1 ? 2 : 1;
    }
    print_board(board);
    if (check_win(board, 1)) {
        printf("You win!\n");
    } else if (check_win(board, 2)) {
        printf("AI wins!\n");
    } else {
        printf("Tie game.\n");
    }
    free_board(board);
    return 0;
}