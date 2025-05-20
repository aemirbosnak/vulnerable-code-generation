//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue Overflow\n");
        exit(0);
    }
    temp->data = val;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("%d enqueued to the queue\n", val);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        exit(0);
    }
    struct node *temp = front;
    printf("%d dequeued from the queue\n", temp->data);
    front = front->next;
    free(temp);
    if (front == NULL)
        rear = NULL;
}

void display() {
    struct node *temp = front;
    if (front == NULL)
        printf("Queue is empty\n");
    else {
        printf("Elements in the queue are: ");
        while (temp!= NULL) {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, val;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Thank you for using the program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}