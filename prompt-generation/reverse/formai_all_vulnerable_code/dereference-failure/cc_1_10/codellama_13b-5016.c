//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    #define MAX_SIZE 10

    typedef struct {
        int data;
        struct node* next;
    } node;

    typedef struct {
        node* front;
        node* rear;
        size_t size;
    } queue;

    queue* create_queue() {
        queue* q = malloc(sizeof(queue));
        q->front = NULL;
        q->rear = NULL;
        q->size = 0;
        return q;
    }

    bool is_empty(queue* q) {
        return q->size == 0;
    }

    bool is_full(queue* q) {
        return q->size == MAX_SIZE;
    }

    void enqueue(queue* q, int data) {
        if (is_full(q)) {
            printf("Queue is full\n");
            return;
        }
        node* new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;
        if (q->front == NULL) {
            q->front = new_node;
        } else {
            q->rear->next = new_node;
        }
        q->rear = new_node;
        q->size++;
    }

    int dequeue(queue* q) {
        if (is_empty(q)) {
            printf("Queue is empty\n");
            return -1;
        }
        int data = q->front->data;
        node* old_front = q->front;
        q->front = q->front->next;
        free(old_front);
        q->size--;
        return data;
    }

    void print_queue(queue* q) {
        node* current = q->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }

    int main() {
        queue* q = create_queue();
        enqueue(q, 1);
        enqueue(q, 2);
        enqueue(q, 3);
        print_queue(q);
        int data = dequeue(q);
        printf("Dequeued data: %d\n", data);
        print_queue(q);
        return 0;
    }