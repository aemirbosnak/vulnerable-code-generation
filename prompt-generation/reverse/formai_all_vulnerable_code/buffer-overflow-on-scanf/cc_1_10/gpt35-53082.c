//FormAI DATASET v1.0 Category: Queue ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // maximum size of queue

typedef struct Queue {
   int front; // front index of queue
   int rear; // rear index of queue
   int elements[MAX_QUEUE_SIZE]; // store the queue elements
} Queue;

void enqueue(Queue *q, int item) {
    if(q -> rear == MAX_QUEUE_SIZE-1) {
        printf("Queue is full. Cannot add more elements.\n");
        return;
    }

    if(q -> front == -1 && q -> rear == -1) { // check if queue is empty
        q -> front = q -> rear = 0;
        q -> elements[0] = item;
    } else {
        q -> rear++;
        q -> elements[q -> rear] = item;
    }
}

int dequeue(Queue *q) {
    int item;
    if(q -> front == -1 || q -> front > q -> rear) { // check if queue is empty
        printf("Queue is empty. Cannot remove elements.\n");
        return -1;
    }

    item = q -> elements[q -> front];
    q -> front++;

    return item;
}

void display(Queue *q) {
    int i;
    if(q -> front == -1 || q -> front > q -> rear) { // check if queue is empty
        printf("Queue is empty. There is nothing to display.\n");
        return;
    }

    printf("Queue elements: ");
    for(i = q -> front; i <= q -> rear; i++) {
        printf("%d ", q -> elements[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    printf("Welcome to the unique C Queue example program!\n");
    printf("In this program, you can add and remove elements from the queue.\n");
    printf("You can also display the current elements in the queue.\n");

    int choice;
    int item;

    do {
        printf("Enter 1 to add an element to the queue.\n");
        printf("Enter 2 to remove an element from the queue.\n");
        printf("Enter 3 to display the current elements in the queue.\n");
        printf("Enter 4 to exit.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element you want to add to the queue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if(item != -1) {
                    printf("Element removed from the queue: %d\n", item);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Thank you for using the unique C Queue example program!\n");
                break;
            default:
                printf("Invalid input. Please enter a valid option.\n");
        }
    } while(choice != 4);

    return 0;
}