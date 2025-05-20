//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int queue_size = 0;

// Function to add an element to the queue
void enqueue(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue_size == 0) {
        front = new_node;
        rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }

    queue_size++;
}

// Function to remove an element from the queue
int dequeue() {
    if (queue_size == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = front->data;
    Node* temp = front;
    front = front->next;
    free(temp);

    queue_size--;
    return data;
}

// Function to display the queue
void display() {
    if (queue_size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    Node* temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    int removed_element = dequeue();
    printf("Removed element: %d\n", removed_element);

    display();

    return 0;
}