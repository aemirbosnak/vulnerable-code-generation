//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the dimensions of the board
#define ROWS 3
#define COLS 3

// Define player and AI symbols
#define PLAYER_SYMBOL 'X'
#define AI_SYMBOL 'O'

// Define game board data structure
typedef struct TicTacToeBoard {
    char board[ROWS][COLS]; // The game board
    int numMoves; // The number of moves made
    char winner; // The winner of the game (if any)
} TicTacToeBoard;

// Initialize the game board
void initializeBoard(TicTacToeBoard* board) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board->board[i][j] = '-';
        }
    }
    board->numMoves = 0;
    board->winner = '-';
}

// Print the game board
void printBoard(TicTacToeBoard* board) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

// Check if a player has won the game
char checkWinner(TicTacToeBoard* board) {
    int i, j;
    // Check rows
    for(i=0; i<ROWS; i++) {
        if(board->board[i][0] != '-' && board->board[i][0] == board->board[i][1] && board->board[i][1] == board->board[i][2]) {
            return board->board[i][0];
        }
    }
    // Check columns
    for(j=0; j<COLS; j++) {
        if(board->board[0][j] != '-' && board->board[0][j] == board->board[1][j] && board->board[1][j] == board->board[2][j]) {
            return board->board[0][j];
        }
    }
    // Check diagonals
    if(board->board[0][0] != '-' && board->board[0][0] == board->board[1][1] && board->board[1][1] == board->board[2][2]) {
        return board->board[0][0];
    }
    if(board->board[0][2] != '-' && board->board[0][2] == board->board[1][1] && board->board[1][1] == board->board[2][0]) {
        return board->board[0][2];
    }
    // Check for a tie
    if(board->numMoves == ROWS*COLS) {
        return 'T';
    }
    // No winner yet
    return '-';
}

// Check if a move is valid
int isValidMove(TicTacToeBoard* board, int row, int col) {
    if(row<0 || row>=ROWS || col<0 || col>=COLS) {
        return 0;
    }
    if(board->board[row][col] != '-') {
        return 0;
    }
    return 1;
}

// Make a move on the game board
void makeMove(TicTacToeBoard* board, int row, int col, char symbol) {
    board->board[row][col] = symbol;
    board->numMoves++;
}

// Make the AI move on the game board
void makeAIMove(TicTacToeBoard* board) {
    int i, j, row, col;
    // Check if the AI can win in one move
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board->board[i][j] == '-') {
                board->board[i][j] = AI_SYMBOL;
                if(checkWinner(board) == AI_SYMBOL) {
                    return;
                }
                board->board[i][j] = '-';
            }
        }
    }
    // Check if the player can win in one move and block them
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board->board[i][j] == '-') {
                board->board[i][j] = PLAYER_SYMBOL;
                if(checkWinner(board) == PLAYER_SYMBOL) {
                    board->board[i][j] = AI_SYMBOL;
                    return;
                }
                board->board[i][j] = '-';
            }
        }
    }
    // Choose a random empty space on the board
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
    } while(!isValidMove(board, row, col));
    board->board[row][col] = AI_SYMBOL;
}

int main() {
    TicTacToeBoard board;
    initializeBoard(&board);
    int row, col;
    char turn = PLAYER_SYMBOL;
    while(board.winner == '-') {
        if(turn == PLAYER_SYMBOL) {
            printf("It's your turn!\n");
            printBoard(&board);
            printf("Enter Row (0 - 2): ");
            scanf("%d", &row);
            printf("Enter Column (0 - 2): ");
            scanf("%d", &col);
            if(isValidMove(&board, row, col)) {
                makeMove(&board, row, col, turn);
                turn = AI_SYMBOL;
            }
            else {
                printf("Invalid move, try again.\n");
            }
        }
        else {
            printf("It's the AI's turn!\n");
            makeAIMove(&board);
            turn = PLAYER_SYMBOL;
        }
        board.winner = checkWinner(&board);
    }
    printf("Game over!\n");
    printBoard(&board);
    if(board.winner == PLAYER_SYMBOL) {
        printf("You win!\n");
    }
    else if(board.winner == AI_SYMBOL) {
        printf("The AI wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }
    return 0;
}