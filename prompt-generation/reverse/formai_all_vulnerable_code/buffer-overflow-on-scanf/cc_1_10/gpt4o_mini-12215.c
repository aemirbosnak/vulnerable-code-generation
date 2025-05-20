//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    int front, rear, count;
    char customers[MAX][100]; // Array to store customers' names
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->count == 0;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->count == MAX;
}

// Function to add a customer to the queue
void enqueue(Queue* q, char* customer) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        strcpy(q->customers[q->rear], customer);
        q->count++;
        printf("%s has been added to the queue.\n", customer);
    } else {
        printf("The queue is full! Cannot add %s.\n", customer);
    }
}

// Function to remove a customer from the queue
void dequeue(Queue* q) {
    if (!isEmpty(q)) {
        printf("%s has been served and removed from the queue.\n", q->customers[q->front]);
        q->front = (q->front + 1) % MAX;
        q->count--;
    } else {
        printf("The queue is empty! No customers to serve.\n");
    }
}

// Function to view the current queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is currently empty.\n");
    } else {
        printf("Current queue status:\n");
        for (int i = 0; i < q->count; i++) {
            int index = (q->front + i) % MAX;
            printf("%d. %s\n", i + 1, q->customers[index]);
        }
    }
}

// Main function demonstrating the usage of the queue
int main() {
    Queue queue;
    initQueue(&queue);
    char customerName[100];
    int choice;

    while (1) {
        printf("\nMovie Theater Ticketing System\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Serve Customer\n");
        printf("3. View Current Queue\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // to consume newline character left by scanf
        
        switch (choice) {
            case 1:
                printf("Enter the customer's name: ");
                fgets(customerName, sizeof(customerName), stdin);
                customerName[strcspn(customerName, "\n")] = 0; // remove newline
                enqueue(&queue, customerName);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting the ticketing system. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}