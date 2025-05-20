//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Define a Queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
void createQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);
void menu();

int main() {
    Queue q;
    createQueue(&q);
    int choice, value;

    printf("🌟 Welcome to the Happy Queue Program! 🌟\n");

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("✨ Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("😊 Thank you for using the Happy Queue Program! Goodbye! 😊\n");
                break;
            default:
                printf("❌ Invalid choice! Please try again. ❌\n");
        }
    } while (choice != 4);

    return 0;
}

// Initialize the queue
void createQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue an element
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("😢 Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (q->front == -1) q->front = 0; // Set front to 0 if queue was empty
        q->rear++;
        q->items[q->rear] = value;
        printf("🎉 Enqueued: %d\n", value);
    }
}

// Dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("😢 Queue is empty! No elements to dequeue.\n");
        return -1;
    } else {
        int value = q->items[q->front];
        q->front++;
        if (q->front > q->rear) { // Reset the queue when it becomes empty
            q->front = q->rear = -1;
        }
        return value;
    }
}

// Display the elements of the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("😢 Queue is empty! Nothing to display.\n");
    } else {
        printf("🌈 Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Show a menu to the user
void menu() {
    printf("\n🤗 Queue Menu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
}