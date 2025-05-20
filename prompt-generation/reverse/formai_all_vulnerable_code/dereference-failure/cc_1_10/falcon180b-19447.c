//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
void createQueue(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(struct queue* q) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    else {
        free(temp);
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(struct queue* q, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL)
        printf("Queue is full\n");
    else {
        temp->data = value;
        temp->next = NULL;

        if (isEmpty(q)) {
            q->front = temp;
            q->rear = temp;
        }
        else {
            q->rear->next = temp;
            q->rear = temp;
        }
    }
}

// Function to remove an element from the queue
int dequeue(struct queue* q) {
    int value;
    struct node* temp = q->front;

    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        value = temp->data;
        q->front = temp->next;

        if (q->front == NULL)
            q->rear = NULL;

        free(temp);
    }

    return value;
}

// Function to display the elements of the queue
void display(struct queue* q) {
    struct node* temp = q->front;

    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to be executed by each thread
void* threadFunction(void* arg) {
    int threadID = *(int*)arg;
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    createQueue(q);

    int i;
    for (i = 0; i < 10; i++) {
        enqueue(q, threadID*100 + i);
        printf("Thread %d enqueued %d\n", threadID, threadID*100 + i);
    }

    for (i = 0; i < 10; i++) {
        int value = dequeue(q);
        printf("Thread %d dequeued %d\n", threadID, value);
    }

    free(q);
}

// Main function
int main() {
    pthread_t threads[5];
    int i;

    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void*)i);
    }

    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}