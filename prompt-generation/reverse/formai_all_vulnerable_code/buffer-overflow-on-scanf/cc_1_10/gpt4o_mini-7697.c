//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    char *name;
    int age;
} Survivor;

typedef struct {
    Survivor *queue[MAX_SIZE];
    int front;
    int rear;
    int count; // Tracks the number of survivors in the queue
} Queue;

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return q;
}

bool isFull(Queue *q) {
    return q->count == MAX_SIZE;
}

bool isEmpty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, Survivor *s) {
    if (isFull(q)) {
        printf("Desperate times! Survivors are being left behind.\n");
        return;
    }
    q->queue[q->rear] = s;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->count++;
    printf("%s has joined the remnants of humanity!\n", s->name);
}

Survivor* dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("No one left to rescue from the wasteland!\n");
        return NULL;
    }
    Survivor *s = q->queue[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    printf("%s has left the queue. They made it to safety!\n", s->name);
    return s;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty. No survivors waiting.\n");
        return;
    }
    printf("Remaining survivors in the queue:\n");
    for (int i = 0; i < q->count; i++) {
        int idx = (q->front + i) % MAX_SIZE;
        printf("Survivor %d: %s, Age: %d\n", i + 1, q->queue[idx]->name, q->queue[idx]->age);
    }
}

void freeQueue(Queue *q) {
    for (int i = 0; i < q->count; i++) {
        free(q->queue[(q->front + i) % MAX_SIZE]);
    }
    free(q);
}

int main() {
    Queue *survivorQueue = createQueue();
    char option;
    
    do {
        printf("\n=== Apocalyptic Survivor Queue ===\n");
        printf("1. Add Survivor\n");
        printf("2. Rescue Survivor\n");
        printf("3. Show Queue\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &option);
        
        switch (option) {
            case '1': {
                // Adding a survivor
                Survivor *newSurvivor = (Survivor *)malloc(sizeof(Survivor));
                newSurvivor->name = (char *)malloc(50);
                
                printf("Enter survivor name: ");
                scanf(" %49[^\n]", newSurvivor->name); // Read string with spaces
                printf("Enter survivor age: ");
                scanf("%d", &newSurvivor->age);
                
                enqueue(survivorQueue, newSurvivor);
                break;
            }
            case '2': {
                // Rescuing a survivor
                Survivor *rescuedSurvivor = dequeue(survivorQueue);
                if (rescuedSurvivor != NULL) {
                    free(rescuedSurvivor->name);
                    free(rescuedSurvivor);
                }
                break;
            }
            case '3':
                displayQueue(survivorQueue);
                break;
            case '4':
                printf("Farewell, brave warrior!\n");
                break;
            default:
                printf("Invalid option. Choose again.\n");
        }
    } while (option != '4');
    
    freeQueue(survivorQueue);
    return 0;
}