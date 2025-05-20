//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} node;

node *front = NULL, *rear = NULL; // Initialize front and rear to NULL

void addNode(int data) { // Function to add a node to the rear of the queue
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int deleteNode() { // Function to delete a node from the front of the queue
    int data;

    if (front == NULL) {
        printf("Queue is empty\n");
        return 0;
    }

    data = front->data;
    node *temp = front;
    front = front->next;
    free(temp);

    return data;
}

void display() { // Function to display the queue
    node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be added: ");
                scanf("%d", &data);
                addNode(data);
                break;
            case 2:
                data = deleteNode();
                if (data!= 0) {
                    printf("Deleted element is: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}