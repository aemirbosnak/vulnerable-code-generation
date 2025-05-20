//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: mathematical
// Program to visualize data structures in a mathematical style

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct node {
    int data;
    struct node *next;
};

// Define a structure for a linked list
struct linked_list {
    struct node *head;
    struct node *tail;
    int size;
};

// Define a structure for a stack
struct stack {
    struct linked_list *list;
    int top;
};

// Define a structure for a queue
struct queue {
    struct linked_list *list;
    int front;
    int rear;
};

// Function to initialize a linked list
void init_linked_list(struct linked_list *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Function to insert a node at the beginning of a linked list
void insert_beginning(struct linked_list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

// Function to insert a node at the end of a linked list
void insert_end(struct linked_list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Function to print a linked list
void print_linked_list(struct linked_list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to initialize a stack
void init_stack(struct stack *stack) {
    stack->list = malloc(sizeof(struct linked_list));
    init_linked_list(stack->list);
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct stack *stack, int data) {
    insert_beginning(stack->list, data);
    stack->top++;
}

// Function to pop an element from the stack
int pop(struct stack *stack) {
    if (stack->top == -1) {
        return -1;
    }
    int data = stack->list->head->data;
    struct node *current = stack->list->head;
    stack->list->head = current->next;
    free(current);
    stack->top--;
    return data;
}

// Function to initialize a queue
void init_queue(struct queue *queue) {
    queue->list = malloc(sizeof(struct linked_list));
    init_linked_list(queue->list);
    queue->front = 0;
    queue->rear = 0;
}

// Function to enqueue an element into the queue
void enqueue(struct queue *queue, int data) {
    insert_end(queue->list, data);
    queue->rear++;
}

// Function to dequeue an element from the queue
int dequeue(struct queue *queue) {
    if (queue->front == queue->rear) {
        return -1;
    }
    int data = queue->list->head->data;
    struct node *current = queue->list->head;
    queue->list->head = current->next;
    free(current);
    queue->front++;
    return data;
}

int main() {
    // Initialize a linked list
    struct linked_list list;
    init_linked_list(&list);

    // Insert elements into the linked list
    insert_beginning(&list, 1);
    insert_end(&list, 2);
    insert_end(&list, 3);

    // Print the linked list
    print_linked_list(&list);

    // Initialize a stack
    struct stack stack;
    init_stack(&stack);

    // Push elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // Pop elements from the stack
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    // Initialize a queue
    struct queue queue;
    init_queue(&queue);

    // Enqueue elements into the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    // Dequeue elements from the queue
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    return 0;
}