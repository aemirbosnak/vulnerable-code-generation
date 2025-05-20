//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
    #include <stdlib.h>

    typedef struct node {
        int value;
        struct node* next;
    } node;

    typedef struct {
        node* head;
        node* tail;
    } queue;

    queue* create_queue() {
        queue* q = malloc(sizeof(queue));
        q->head = NULL;
        q->tail = NULL;
        return q;
    }

    void enqueue(queue* q, int value) {
        node* n = malloc(sizeof(node));
        n->value = value;
        n->next = NULL;
        if (q->head == NULL) {
            q->head = n;
            q->tail = n;
        } else {
            q->tail->next = n;
            q->tail = n;
        }
    }

    int dequeue(queue* q) {
        if (q->head == NULL) {
            return -1;
        }
        int value = q->head->value;
        node* n = q->head;
        q->head = q->head->next;
        free(n);
        return value;
    }

    int main() {
        queue* q = create_queue();
        enqueue(q, 1);
        enqueue(q, 2);
        enqueue(q, 3);
        int value = dequeue(q);
        printf("Dequeued value: %d\n", value);
        value = dequeue(q);
        printf("Dequeued value: %d\n", value);
        value = dequeue(q);
        printf("Dequeued value: %d\n", value);
        return 0;
    }