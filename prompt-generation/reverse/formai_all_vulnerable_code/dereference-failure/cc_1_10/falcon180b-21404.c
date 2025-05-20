//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation using an array
typedef struct stack {
    int top;
    char data[MAX_SIZE];
} Stack;

// Queue implementation using an array
typedef struct queue {
    int front;
    int rear;
    char data[MAX_SIZE];
} Queue;

// Linked List implementation
typedef struct node {
    char data;
    struct node* next;
} Node;

// Stack operations
void push(Stack* s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(0);
    }
    s->data[++s->top] = value;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(0);
    }
    return s->data[s->top--];
}

// Queue operations
void enqueue(Queue* q, char value) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("Queue overflow\n");
        exit(0);
    }
    q->data[++q->rear] = value;
}

char dequeue(Queue* q) {
    if (q->front == -1 || q->rear == -1) {
        printf("Queue underflow\n");
        exit(0);
    }
    return q->data[q->front++];
}

// Linked List operations
void addNode(Node** head, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack s;
    Queue q;
    Node* head = NULL;

    // Stack operations
    push(&s, 'a');
    push(&s, 'b');
    push(&s, 'c');
    printf("Stack elements: ");
    while (s.top >= 0) {
        printf("%c ", pop(&s));
    }
    printf("\n");

    // Queue operations
    enqueue(&q, 'd');
    enqueue(&q, 'e');
    enqueue(&q, 'f');
    printf("Queue elements: ");
    while (q.front <= q.rear) {
        printf("%c ", dequeue(&q));
    }
    printf("\n");

    // Linked List operations
    addNode(&head, 'g');
    addNode(&head, 'h');
    addNode(&head, 'i');
    printf("Linked List elements: ");
    printList(head);

    return 0;
}