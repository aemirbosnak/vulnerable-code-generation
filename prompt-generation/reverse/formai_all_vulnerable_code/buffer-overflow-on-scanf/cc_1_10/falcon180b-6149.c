//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int value);
int dequeue();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n\nHappy Queue System!!\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void enqueue(int value) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Queue is full!!\n");
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d enqueued successfully!!\n", value);
}

int dequeue() {
    int value;
    struct node *temp;

    if (front == NULL) {
        printf("Queue is empty!!\n");
        return -1;
    }

    temp = front;
    value = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);

    printf("%d dequeued successfully!!\n", value);
    return value;
}

void display() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty!!\n");
        return;
    }

    printf("\nElements in the Queue are:\n");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}