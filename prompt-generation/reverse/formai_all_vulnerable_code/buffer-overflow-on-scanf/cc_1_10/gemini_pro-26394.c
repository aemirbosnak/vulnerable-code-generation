//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 9
#define NUM_PLAYERS 2

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int solved;
} SudokuBoard;

typedef struct {
    char name[20];
    int score;
} Player;

void printBoard(SudokuBoard* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

int checkValidMove(SudokuBoard* board, int row, int col, int value) {
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[row][i] == value) {
            return 0;
        }
    }
    
    // Check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[i][col] == value) {
            return 0;
        }
    }
    
    // Check 3x3 subgrid
    int boxRow = row / 3;
    int boxCol = col / 3;
    for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
        for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
            if (board->board[i][j] == value) {
                return 0;
            }
        }
    }
    
    return 1;
}

int solveSudoku(SudokuBoard* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                for (int value = 1; value <= BOARD_SIZE; value++) {
                    if (checkValidMove(board, i, j, value)) {
                        board->board[i][j] = value;
                        if (solveSudoku(board)) {
                            return 1;
                        } else {
                            board->board[i][j] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    
    board->solved = 1;
    return 1;
}

int main() {
    SudokuBoard board;
    Player players[NUM_PLAYERS];
    
    // Initialize board
    memset(board.board, 0, sizeof(board.board));
    board.solved = 0;
    
    // Initialize players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    
    // Main game loop
    while (!board.solved) {
        // Print board
        printBoard(&board);
        
        // Get player input
        for (int i = 0; i < NUM_PLAYERS; i++) {
            int row, col, value;
            printf("%s's turn: ", players[i].name);
            scanf("%d %d %d", &row, &col, &value);
            
            // Check if move is valid
            if (checkValidMove(&board, row, col, value)) {
                // Make move
                board.board[row][col] = value;
                
                // Check if board is solved
                if (solveSudoku(&board)) {
                    players[i].score++;
                    printf("%s wins!\n", players[i].name);
                    break;
                }
            } else {
                printf("Invalid move. Try again.\n");
            }
        }
    }
    
    // Print final scores
    printf("Final scores:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    
    return 0;
}