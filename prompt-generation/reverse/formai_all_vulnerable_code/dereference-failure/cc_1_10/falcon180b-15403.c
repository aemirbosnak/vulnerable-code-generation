//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // maximum size of the queue

// node structure for the linked list implementation of the queue
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL; // initialize front and rear pointers to NULL

// function to check if the queue is empty
int is_empty() {
    return front == NULL;
}

// function to check if the queue is full
int is_full() {
    return rear == (Node *)malloc(sizeof(Node));
}

// function to enqueue an element
void enqueue(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node)); // create a new node
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty()) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

// function to dequeue an element
int dequeue() {
    if (is_empty()) {
        printf("Queue is empty.\n");
        return -1;
    }

    int data = front->data;
    Node *temp = front;
    front = front->next;
    free(temp);

    if (is_empty())
        rear = NULL;

    return data;
}

// function to display the elements in the queue
void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    Node *temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// main function to test the queue implementation
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    int data = dequeue();
    printf("Dequeued element: %d\n", data);

    display();

    data = dequeue();
    printf("Dequeued element: %d\n", data);

    display();

    data = dequeue();
    printf("Dequeued element: %d\n", data);

    display();

    data = dequeue();
    printf("Dequeued element: %d\n", data);

    display();

    data = dequeue();
    printf("Dequeued element: %d\n", data);

    return 0;
}