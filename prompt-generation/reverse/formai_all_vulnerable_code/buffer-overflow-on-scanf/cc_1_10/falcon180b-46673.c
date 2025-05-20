//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front, rear;
    int size;
} Queue;

void init(Queue *q, int s) {
    q->arr = (int *)malloc(s * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = s;
}

int isEmpty(Queue *q) {
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(Queue *q) {
    if ((q->rear + 1) % q->size == q->front)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int x) {
    if (isFull(q))
        printf("Queue is Full\n");
    else if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->arr[q->rear] = x;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = x;
    }
}

int dequeue(Queue *q) {
    int x;
    if (isEmpty(q))
        printf("Queue is Empty\n");
    else if (q->front == q->rear) {
        x = q->arr[q->front];
        q->front = q->rear = -1;
    } else {
        x = q->arr[q->front];
        q->front = (q->front + 1) % q->size;
    }
    return x;
}

void display(Queue *q) {
    int i;
    if (isEmpty(q))
        printf("Queue is Empty\n");
    else {
        printf("Elements in the Queue are: ");
        for (i = q->front; i <= q->rear; i = (i + 1) % q->size)
            printf("%d ", q->arr[i]);
    }
}

int main() {
    Queue q;
    int ch, x;

    init(&q, 5);

    do {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            enqueue(&q, x);
            break;

        case 2:
            x = dequeue(&q);
            if (x!= -1)
                printf("The element removed is %d\n", x);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}