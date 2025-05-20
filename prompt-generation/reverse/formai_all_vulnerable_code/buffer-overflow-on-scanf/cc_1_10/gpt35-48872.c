//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
/* A Romeo and Juliet inspired C Queue Implementation */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100 // maximum size of the queue

/* Defining the Queue */
typedef struct {
    int front; // front of the queue
    int rear; // rear of the queue
    int data[MAX_QUEUE_SIZE]; // data in the queue
} Queue;

/* Initializing the Queue */
void init_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

/* Checking if Queue is Empty */
bool is_empty(Queue *q) {
    if(q->front == -1 && q->rear == -1)
        return true;
    else
        return false;
}

/* Checking if Queue is Full */
bool is_full(Queue *q) {
    if(q->rear == MAX_QUEUE_SIZE-1)
        return true;
    else
        return false;
}

/* Adding an Element into Queue */
void enqueue(Queue *q, int x) {
    if(is_full(q)) {
        printf("Alas! My love, the queue is full!\n");
    } else if(is_empty(q)) {
        q->front = 0;
        q->rear = 0;
        q->data[q->rear] = x;
        printf("\'Tis a triumph! %d has been added to the queue.\n", x);
    } else {
        q->rear++;
        q->data[q->rear] = x;
        printf("\'Tis a triumph! %d has been added to the queue.\n", x);
    }
}

/* Removing an Element from Queue */
void dequeue(Queue *q) {
    if(is_empty(q)) {
        printf("I weep, for the queue is empty.\n");
    } else if(q->front == q->rear) {
        printf("\'Twas a joyous moment, for %d has been removed from the queue.\n", q->data[q->front]);
        q->front = -1;
        q->rear = -1;
    } else {
        printf("\'Twas a joyous moment, for %d has been removed from the queue.\n", q->data[q->front]);
        q->front++;
    }
}

/* Displaying the Queue */
void display(Queue *q) {
    if(is_empty(q)) {
        printf("Behold! The queue is empty.\n");
    } else {
        printf("The queue is as follows: ");
        for(int i=q->front; i<=q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    init_queue(&q);
    
    printf("O Romeo, O Romeo! Our queue lies empty here, screaming to be filled...\n");
    
    printf("\nEnter a command to add, remove, or display queue elements. To quit, type \'quit\'.\n");
    char cmd[10];
    while(scanf("%s", cmd) == 1) {
        if(cmd[0] == 'q' && cmd[1] == 'u' && cmd[2] == 'i' && cmd[3] == 't') {
            break;
        } else if(cmd[0] == 'a' && cmd[1] == 'd' && cmd[2] == 'd') {
            int x;
            printf("My heart sings at the thought of adding an element. What should it be, my love?\n");
            scanf("%d", &x);
            enqueue(&q, x);
        } else if(cmd[0] == 'r' && cmd[1] == 'e' && cmd[2] == 'm' && cmd[3] == 'o' && cmd[4] == 'v' && cmd[5] == 'e') {
            printf("Woe is me, we must remove an element from the queue. But who shall it be?\n");
            dequeue(&q);
        } else if(cmd[0] == 'd' && cmd[1] == 'i' && cmd[2] == 's' && cmd[3] == 'p' && cmd[4] == 'l' && cmd[5] == 'a' && cmd[6] == 'y') {
            display(&q);
        } else {
            printf("Alack! Type a valid command, my love.\n");
        }
    }
    
    printf("Farewell, my love. Let us embrace once more before we part.\n");
    
    return 0;
}