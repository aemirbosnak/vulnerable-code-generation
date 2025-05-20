//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include<stdio.h>

#define MAXSIZE 100

// Creating a structure for Stack
typedef struct {
    int data[MAXSIZE];
    int top;
} Stack;

// Creating a structure for Queue
typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
} Queue;

// Function to initialize Stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if Stack is empty
int isEmptyStack(Stack *s) {
    if(s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to check if Stack is full
int isFullStack(Stack *s) {
    if(s->top == MAXSIZE-1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to push element onto Stack
void pushStack(Stack *s, int elem) {
    if(isFullStack(s)) {
        printf("Stack is full!\n");
    }
    else {
        s->top++;
        s->data[s->top] = elem;
    }
}

// Function to pop element from Stack
int popStack(Stack *s) {
    int elem;
    if(isEmptyStack(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    else {
        elem = s->data[s->top];
        s->top--;
        return elem;
    }
}

// Function to display contents of Stack
void displayStack(Stack *s) {
    if(isEmptyStack(s)) {
        printf("Stack is empty!\n");
    }
    else {
        int i;
        printf("Stack contents: ");
        for(i=s->top;i>=0;i--) {
            printf("%d ",s->data[i]);
        }
        printf("\n");
    }
}

// Function to initialize Queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Function to check if Queue is empty
int isEmptyQueue(Queue *q) {
    if(q->rear < q->front) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to check if Queue is full
int isFullQueue(Queue *q) {
    if(q->rear == MAXSIZE-1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to add element to Queue
void enqueue(Queue *q, int elem) {
    if(isFullQueue(q)) {
        printf("Queue is full!\n");
    }
    else {
        q->rear++;
        q->data[q->rear] = elem;
    }
}

// Function to remove element from Queue
int dequeue(Queue *q) {
    int elem;
    if(isEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        elem = q->data[q->front];
        q->front++;
        return elem;
    }
}

// Function to display contents of Queue
void displayQueue(Queue *q) {
    if(isEmptyQueue(q)) {
        printf("Queue is empty!\n");
    }
    else {
        int i;
        printf("Queue contents: ");
        for(i=q->front;i<=q->rear;i++) {
            printf("%d ",q->data[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice,elem;

    // Creating Stack and Queue objects
    Stack s;
    Queue q;
    // Initializing Stack and Queue
    initStack(&s);
    initQueue(&q);

    do {
        // Displaying menu
        printf("-----------------------------------\n");
        printf("1. Push element onto Stack.\n");
        printf("2. Pop element from Stack.\n");
        printf("3. Display Stack.\n");
        printf("4. Add element to Queue.\n");
        printf("5. Remove element from Queue.\n");
        printf("6. Display Queue.\n");
        printf("7. Exit.\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter element to push onto Stack: ");
                scanf("%d",&elem);
                pushStack(&s,elem);
                break;
            case 2:
                elem = popStack(&s);
                if(elem != -1) {
                    printf("Popped element: %d\n",elem);
                }
                break;
            case 3:
                displayStack(&s);
                break;
            case 4:
                printf("Enter element to add to Queue: ");
                scanf("%d",&elem);
                enqueue(&q,elem);
                break;
            case 5:
                elem = dequeue(&q);
                if(elem != -1) {
                    printf("Removed element: %d\n",elem);
                }
                break;
            case 6:
                displayQueue(&q);
                break;
            case 7:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 7);

    return 0;
}