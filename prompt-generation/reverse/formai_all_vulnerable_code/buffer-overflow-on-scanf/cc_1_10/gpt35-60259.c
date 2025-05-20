//FormAI DATASET v1.0 Category: Queue ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5   // Use 5 elements in the queue

void enqueue(int *queue, int *front, int *rear, int element) {
    if (*rear == MAX_SIZE - 1) {  // Check if the queue is full
        printf("Queue overflow!\n");
        return;
    }

    if (*front == -1) {  // If queue is empty assign the front index to 0
        *front = 0;
    }

    *rear += 1;  // Increment the rear index
    queue[*rear] = element;  // Add the element to the rear of the queue
}

void dequeue(int *queue, int *front, int *rear) {
    if (*front == -1) {  // If queue is empty
        printf("Queue underflow!\n");
        return;
    }

    printf("%d dequeued from the queue\n", queue[*front]);  
    queue[*front] = 0;  // Remove front element from the queue
    if (*front == *rear) {   // If queue has only one element left
        *front = -1;
        *rear = -1;
    } else {
        *front += 1;   // Increment front index to dequeue next element
    }
}

void display(int *queue, int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("The queue is:\n");
    for (int i = *front; i <= *rear; i++) {
        printf("%d ", queue[i]);  // Print all elements of the queue from front to rear
    }
    printf("\n");
}

int main() {
    int queue[MAX_SIZE], front = -1, rear = -1, choice;

    do {
        printf("\n********** Main Menu **********\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                int element;
                scanf("%d", &element);
                enqueue(queue, &front, &rear, element);
                break;
            case 2:
                dequeue(queue, &front, &rear);
                break;
            case 3:
                display(queue, &front, &rear);
                break;
            case 4:
                printf("Exiting program.\n\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}