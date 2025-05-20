//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void playTicTacToe() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Create a linked list to store the moves
    Node* moves = NULL;

    // Player X goes first
    int currentPlayer = PLAYER_X;

    // Game loop
    while (!isGameOver(board) && movesCount(moves) < BOARD_SIZE * BOARD_SIZE) {
        // Get the move from the player
        int move = getMove();

        // Check if the move is valid
        if (!isValidMove(board, move)) {
            // Invalid move, prompt the player to try again
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        board[move / BOARD_SIZE][move % BOARD_SIZE] = currentPlayer;

        // Insert the move into the linked list
        insertAtTail(moves, move);

        // Switch to the next player
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Game over, print the winner
    if (isGameOver(board)) {
        printf("Congratulations! Player %d won!\n", currentPlayer);
    } else {
        printf("It's a draw.\n");
    }
}

int isGameOver(int** board) {
    // Check for rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
            return 1;
        }
    }

    // Check for columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0) {
            return 1;
        }
    }

    // Check for diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
        return 1;
    }

    // No winner, game is still on
    return 0;
}

int movesCount(Node* moves) {
    int count = 0;

    while (moves) {
        count++;
        moves = moves->next;
    }

    return count;
}

int getMove() {
    int move;

    // Get the move from the player
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    return move;
}

int isValidMove(int** board, int move) {
    // Check if the move is within the bounds of the board
    if (move < 1 || move > 9) {
        return 0;
    }

    // Check if the move has already been made
    if (board[move / BOARD_SIZE][move % BOARD_SIZE] != 0) {
        return 0;
    }

    // Move is valid
    return 1;
}

int main() {
    playTicTacToe();

    return 0;
}