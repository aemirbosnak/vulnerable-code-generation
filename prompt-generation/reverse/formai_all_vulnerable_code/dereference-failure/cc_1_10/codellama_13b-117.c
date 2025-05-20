//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: complete
/*
 * Unique C Data structures visualization example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

// Linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Linked list
typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

// Stack node
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

// Stack
typedef struct {
    StackNode *top;
} Stack;

// Queue node
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// Queue
typedef struct {
    QueueNode *head;
    QueueNode *tail;
} Queue;

// Main function
int main() {
    // Initialize linked list
    LinkedList linkedList = {NULL, NULL};

    // Initialize stack
    Stack stack = {NULL};

    // Initialize queue
    Queue queue = {NULL, NULL};

    // Insert elements in linked list
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        Node *node = malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        if (linkedList.head == NULL) {
            linkedList.head = node;
            linkedList.tail = node;
        } else {
            linkedList.tail->next = node;
            linkedList.tail = node;
        }
    }

    // Insert elements in stack
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        StackNode *node = malloc(sizeof(StackNode));
        node->data = i;
        node->next = stack.top;
        stack.top = node;
    }

    // Insert elements in queue
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        QueueNode *node = malloc(sizeof(QueueNode));
        node->data = i;
        node->next = NULL;
        if (queue.head == NULL) {
            queue.head = node;
            queue.tail = node;
        } else {
            queue.tail->next = node;
            queue.tail = node;
        }
    }

    // Print linked list
    printf("Linked List: ");
    Node *node = linkedList.head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");

    // Print stack
    printf("Stack: ");
    StackNode *stackNode = stack.top;
    while (stackNode != NULL) {
        printf("%d ", stackNode->data);
        stackNode = stackNode->next;
    }
    printf("\n");

    // Print queue
    printf("Queue: ");
    QueueNode *queueNode = queue.head;
    while (queueNode != NULL) {
        printf("%d ", queueNode->data);
        queueNode = queueNode->next;
    }
    printf("\n");

    return 0;
}