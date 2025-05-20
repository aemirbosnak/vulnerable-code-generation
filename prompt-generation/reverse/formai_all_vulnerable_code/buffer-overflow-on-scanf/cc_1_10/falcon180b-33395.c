//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Queue is Full!!!\n");
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
}

int dequeue() {
    int value;
    struct node *temp;

    if (front == NULL) {
        printf("Queue is Empty!!!\n");
        return -1;
    }

    temp = front;
    value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);

    return value;
}

void display() {
    struct node *ptr;

    if (front == NULL) {
        printf("Queue is Empty!!!\n");
        return;
    }

    printf("Queue elements are: ");
    ptr = front;

    while (ptr!= NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            value = dequeue();
            if (value!= -1)
                printf("Dequeued value is %d\n", value);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!!!\n");
        }
    }

    return 0;
}