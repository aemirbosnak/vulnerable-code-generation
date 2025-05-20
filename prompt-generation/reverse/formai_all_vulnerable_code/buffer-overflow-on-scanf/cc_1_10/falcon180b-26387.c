//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node *next;
} node;

typedef struct {
    node *front;
    node *rear;
} queue;

queue *createQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(queue *q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

int isFull(queue *q) {
    node *temp = (node *)malloc(sizeof(node));
    if (!temp) {
        printf("Memory error\n");
        exit(0);
    }
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        temp->next = NULL;
        return 0;
    } else {
        free(temp);
        return 1;
    }
}

void enqueue(queue *q, int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory error\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(queue *q) {
    if (isEmpty(q))
        return -1;
    int data = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

void display(queue *q) {
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        node *temp = q->front;
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    queue *q = createQueue();
    int choice, data;

    do {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;

        case 2:
            data = dequeue(q);
            if (data!= -1)
                printf("\nDequeued data is %d", data);
            break;

        case 3:
            display(q);
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    } while (1);

    return 0;
}