//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a Tic Tac Toe board
typedef struct {
    int board[3][3];
} Board;

// Function to print the Tic Tac Toe board
void printBoard(Board board) {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%c ", i + 'A');
        for (int j = 0; j < 3; j++) {
            printf("%d ", board.board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int isGameOver(Board board) {
    // Check if the board is full
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.board[i][j] == 0) {
                return 0;
            }
        }
    }

    // Check if there is a winner
    for (int i = 0; i < 3; i++) {
        if (board.board[0][i] == board.board[1][i] &&
            board.board[0][i] == board.board[2][i] &&
            board.board[0][i]!= 0) {
            return 1;
        }
        if (board.board[1][i] == board.board[2][i] &&
            board.board[1][i]!= 0) {
            return 1;
        }
        if (board.board[2][i] == board.board[0][i] &&
            board.board[2][i]!= 0) {
            return 1;
        }
    }

    // Check if there is a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 2;
}

// Function to choose a random move
int randomMove(Board board) {
    int move = 0;
    srand(time(NULL));

    while (board.board[rand() % 3][rand() % 3]!= 0) {
        move++;
    }

    return move;
}

// Function to get a move from the user
int getMove(Board board) {
    int move = 0;

    printf("Player X, please enter your move: ");
    scanf("%d", &move);

    if (move > 8 || move < 1) {
        printf("Invalid move. Please enter a number between 1 and 9.\n");
        return -1;
    }

    if (board.board[move - 1][0] == 1 ||
        board.board[move - 1][1] == 1 ||
        board.board[move - 1][2] == 1) {
        printf("Move already taken. Please enter another move.\n");
        return -1;
    }

    board.board[move - 1][0] = 1;
    return move;
}

// Function to get a move from the AI
int aiMove(Board board) {
    int move = 0;
    int bestMove = -1;
    int score[9];

    // Check all possible moves
    for (int i = 0; i < 9; i++) {
        score[i] = -1;
        board.board[i][0] = 0;
        board.board[i][1] = 0;
        board.board[i][2] = 0;
    }

    // Check all possible moves for player X
    for (int i = 0; i < 9; i++) {
        if (board.board[i][0] == 0 && board.board[i][1] == 0 && board.board[i][2] == 0) {
            board.board[i][0] = 1;
            board.board[i][1] = 1;
            board.board[i][2] = 1;
            score[i] = isGameOver(board);
            board.board[i][0] = 0;
            board.board[i][1] = 0;
            board.board[i][2] = 0;
        }
    }

    // Check all possible moves for player O
    for (int i = 0; i < 9; i++) {
        if (board.board[i][0] == 0 && board.board[i][1] == 0 && board.board[i][2] == 0) {
            board.board[i][0] = 2;
            board.board[i][1] = 2;
            board.board[i][2] = 2;
            score[i] = isGameOver(board);
            board.board[i][0] = 0;
            board.board[i][1] = 0;
            board.board[i][2] = 0;
        }
    }

    // Choose the best move
    for (int i = 0; i < 9; i++) {
        if (score[i] == -1 && bestMove == -1) {
            bestMove = i;
        }
        if (score[i] > score[bestMove]) {
            bestMove = i;
        }
    }

    // Place the move on the board
    board.board[bestMove][0] = 1;
    return bestMove;
}

int main() {
    Board board;

    int move;

    // Welcome message
    printf("Welcome to Tic Tac Toe!n");

    // Main game loop
    while (1) {
        // Print the current board
        printBoard(board);

        // Get a move from the user
        move = getMove(board);

        // Check if the game is over
        if (move == -1) {
            printf("Invalid move. Please enter a number between 1 and 9.\n");
            continue;
        }

        // Update the board
        board.board[move - 1][0] = 1;

        // Check if the game is over
        if (isGameOver(board)!= -1) {
            printf("Player X wins!\n");
            break;
        }

        // Get a move from the AI
        move = aiMove(board);

        // Update the board
        board.board[move][0] = 2;

        // Check if the game is over
        if (isGameOver(board)!= -1) {
            printf("Player O wins!\n");
            break;
        }

        // Random move if the game is still going
        if (isGameOver(board) == -1) {
            move = randomMove(board);
            board.board[move][0] = 0;
        }

        // Print the updated board
        printBoard(board);
    }

    return 0;
}