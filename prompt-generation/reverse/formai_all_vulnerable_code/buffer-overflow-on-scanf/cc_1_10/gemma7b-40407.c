//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT -1

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

int main() {
    time_t start, end;
    start = time(NULL);

    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                                {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                                {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT}};

    int player = 1;
    int moveMade = 0;

    Node* movesMadeList = NULL;

    while (!moveMade) {
        int moveX, moveY;

        // Get the move from the player
        printf("Enter move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Check if the move is valid
        if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the spot is empty
        if (board[moveX][moveY] != EMPTY_SPOT) {
            printf("That spot is already taken.\n");
            continue;
        }

        // Make the move
        board[moveX][moveY] = player;

        // Add the move to the list
        movesMadeList = createNode(moveX, moveY);

        // Check if the player has won
        if (checkWin(board, player) || moveMade == BOARD_SIZE * BOARD_SIZE - 1) {
            moveMade = 1;
        }

        // Switch to the next player
        player = (player == 1) ? 2 : 1;
    }

    end = time(NULL);
    printf("Time taken: %.2f seconds\n", (double)(end - start));

    return 0;
}

int checkWin(int** board, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}