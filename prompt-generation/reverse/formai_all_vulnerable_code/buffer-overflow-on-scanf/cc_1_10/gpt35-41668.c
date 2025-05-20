//FormAI DATASET v1.0 Category: Queue Implementation ; Style: funny
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10

//declaring the structure for our queue
typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} queue;

//function prototypes
queue * createQueue();
void enqueue(queue *q, int);
int dequeue(queue *q);
void display(queue *q);

//function to create an empty queue
queue * createQueue() {
    queue *q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//function to insert an element in the queue
void enqueue(queue *q, int value) {
    if(q->rear == MAX_QUEUE_SIZE-1) {
        printf("Sorry, the queue is already full!\n");
    } else {
        if(q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d was successfully added to the queue!\n", value);
    }
}

//function to remove an element from the queue
int dequeue(queue *q) {
    if(q->front == -1) {
        printf("Sorry, the queue is already empty!\n");
        return -1;
    } else {
        int value = q->items[q->front];
        q->front++;
        if(q->front > q->rear) {
            q->front = q->rear = -1;
        }
        printf("%d was successfully removed from the queue!\n", value);
        return value;
    }
}

//function to display all the elements in the queue
void display(queue *q) {
    if(q->rear == -1) {
        printf("Sorry, the queue is empty!\n");
    } else {
        printf("Queue elements are:\n");
        for(int i=q->front; i<=q->rear; i++) {
            printf("%d\n", q->items[i]);
        }
    }
}

//main function
int main() {
    printf("Welcome to the funny queue program!\n\n");
    queue *q = createQueue();
    int choice, value;
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display all elements\n");
        printf("4. Quit the program\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element you want to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Sad to see you go! Thanks for using our queue program!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}