//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

// Queue node structure
typedef struct {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Create a new queue
Queue* create_queue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;
    return new_queue;
}

// Enqueue an element to the end of the queue
void enqueue(Queue* queue, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

// Dequeue an element from the front of the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Error: queue is empty\n");
        exit(1);
    }

    Node* temp_node = queue->front;
    int data = temp_node->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp_node);
    queue->size--;

    return data;
}

// Check if the queue is empty
bool is_empty(Queue* queue) {
    return queue->front == NULL;
}

// Print the contents of the queue
void print_queue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue: ");
        Node* curr_node = queue->front;
        while (curr_node!= NULL) {
            printf("%d ", curr_node->data);
            curr_node = curr_node->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue* my_queue = create_queue();

    enqueue(my_queue, 10);
    enqueue(my_queue, 20);
    enqueue(my_queue, 30);

    print_queue(my_queue);

    int dequeued_data = dequeue(my_queue);
    printf("Dequeued data: %d\n", dequeued_data);

    print_queue(my_queue);

    dequeued_data = dequeue(my_queue);
    printf("Dequeued data: %d\n", dequeued_data);

    print_queue(my_queue);

    dequeued_data = dequeue(my_queue);
    printf("Dequeued data: %d\n", dequeued_data);

    print_queue(my_queue);

    return 0;
}