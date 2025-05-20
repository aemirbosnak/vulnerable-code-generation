//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: accurate
/*
 * A unique C Queue Implementation example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void enqueue(struct queue *q, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(struct queue *q) {
    if (q->head == NULL) {
        return -1;
    }

    struct node *temp = q->head;
    int data = temp->data;
    q->head = temp->next;
    free(temp);

    if (q->head == NULL) {
        q->tail = NULL;
    }

    return data;
}

bool is_empty(struct queue *q) {
    return q->head == NULL;
}

int main() {
    struct queue q;
    q.head = q.tail = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    int data = dequeue(&q);
    printf("%d\n", data);

    data = dequeue(&q);
    printf("%d\n", data);

    data = dequeue(&q);
    printf("%d\n", data);

    if (is_empty(&q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    return 0;
}