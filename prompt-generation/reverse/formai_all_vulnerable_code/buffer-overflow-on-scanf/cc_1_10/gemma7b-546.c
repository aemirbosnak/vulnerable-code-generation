//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void playTicTacToe() {
    Node* head = newNode(0, 0);
    head->next = newNode(1, 0);
    head->next->next = newNode(2, 0);

    head->next->next->next = newNode(0, 1);
    head->next->next->next->next = newNode(1, 1);
    head->next->next->next->next->next = newNode(2, 1);

    head->next->next->next->next->next->next = newNode(0, 2);
    head->next->next->next->next->next->next->next = newNode(1, 2);
    head->next->next->next->next->next->next->next = newNode(2, 2);

    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

    int player = 1;
    int moveMade = 0;

    while (!moveMade) {
        int x, y;

        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        if (board[x][y] != 0) {
            printf("That move is already made.\n");
            continue;
        }

        board[x][y] = player;
        moveMade = 1;
    }

    // Check if the player won
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            printf("You won!\n");
            return;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            printf("You won!\n");
            return;
        }
    }

    // If all moves have been made and no one won, it's a draw
    printf("Draw!\n");
}

int main() {
    playTicTacToe();

    return 0;
}