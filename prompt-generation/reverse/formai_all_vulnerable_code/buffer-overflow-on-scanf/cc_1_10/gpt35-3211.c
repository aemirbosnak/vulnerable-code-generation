//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include<stdio.h>
#include<stdbool.h>

#define MAX 50

int front = -1, rear = -1;

typedef struct {
    int weight;
    int destination;
} baggage;

baggage Queue[MAX];

bool isFull() {
    return (rear == MAX-1);
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void insertBaggage(baggage b) {
    if (isFull()) {
        printf("Queue is full! Cannot insert baggage");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        Queue[rear] = b;
        printf("\nBaggage with weight %d and destination %d inserted successfully", b.weight, b.destination);
    }
}

baggage deleteBaggage() {
    if (isEmpty()) {
        printf("\nQueue is empty! Cannot remove baggage");
    }
    else {
        baggage b = Queue[front];
        front++;
        printf("\nBaggage with weight %d and destination %d removed successfully", b.weight, b.destination);
        return b;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("\nQueue is empty!");
    }
    else {
        printf("\nQueue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d(w%d) ", Queue[i].destination, Queue[i].weight);
        }
    }
}

int main() {
    int choice;
    baggage b;
    printf("Airport Baggage Handling Simulation\n");
    printf("----------------------------------");

    do {
        printf("\n\n1. Add Baggage\n2. Remove Baggage\n3. Display Baggage Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add Baggage
                    printf("\nEnter weight of baggage: ");
                    scanf("%d", &b.weight);
                    printf("Enter destination of baggage: ");
                    scanf("%d", &b.destination);
                    insertBaggage(b);
                    break;

            case 2: // Remove Baggage
                    deleteBaggage();
                    break;

            case 3: // Display Queue
                    displayQueue();
                    break;

            case 4: // Exit
                    printf("\nExiting simulation...");
                    break;

            default: printf("\nInvalid choice! Please select a valid option");
        }
    } while (choice != 4);

    return 0;
}