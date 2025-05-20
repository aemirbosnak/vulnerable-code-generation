//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("\nQueue is Full!!");
        exit(0);
    }

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL)
        front = newnode;
    else
        rear->next = newnode;

    rear = newnode;
}

void dequeue() {
    printf("\nDeleted element is %d", front->data);
    struct node *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void display() {
    struct node *temp = front;

    if (front == NULL)
        printf("\nQueue is Empty");
    else {
        printf("\nElements in the Queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int ch, value;

    while (1) {
        printf("\n\n*********MENU*********\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("\nEnter the value to be inserted: ");
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
            printf("\nInvalid Choice!! Please try again..");
        }
    }

    return 0;
}