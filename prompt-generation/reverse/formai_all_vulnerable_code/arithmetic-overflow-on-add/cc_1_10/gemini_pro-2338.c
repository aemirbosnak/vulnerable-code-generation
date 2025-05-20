//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: invasive
// C program to implement a queue using two stacks

#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// A structure to represent a queue
struct Queue {
    struct Stack *stack1;
    struct Stack *stack2;
};

// Function to create a stack of given capacity. It initializes size of
// the stack, top and array of given size. The array is allocated in
// dynamic memory using malloc()
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to create a queue of given capacity. It initializes size
// of queue, two stacks
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to push an item to stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to enqueue an item to queue
void enqueue(struct Queue* queue, int item) {
    push(queue->stack1, item);
}

// Function to dequeue an item from queue
int dequeue(struct Queue* queue) {
    int item;
    if (queue->stack1->top == -1) {
        printf("Queue is empty");
        return -1;
    }
    // Move all elements from stack1 to stack2
    while (queue->stack1->top != -1) {
        item = pop(queue->stack1);
        push(queue->stack2, item);
    }
    // Pop the element from stack2
    item = pop(queue->stack2);
    // Push everything back to stack1
    while (queue->stack2->top != -1) {
        item = pop(queue->stack2);
        push(queue->stack1, item);
    }
    return item;
}

// Driver program to test an example of queue
int main() {
    struct Queue* queue = createQueue(10);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    return 0;
}