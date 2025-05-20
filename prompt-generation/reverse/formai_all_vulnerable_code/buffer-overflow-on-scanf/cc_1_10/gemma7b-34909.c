//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

int main() {
    // Create the tic tac toe board
    Node* board = newNode(0, 0);
    board->next = newNode(1, 0);
    board->next->next = newNode(2, 0);
    board->next->next->next = newNode(0, 1);
    board->next->next->next->next = newNode(1, 1);
    board->next->next->next->next->next = newNode(2, 1);
    board->next->next->next->next->next->next = newNode(0, 2);
    board->next->next->next->next->next->next->next = newNode(1, 2);
    board->next->next->next->next->next->next->next->next = newNode(2, 2);

    // Game loop
    int player = 1;
    while (!board->next->next->next) {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Check if the move is valid
        if (move_x < 0 || move_x >= BOARD_SIZE || move_y < 0 || move_y >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Place the player's mark on the board
        Node* move = newNode(move_x, move_y);
        move->next = board->next;
        board = move;

        // Switch players
        player = (player == 1) ? 2 : 1;
    }

    // Game over
    printf("Game over! The winner is: ");
    if (player == 1) {
        printf("Player 1\n");
    } else {
        printf("Player 2\n");
    }

    return 0;
}