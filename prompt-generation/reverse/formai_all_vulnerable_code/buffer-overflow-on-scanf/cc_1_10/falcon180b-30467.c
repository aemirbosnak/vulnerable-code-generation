//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    node->data = data;
    node->next = head;
    head = node;
}

int pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }

    struct Node *node = head;
    int data = node->data;
    head = head->next;
    free(node);

    return data;
}

void display() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    struct Node *node = head;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    int choice, data;

    do {
        printf("\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            data = pop();
            printf("Popped element is: %d\n", data);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}