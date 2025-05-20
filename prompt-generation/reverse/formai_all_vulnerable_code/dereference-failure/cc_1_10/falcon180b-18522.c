//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the queue
#define QUEUE_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

// Create an empty queue
Node* createQueue() {
    Node* queue = (Node*)malloc(sizeof(Node));
    if (queue == NULL) {
        printf("Error: Could not create queue\n");
        exit(1);
    }
    queue->next = NULL;
    return queue;
}

// Add an element to the end of the queue
void enqueue(Node* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Could not enqueue element\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->next == NULL) {
        queue->next = newNode;
    } else {
        Node* temp = queue->next;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d enqueued to the queue\n", data);
}

// Remove an element from the front of the queue
int dequeue(Node* queue) {
    if (queue->next == NULL) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    int data = queue->next->data;
    Node* temp = queue->next;
    queue->next = temp->next;
    free(temp);
    printf("%d dequeued from the queue\n", data);
    return data;
}

// Check if the queue is empty
bool isEmpty(Node* queue) {
    if (queue->next == NULL) {
        return true;
    } else {
        return false;
    }
}

// Display the elements in the queue
void display(Node* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->next;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    display(queue);
    return 0;
}