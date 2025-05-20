//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
// Visualize Data Structures in C

#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

// Linked List
struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

// Stack
struct Stack {
    struct LinkedList *list;
};

// Queue
struct Queue {
    struct LinkedList *list;
};

// Function to create a new Linked List
struct LinkedList *createList() {
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to create a new Node
struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to push data onto a Stack
void push(struct Stack *stack, int data) {
    struct LinkedList *list = stack->list;
    struct Node *node = createNode(data);
    node->next = list->head;
    list->head = node;
}

// Function to pop data from a Stack
int pop(struct Stack *stack) {
    struct LinkedList *list = stack->list;
    struct Node *node = list->head;
    int data = node->data;
    list->head = node->next;
    free(node);
    return data;
}

// Function to enqueue data into a Queue
void enqueue(struct Queue *queue, int data) {
    struct LinkedList *list = queue->list;
    struct Node *node = createNode(data);
    node->next = list->tail;
    list->tail = node;
}

// Function to dequeue data from a Queue
int dequeue(struct Queue *queue) {
    struct LinkedList *list = queue->list;
    struct Node *node = list->head;
    int data = node->data;
    list->head = node->next;
    free(node);
    return data;
}

int main() {
    // Create a Stack
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->list = createList();

    // Create a Queue
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->list = createList();

    // Push data onto the Stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // Pop data from the Stack
    int data = pop(stack);
    printf("Popped data: %d\n", data);

    // Enqueue data into the Queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Dequeue data from the Queue
    data = dequeue(queue);
    printf("Dequeued data: %d\n", data);

    return 0;
}