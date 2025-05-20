//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
    }
}

int main() {
    Node* head = NULL;

    // Insert data into the linked list
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    // Play the memory game
    int guessNumber;
    printf("Enter a number: ");
    scanf("%d", &guessNumber);

    Node* current = head;
    while (current) {
        if (current->data == guessNumber) {
            printf("Congratulations! You found the number.\n");
            break;
        } else if (current->next == NULL) {
            printf("Sorry, the number is not found.\n");
            break;
        }
        current = current->next;
    }

    return 0;
}