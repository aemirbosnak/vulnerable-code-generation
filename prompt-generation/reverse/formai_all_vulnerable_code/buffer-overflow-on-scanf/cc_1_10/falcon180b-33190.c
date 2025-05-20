//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

void enqueue(struct node **front, struct node **rear, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    if (*front == NULL) {
        *front = new_node;
        *rear = new_node;
    } else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

void dequeue(struct node **front, struct node **rear) {
    struct node *temp = *front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    *front = temp->next;
    free(temp);
    if (*front == NULL) {
        *rear = NULL;
    }
}

void display(struct node *front) {
    struct node *temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *front = NULL, *rear = NULL;
    int choice, data;

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}