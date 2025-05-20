//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
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
    Node* head = NULL;
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int move = 0;

    // Game loop
    while (move < 9) {
        // Get the player's move
        int row, column;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &row, &column);

        // Validate the move
        if (board[row][column] != 0) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        board[row][column] = player;

        // Check if the player has won
        if (checkWin(board, player) == 1) {
            printf("Congratulations! You have won!\n");
            break;
        }

        // If the board is full, it's a draw
        if (move == 9) {
            printf("It's a draw!\n");
            break;
        }

        // Switch to the next player
        player = (player == 1) ? 2 : 1;

        // Increment the move counter
        move++;
    }

    // Free the memory allocated for the linked list
    free(head);
}

int checkWin(int** board, int player) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // If there has not been a win, return 0
    return 0;
}

int main() {
    playTicTacToe();

    return 0;
}