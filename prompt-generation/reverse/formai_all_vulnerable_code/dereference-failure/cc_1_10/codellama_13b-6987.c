//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int size;
} queue;

void enqueue(queue* q, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    q->size++;
}

int dequeue(queue* q) {
    if (q->head == NULL) {
        return -1;
    }

    int data = q->head->data;
    node* temp = q->head;
    q->head = q->head->next;
    free(temp);

    q->size--;
    return data;
}

void print_queue(queue* q) {
    node* temp = q->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    print_queue(q);

    int data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    print_queue(q);

    return 0;
}