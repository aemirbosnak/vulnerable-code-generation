//FormAI DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 5

int front = -1, rear = -1;
int queueItems[QUEUE_SIZE];

void insert(int item);
int delete();
void display();

int main() {
    int choice, item;
    while (1) {
        printf("\nQueue Operation: \n");
        printf("1. Insert Item in Queue\n");
        printf("2. Delete Item from Queue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                item = delete();
                if(item != -1) {
                    printf("\n%d deleted from the Queue.", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}

void insert(int item) {
    if (rear == QUEUE_SIZE - 1) {
        printf("\nQueue Overflow: Unable to insert item.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    queueItems[rear] = item;
    printf("\n%d inserted in the Queue.", item);
}

int delete() {
    int item;
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow: Unable to delete item.\n");
        return -1;
    }
    item = queueItems[front];
    front = front + 1;
    return item;
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nQueue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queueItems[i]);
    }
    printf("\n");
}