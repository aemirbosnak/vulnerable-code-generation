//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

// Node structure
struct node {
    int data;
    struct node *next;
};

// Queue structure
struct queue {
    struct node *front;
    struct node *rear;
};

// Function prototypes
void enqueue(struct queue *, int);
int dequeue(struct queue *);
int is_empty(struct queue *);
int is_full(struct queue *);
void display(struct queue *);

// Driver program
int main() {
    struct queue q;
    q.front = q.rear = NULL;

    int choice, data;

    do {
        printf("\n\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;

            case 2:
                data = dequeue(&q);
                if (data!= -1)
                    printf("\nDequeued data: %d\n", data);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    } while (TRUE);

    return 0;
}

// Function to add an element to the queue
void enqueue(struct queue *q, int data) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("\nQueue overflow!\n");
        exit(0);
    }

    newnode->data = data;
    newnode->next = NULL;

    if (q->front == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

// Function to remove an element from the queue
int dequeue(struct queue *q) {
    int data;
    struct node *temp = q->front;

    if (q->front == NULL)
        return -1;

    data = q->front->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return data;
}

// Function to check if the queue is empty
int is_empty(struct queue *q) {
    if (q->front == NULL)
        return TRUE;
    else
        return FALSE;
}

// Function to check if the queue is full
int is_full(struct queue *q) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));

    if (temp == NULL)
        return TRUE;
    else {
        free(temp);
        return FALSE;
    }
}

// Function to display the elements in the queue
void display(struct queue *q) {
    struct node *temp = q->front;

    if (is_empty(q))
        printf("\nQueue is empty!\n");
    else {
        printf("\nElements in the queue are:\n");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}