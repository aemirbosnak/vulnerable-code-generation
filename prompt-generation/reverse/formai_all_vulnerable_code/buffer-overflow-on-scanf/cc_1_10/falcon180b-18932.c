//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value);
int dequeue();
void display();

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value!= -1)
                    printf("The dequeued value is %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);

    return 0;
}

void enqueue(int value) {
    Node *newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("Queue is full!\n");
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue() {
    int value = -1;

    if(front == NULL) {
        printf("Queue is empty!\n");
        return value;
    }

    Node *temp = front;
    value = front->data;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    return value;
}

void display() {
    Node *temp = front;

    if(front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("The elements in the queue are:\n");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp!= front);

    printf("\n");
}