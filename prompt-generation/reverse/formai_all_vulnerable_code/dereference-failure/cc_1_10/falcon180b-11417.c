//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
typedef struct Node* Queue;

// Function to create an empty queue
Queue createQueue() {
    Queue q = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue q) {
    if (q == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*q == NULL)
        *q = newNode;
    else {
        struct Node* last = *q;
        while (last->next!= NULL)
            last = last->next;
        last->next = newNode;
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(*q))
        return -1;

    struct Node* temp = *q;
    *q = (*q)->next;
    int value = temp->data;
    free(temp);

    return value;
}

// Function to print the queue elements
void printQueue(Queue q) {
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        struct Node* current = q;
        while (current!= NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue q = createQueue();

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(q);

    int value = dequeue(&q);
    printf("Dequeued value: %d\n", value);

    printQueue(q);

    return 0;
}