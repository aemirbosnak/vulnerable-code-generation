//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
    int move;
    struct Node* next;
} Node;

void makeMove(Node* head, int move) {
    Node* newNode = malloc(sizeof(Node));
    newNode->move = move;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void playChess(int player) {
    Node* head = NULL;
    char board[MAX_BOARD_SIZE] = {0};

    // Make your move
    int move = 0;
    printf("Enter your move (e.g. e4, Nf3): ");
    scanf("%d", &move);

    // Validate the move
    if (move < 1 || move > MAX_BOARD_SIZE) {
        printf("Invalid move.\n");
        return;
    }

    // Make the move
    makeMove(head, move);

    // Print the board
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        printf("%c ", board[i]);
    }

    // Play again
    if (player == 1) {
        playChess(2);
    } else {
        printf("Game over.\n");
    }
}

int main() {
    playChess(1);

    return 0;
}