//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void enqueue(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

int dequeue(Node** head)
{
    if (*head == NULL)
    {
        return -1;
    }

    int data = (*head)->data;
    *head = (*head)->next;
    return data;
}

int main()
{
    Node* head = NULL;

    // Multiplayer game logic
    while (1)
    {
        // Player 1 enqueues
        printf("Player 1, enter your data: ");
        int data1 = atoi(gets(NULL));
        enqueue(&head, data1);

        // Player 2 enqueues
        printf("Player 2, enter your data: ");
        int data2 = atoi(gets(NULL));
        enqueue(&head, data2);

        // Player 1 dequeues
        printf("Player 1, your data is: %d\n", dequeue(&head));

        // Player 2 dequeues
        printf("Player 2, your data is: %d\n", dequeue(&head));

        // Check if game ends
        if (dequeue(&head) == -1)
        {
            break;
        }
    }

    return 0;
}