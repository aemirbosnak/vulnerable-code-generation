//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    struct node* next;
} node_t;

typedef struct {
    node_t* front;
    node_t* rear;
} queue_t;

void init_queue(queue_t* q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(queue_t* q) {
    return q->front == NULL;
}

int is_full(queue_t* q) {
    node_t* temp = q->front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count == MAX_QUEUE_SIZE;
}

void enqueue(queue_t* q, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue_t* q) {
    int data = -1;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return data;
    }
    node_t* temp = q->front;
    data = temp->data;
    q->front = temp->next;
    free(temp);
    return data;
}

void display(queue_t* q) {
    node_t* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue_t q;
    init_queue(&q);
    int choice, data;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data!= -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}