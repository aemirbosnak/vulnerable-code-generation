//FormAI DATASET v1.0 Category: Queue ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

// Function to implement is_full queue
int is_full(int rear, int max_queue_size) {
    return rear == (max_queue_size - 1);
}

// Function to implement is_empty queue
int is_empty(int front, int rear) {
    return front > rear;
}

int main() {
    int queue[MAX_QUEUE_SIZE], front = 0, rear = -1, choice, value;
    do {
        printf("\n\nWelcome to MyQueue: The Ultimate C Queue!");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(is_full(rear, MAX_QUEUE_SIZE)) {
                    printf("\n Queue is full. Cannot insert any more elements.");
                }
                else {
                    printf("\n Enter element to insert into queue: ");
                    scanf("%d", &value);
                    queue[++rear] = value;
                    printf("\n Element %d was successfully inserted into queue!", value);
                }
                break;
            case 2:
                if(is_empty(front, rear)) {
                    printf("\n Queue is empty. Cannot remove any elements.");
                }
                else {
                    printf("\n Element %d was successfully removed from queue!", queue[front++]);
                }
                break;
            case 3:
                if(is_empty(front, rear)) {
                    printf("\n Queue is empty. Cannot display any elements.");
                }
                else {
                    int i;
                    printf("\n");
                    for(i=front;i<=rear;i++) {
                        printf("%d ", queue[i]);
                    }
                }
                break;
            case 4:
                printf("\n Thank you for using MyQueue: The Ultimate C Queue ... Goodbye!");
                break;
            default:
                printf("\n Invalid choice. Please try again.");
        }
    } while(choice!=4);

    return 0;
}