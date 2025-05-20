//FormAI DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//Queue structure
typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

//Function to add element to queue
void enqueue(Queue *q, int val) {
    if(q->rear == MAX_SIZE - 1) {
        printf("Queue is full, cannot add element.\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
    if(q->front == -1) {
        q->front++;
    }
}

//Function to remove element from queue
int dequeue(Queue *q) {
    if(q->front == -1 || q->front > q->rear) {
        printf("Queue is empty, cannot remove element.\n");
        return -1;
    }
    int val = q->arr[q->front];
    q->front++;
    return val;
}

//Function to display queue elements
void display(Queue q) {
    if(q.front == -1 || q.front > q.rear) {
        printf("Queue is empty.\n");
        return;
    }
    int i;
    printf("Queue elements: ");
    for(i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

//Main function to test queue implementation
int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    int n, val, ch;
    do {
        printf("Enter 1 to enqueue element\n");
        printf("Enter 2 to dequeue element\n");
        printf("Enter 3 to display elements\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter element to be enqueued: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if(val != -1) {
                    printf("Removed element: %d\n", val);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(1);
    return 0;
}