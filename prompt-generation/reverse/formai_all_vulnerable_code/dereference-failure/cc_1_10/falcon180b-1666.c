//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
    struct node_t *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
} queue_t;

void enqueue(queue_t *q, double x) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = x;
    new_node->next = NULL;

    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

double dequeue(queue_t *q) {
    if (q->head == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    double x = q->head->value;
    node_t *temp_node = q->head;
    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp_node);

    return x;
}

int is_empty(queue_t *q) {
    return (q->head == NULL);
}

void print_queue(queue_t *q) {
    node_t *temp_node = q->head;

    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp_node!= NULL) {
        printf("%lf ", temp_node->value);
        temp_node = temp_node->next;
    }

    printf("\n");
}

int main() {
    queue_t q;
    q.head = NULL;
    q.tail = NULL;

    enqueue(&q, 2.5);
    enqueue(&q, 4.7);
    enqueue(&q, 6.9);

    print_queue(&q);

    double x = dequeue(&q);
    printf("Dequeued element is: %lf\n", x);

    print_queue(&q);

    x = dequeue(&q);
    printf("Dequeued element is: %lf\n", x);

    print_queue(&q);

    x = dequeue(&q);
    printf("Dequeued element is: %lf\n", x);

    print_queue(&q);

    return 0;
}