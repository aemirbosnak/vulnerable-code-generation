//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
    int move;
    struct Node* next;
} Node;

void makeMove(Node* node) {
    printf("Move: %d\n", node->move);
}

int main() {
    Node* head = NULL;
    int move = 0;

    // Loop to get moves from the user
    while (1) {
        printf("Enter move: ");
        scanf("%d", &move);

        // Create a new node
        Node* newNode = malloc(sizeof(Node));
        newNode->move = move;
        newNode->next = NULL;

        // Add the new node to the head
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        // Make the move
        makeMove(newNode);

        // Check if the user wants to continue
        printf("Continue? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        // Break out of the loop if the user does not want to continue
        if (answer == 'N') {
            break;
        }
    }

    return 0;
}