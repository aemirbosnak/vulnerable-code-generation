//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the rear of the queue
void enqueue(struct Node** frontRef, struct Node** rearRef, int data) {
    struct Node* newNode = createNode(data);
    if (*rearRef == NULL) {
        *frontRef = newNode;
        *rearRef = newNode;
    }
    else {
        (*rearRef)->next = newNode;
        *rearRef = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Node** frontRef, struct Node** rearRef) {
    struct Node* temp = *frontRef;
    int data = temp->data;
    if (*frontRef == *rearRef) {
        *frontRef = NULL;
        *rearRef = NULL;
    }
    else {
        *frontRef = temp->next;
    }
    free(temp);
    return data;
}

// Function to display the elements in the queue
void display(struct Node* front) {
    printf("Queue elements are: ");
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    display(front);
    printf("Dequeued element: %d\n", dequeue(&front, &rear));
    display(front);
    printf("Dequeued element: %d\n", dequeue(&front, &rear));
    display(front);
    printf("Dequeued element: %d\n", dequeue(&front, &rear));
    display(front);
    return 0;
}