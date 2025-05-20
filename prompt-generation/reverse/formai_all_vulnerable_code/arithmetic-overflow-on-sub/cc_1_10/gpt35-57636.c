//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 3

typedef enum {NONE, PLAYER1, PLAYER2} GamePiece;
typedef enum {NONE_WON, PLAYER1_WON, PLAYER2_WON, DRAW, IN_PROGRESS} GameState;

typedef struct {
    GamePiece position[SIZE][SIZE];
    int movesLeft;
    GameState state;
} TicTacToeBoard;

//Initializes the board
void initializeBoard(TicTacToeBoard* board) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board->position[i][j] = NONE;
        }
    }
    board->movesLeft = SIZE * SIZE;
    board->state = IN_PROGRESS;

}

//Function to display the board
void displayBoard(TicTacToeBoard board) {
    for(int i = 0; i < SIZE; i++) {
        printf(" ");
        for(int j = 0; j < SIZE; j++) {
            switch(board.position[i][j]) {
                case NONE:
                    printf(" ");
                    break;
                case PLAYER1:
                    printf("X");
                    break;
                case PLAYER2:
                    printf("O");
                    break;
                default:
                    break;
            }
            if(j < SIZE - 1) {
                printf(" | ");
            }
        }
        printf("\n");
        if(i < SIZE - 1) {
            printf("-----------\n");
        }
    }
}

//Function to Check if a player has won
bool isWinner(GamePiece piece, TicTacToeBoard board) {
    for(int i = 0; i < SIZE; i++) {
        //Check for horizontal win
        if(board.position[i][0] == piece && board.position[i][1] == piece && board.position[i][2] == piece) {
            return true;
        }
        //Check for vertical win
        if(board.position[0][i] == piece && board.position[1][i] == piece && board.position[2][i] == piece) {
            return true;
        }
    }
    //Check for diagonal win
    if(board.position[0][0] == piece && board.position[1][1] == piece && board.position[2][2] == piece) {
        return true;
    }
    if(board.position[2][0] == piece && board.position[1][1] == piece && board.position[0][2] == piece) {
        return true;
    }
    return false;
}

//Function to check if game is a draw
bool isDraw(TicTacToeBoard board) {
    return board.movesLeft == 0;
}

//Function to get player move
void getPlayerMove(TicTacToeBoard* board, int player) {
    int row, col;
    bool validMove = false;
    do {
        printf("Player %d, enter row and column position (1-3):", player);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(row < 0 || row > SIZE - 1 || col < 0 || col > SIZE - 1) {
            printf("Invalid position.\n");
            continue;
        }
        if(board->position[row][col] != NONE) {
            printf("Position already occupied.\n");
            continue;
        }
        validMove = true;
    } while(!validMove);
    board->position[row][col] = (player == 1) ? PLAYER1 : PLAYER2;
    board->movesLeft--;
}

//Function to get AI move
void getAIMove(TicTacToeBoard* board) {
    int row, col;
    bool validMove = false;
    while(!validMove) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if(board->position[row][col] == NONE) {
            validMove = true;
        }
    }
    board->position[row][col] = PLAYER2;
    board->movesLeft--;
}

//Function to play game
void playGame() {
    TicTacToeBoard board;
    int currentPlayer = 1;
    initializeBoard(&board);
    while(board.state == IN_PROGRESS) {
        displayBoard(board);
        if(currentPlayer == 1) {
            getPlayerMove(&board, currentPlayer);
        } else {
            getAIMove(&board);
        }
        if(isWinner((currentPlayer == 1) ? PLAYER1 : PLAYER2, board)) {
            board.state = (currentPlayer == 1) ? PLAYER1_WON : PLAYER2_WON;
            displayBoard(board);
            printf("Player %d wins!\n", currentPlayer);
            return;
        }
        if(isDraw(board)) {
            board.state = DRAW;
            displayBoard(board);
            printf("Game is a draw!\n");
            return;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

int main() {
    playGame();
    return 0;
}