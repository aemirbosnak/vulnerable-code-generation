//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void playTicTacToe() {
    // Create the game board
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Create the moves list
    Node* moves = NULL;

    // Get the player's move
    int moveX, moveY;

    // Place the player's move on the board
    board[moveX][moveY] = 1;

    // Add the move to the list
    moves = createNode(moveX, moveY);

    // Check if the player has won
    if (checkWin(board, moves)) {
        printf("You have won!");
    } else if (moves->next == NULL) {
        printf("It's a draw!");
    } else {
        // Make the AI's move
        moveX = makeMove(board, moves);

        // Place the AI's move on the board
        board[moveX][moveY] = 2;

        // Add the move to the list
        moves = createNode(moveX, moveY);

        // Check if the AI has won
        if (checkWin(board, moves)) {
            printf("The AI has won!");
        } else {
            // Prompt the player to make their next move
            printf("Make your next move (x, y): ");
            scanf("%d %d", &moveX, &moveY);

            // Place the player's move on the board
            board[moveX][moveY] = 1;

            // Add the move to the list
            moves = createNode(moveX, moveY);

            // Check if the player has won
            if (checkWin(board, moves)) {
                printf("You have won!");
            } else if (moves->next == NULL) {
                printf("It's a draw!");
            } else {
                playTicTacToe();
            }
        }
    }
}

int checkWin(int** board, Node* moves) {
    // Check for a horizontal win
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            int win = 1;
            for (Node* move = moves; move != NULL; move++) {
                if (board[move->x][move->y] != moves->x) {
                    win = 0;
                }
            }
            if (win) {
                return 1;
            }
        }
    }

    // Check for a vertical win
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            int win = 1;
            for (Node* move = moves; move != NULL; move++) {
                if (board[move->x][move->y] != moves->y) {
                    win = 0;
                }
            }
            if (win) {
                return 1;
            }
        }
    }

    // Check for a diagonal win
    for (int d = 0; d < BOARD_SIZE; d++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            int win = 1;
            for (Node* move = moves; move != NULL; move++) {
                if (board[move->x][move->y] != d) {
                    win = 0;
                }
            }
            if (win) {
                return 1;
            }
        }
    }

    // No win
    return 0;
}

int makeMove(int** board, Node* moves) {
    // Get the best move
    int moveX = -1;
    int moveY = -1;
    int maxScore = -1;

    // Iterate over all possible moves
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            // Check if the move is valid
            if (board[x][y] == 0) {
                // Calculate the score for the move
                int score = evaluateMove(board, x, y, moves);

                // If the score is better than the best score, update the best move
                if (score > maxScore) {
                    maxScore = score;
                    moveX = x;
                    moveY = y;
                }
            }
        }
    }

    // Return the best move
    return moveX;
}

int evaluateMove(int** board, int x, int y, Node* moves) {
    // Calculate the number of moves the player has won
    int numWins = checkWin(board, moves);

    // Calculate the number of moves the player has lost
    int numLosses = checkWin(board, moves) ^ 1;

    // Calculate the number of moves that are still available
    int numAvailable = BOARD_SIZE * BOARD_SIZE - numWins - numLosses;

    // Return the move value
    return numWins - numLosses + numAvailable;
}

int main() {
    playTicTacToe();
    return 0;
}