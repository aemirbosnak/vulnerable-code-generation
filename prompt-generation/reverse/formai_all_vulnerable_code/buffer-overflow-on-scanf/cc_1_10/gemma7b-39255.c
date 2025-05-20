//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void printBoard(Node* head) {
    for (Node* current = head; current; current = current->next) {
        printf("%c ", current->x + 'a' - 'a' + 1);
        printf("%c ", current->y + 1);
        printf("  ");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Node* board = newNode(MAX_BOARD_SIZE - 1, MAX_BOARD_SIZE - 1);

    // Place the AI's first move randomly
    int x = rand() % MAX_BOARD_SIZE;
    int y = rand() % MAX_BOARD_SIZE;
    newNode(x, y);

    // Loop until the player wins or the board is full
    while (!board->next) {
        // Get the player's move
        int moveX = 0;
        int moveY = 0;
        printf("Enter move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Validate the move
        if (moveX < 1 || moveX > MAX_BOARD_SIZE || moveY < 1 || moveY > MAX_BOARD_SIZE) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the player's move
        newNode(moveX - 1, moveY - 1);
    }

    // Print the final board
    printBoard(board);

    // Declare the winner
    printf("Winner: %c", board->x + 'a' - 'a' + 1);

    return 0;
}