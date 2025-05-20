//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the structure of each node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Initialize an empty queue
void init(Node** front, Node** rear) {
    *front = NULL;
    *rear = NULL;
}

// Check if the queue is empty
int is_empty(Node* front, Node* rear) {
    return (front == NULL && rear == NULL);
}

// Add an element to the rear of the queue
void enqueue(Node** front, Node** rear, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(*front, *rear)) {
        *front = new_node;
        *rear = new_node;
    } else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

// Remove an element from the front of the queue
int dequeue(Node** front, Node** rear) {
    int data = -1;

    if (!is_empty(*front, *rear)) {
        Node* temp = *front;
        data = temp->data;
        *front = temp->next;

        if (*front == NULL) {
            *rear = NULL;
        }

        free(temp);
    }

    return data;
}

// Display the elements in the queue
void display(Node* front) {
    printf("Queue: ");

    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }

    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    init(&front, &rear);

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);

    display(front);

    dequeue(&front, &rear);

    display(front);

    dequeue(&front, &rear);

    display(front);

    dequeue(&front, &rear);

    display(front);

    return 0;
}