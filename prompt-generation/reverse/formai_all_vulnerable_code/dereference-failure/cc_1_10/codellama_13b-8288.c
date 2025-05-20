//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: genius
/*
 * C Data structures visualization example program
 * in a genius style
 */
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node *next;
};

// Queue structure
struct queue {
    struct node *front;
    struct node *rear;
};

// Stack structure
struct stack {
    struct node *top;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
struct queue* newQueue() {
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}

// Function to create a new stack
struct stack* newStack() {
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->top = NULL;
    return temp;
}

// Function to add an element to the queue
void enqueue(struct queue* queue, int data) {
    struct node* temp = newNode(data);
    if (queue->rear == NULL) {
        queue->front = temp;
        queue->rear = temp;
    } else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

// Function to remove an element from the queue
int dequeue(struct queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

// Function to add an element to the stack
void push(struct stack* stack, int data) {
    struct node* temp = newNode(data);
    temp->next = stack->top;
    stack->top = temp;
}

// Function to remove an element from the stack
int pop(struct stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to display the queue
void displayQueue(struct queue* queue) {
    struct node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display the stack
void displayStack(struct stack* stack) {
    struct node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct queue* queue = newQueue();
    struct stack* stack = newStack();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    displayQueue(queue);
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    displayStack(stack);
    pop(stack);
    pop(stack);
    displayStack(stack);
    return 0;
}