//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    int data = -1;
    node* temp = front;

    if (front!= NULL) {
        data = front->data;
        front = front->next;
        free(temp);
    }

    return data;
}

void display() {
    node* temp = front;

    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, data;

    printf("Enter 1 to enqueue, 2 to dequeue, and 3 to display.\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            data = dequeue();
            if (data!= -1)
                printf("Dequeued data: %d\n", data);
            break;

        case 3:
            display();
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}