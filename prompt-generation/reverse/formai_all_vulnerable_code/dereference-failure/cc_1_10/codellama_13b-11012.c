//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
/*
 * A unique C Queue Implementation example program in a Ken Thompson style
 * by Anonymous
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *value;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void enqueue(struct queue *q, char *value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = strdup(value);
    new_node->next = NULL;
    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

char *dequeue(struct queue *q) {
    if (q->head == NULL) {
        return NULL;
    }
    char *value = q->head->value;
    struct node *old_head = q->head;
    q->head = q->head->next;
    free(old_head);
    return value;
}

void print_queue(struct queue *q) {
    struct node *current = q->head;
    while (current != NULL) {
        printf("%s ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct queue q;
    q.head = NULL;
    q.tail = NULL;
    enqueue(&q, "A");
    enqueue(&q, "B");
    enqueue(&q, "C");
    print_queue(&q);
    char *value = dequeue(&q);
    printf("Dequeued: %s\n", value);
    print_queue(&q);
    return 0;
}