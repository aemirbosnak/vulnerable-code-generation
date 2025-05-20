//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Node structure definition
struct node {
    int data;
    struct node* next;
};

int front = -1, rear = -1;
struct node* queue[MAX];

// Function to add an element to the rear of the queue
void enqueue(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory Error\n");
        exit(0);
    }

    temp->data = value;
    temp->next = NULL;

    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear++;
    }

    queue[rear] = temp;
}

// Function to remove an element from the front of the queue
int dequeue() {
    int value = -1;
    struct node* temp = NULL;

    if (front == -1) {
        printf("Queue is empty\n");
        exit(0);
    }
    else {
        temp = queue[front];
        value = temp->data;
        free(temp);
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
    }

    return value;
}

// Function to display the current state of the queue
void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]->data);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value!= -1) {
                    printf("Dequeued value is: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}