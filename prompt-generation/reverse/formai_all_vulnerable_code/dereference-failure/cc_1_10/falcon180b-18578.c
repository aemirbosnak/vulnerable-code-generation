//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node *front, *rear;
};

void init(struct queue* q) {
    q->front = q->rear = NULL;
}

int is_empty(struct queue* q) {
    return q->front == NULL;
}

int is_full(struct queue* q) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    else {
        free(temp);
        return 0;
    }
}

void enqueue(struct queue* q, int data) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue Overflow\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct queue* q) {
    if (is_empty(q)) {
        printf("Queue Underflow\n");
        exit(0);
    }
    struct node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL)
        q->rear = NULL;
    return data;
}

void display(struct queue* q) {
    if (is_empty(q))
        printf("Queue is Empty\n");
    else {
        struct node* temp = q->front;
        printf("Queue is: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    return 0;
}