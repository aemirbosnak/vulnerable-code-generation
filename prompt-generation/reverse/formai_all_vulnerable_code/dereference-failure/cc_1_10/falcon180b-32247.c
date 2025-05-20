//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_QUEUE_SIZE 10
#define INIT_VALUE 0

typedef struct {
    int data;
    struct node* next;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail;
    int count;
    sem_t sem;
} queue_t;

void init_queue(queue_t* q) {
    q->head = NULL;
    q->tail = NULL;
    q->count = INIT_VALUE;
    sem_init(&q->sem, 0, MAX_QUEUE_SIZE);
}

void push(queue_t* q, int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    sem_wait(&q->sem);

    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    q->count++;

    sem_post(&q->sem);
}

int pop(queue_t* q) {
    int data = INIT_VALUE;
    node_t* temp_node = NULL;

    sem_wait(&q->sem);

    if (q->head!= NULL) {
        temp_node = q->head;
        q->head = q->head->next;
        data = temp_node->data;
        free(temp_node);
    }

    q->count--;

    sem_post(&q->sem);

    return data;
}

int is_empty(queue_t* q) {
    return q->count == INIT_VALUE;
}

int is_full(queue_t* q) {
    return q->count == MAX_QUEUE_SIZE;
}

void print_queue(queue_t* q) {
    node_t* temp_node = q->head;
    printf("Queue elements: ");

    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }

    printf("\n");
}

int main() {
    queue_t q;
    init_queue(&q);

    int i;
    for (i = 0; i < MAX_QUEUE_SIZE + 1; i++) {
        push(&q, i);
        printf("Pushed element %d\n", i);
    }

    for (i = 0; i < MAX_QUEUE_SIZE; i++) {
        printf("Popped element %d\n", pop(&q));
    }

    print_queue(&q);

    return 0;
}