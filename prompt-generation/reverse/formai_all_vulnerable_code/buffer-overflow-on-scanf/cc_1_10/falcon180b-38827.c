//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    int value;
    Node *temp_node;

    if (front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }

    temp_node = front;
    value = front->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp_node);

    return value;
}

void display() {
    Node *temp_node = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
}

int main() {
    int choice, value;

    printf("Enter 1 to enqueue an element\n");
    printf("Enter 2 to dequeue an element\n");
    printf("Enter 3 to display the queue\n");
    printf("Enter 0 to exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            value = dequeue();
            printf("Dequeued element is: %d\n", value);
            break;

        case 3:
            display();
            break;

        case 0:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}