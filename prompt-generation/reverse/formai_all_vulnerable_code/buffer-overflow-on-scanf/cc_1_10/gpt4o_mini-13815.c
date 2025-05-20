//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("\n🎉 Oh no! The queue is full! Can't add %d to the party! 🎊\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // First element 
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("\n🎈 Yay! %d joined the queue! Welcome! 🎈\n", value);
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("\n😢 Oops! The queue is empty! No one to dequeue! 😢\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Reset queue after last element
    }
    printf("\n🎉 Hooray! %d has left the queue! Goodbye! 🎉\n", value);
    return value;
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("\n😴 The queue is looking empty and lonely! 😴\n");
        return;
    }
    printf("\n🎊 Current Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("🎊\n");
}

// Main function to run the queue program
int main() {
    Queue q;
    initQueue(&q);
    int choice, value;

    do {
        printf("\n☺️ Welcome to the Queue Management System! ☺️\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("🌈 Please enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("🎁 Enter a number to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("\n🎊 Thank you for visiting the Queue! Goodbye! 🎊\n");
                break;
            default:
                printf("\n❌ Invalid choice! Please choose a valid option (1-4)! ❌\n");
        }
    } while (choice != 4);

    return 0;
}