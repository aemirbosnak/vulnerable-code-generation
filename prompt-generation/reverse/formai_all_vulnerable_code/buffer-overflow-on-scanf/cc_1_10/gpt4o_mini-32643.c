//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 10

// Define a futuristic structure for an element in the queue
typedef struct CosmicElement {
    char name[50];
    int id;
    float energy;
} CosmicElement;

typedef struct CosmicQueue {
    CosmicElement elements[MAX];
    int front;
    int rear;
} CosmicQueue;

// Initialize the cosmic queue
void initQueue(CosmicQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int isEmpty(CosmicQueue *queue) {
    return (queue->front == -1);
}

// Check if the queue is full
int isFull(CosmicQueue *queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Add an element to the cosmic queue
void enqueue(CosmicQueue *queue, CosmicElement element) {
    if (isFull(queue)) {
        printf("The cosmic queue is full! Cannot enqueue %s.\n", element.name);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->elements[queue->rear] = element;
    printf("Enqueued %s to the cosmic queue.\n", element.name);
}

// Remove an element from the cosmic queue
CosmicElement dequeue(CosmicQueue *queue) {
    CosmicElement element;
    if (isEmpty(queue)) {
        printf("The cosmic queue is empty! Cannot dequeue.\n");
        element.id = -1; // indicating an invalid element
        return element;
    }
    element = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Queue is empty after this operation
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    printf("Dequeued %s from the cosmic queue.\n", element.name);
    return element;
}

// Peek the front element of the cosmic queue
CosmicElement peek(CosmicQueue *queue) {
    CosmicElement element;
    if (isEmpty(queue)) {
        printf("The cosmic queue is empty! Cannot peek.\n");
        element.id = -1; // indicating an invalid element
        return element;
    }
    return queue->elements[queue->front];
}

// Display the contents of the cosmic queue
void displayQueue(CosmicQueue *queue) {
    if (isEmpty(queue)) {
        printf("The cosmic queue is empty!\n");
        return;
    }
    printf("Current elements in the cosmic queue:\n");
    for (int i = 0; i < MAX; i++) {
        if (i < (queue->rear + 1) % MAX) {
            printf("ID: %d, Name: %s, Energy: %.2f\n", queue->elements[i].id, queue->elements[i].name, queue->elements[i].energy);
        }
    }
}

// Main alien communication module
int main() {
    CosmicQueue queue;
    initQueue(&queue);
    
    while (1) {
        printf("\n--- Cosmic Queue Control Interface ---\n");
        printf("1. Enqueue a Cosmic Element\n");
        printf("2. Dequeue a Cosmic Element\n");
        printf("3. Peek at the Front Element\n");
        printf("4. Display Queue Contents\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            CosmicElement element;
            printf("Enter the ID of the Cosmic Element: ");
            scanf("%d", &element.id);
            printf("Enter the name of the Cosmic Element: ");
            scanf("%s", element.name);
            printf("Enter the energy level of the Cosmic Element: ");
            scanf("%f", &element.energy);
            enqueue(&queue, element);
        } else if (choice == 2) {
            CosmicElement element = dequeue(&queue);
            if (element.id != -1) {
                printf("Successfully dequeued Cosmic Element - ID: %d, Name: %s, Energy: %.2f\n", element.id, element.name, element.energy);
            }
        } else if (choice == 3) {
            CosmicElement element = peek(&queue);
            if (element.id != -1) {
                printf("Front Cosmic Element - ID: %d, Name: %s, Energy: %.2f\n", element.id, element.name, element.energy);
            }
        } else if (choice == 4) {
            displayQueue(&queue);
        } else if (choice == 5) {
            printf("Exiting the Cosmic Queue Control Interface. Safe travels through the cosmos!\n");
            break;
        } else {
            printf("Invalid option! Please select a valid choice.\n");
        }
        sleep(1); // pause for a moment before the next interaction
    }

    return 0;
}