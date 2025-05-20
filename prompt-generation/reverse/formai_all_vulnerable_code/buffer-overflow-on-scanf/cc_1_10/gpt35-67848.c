//FormAI DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void push(int x) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = head;
    head = new_node;
}

void pop() {
    if (head == NULL) return;
    Node *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    Node *temp = head;
    printf("STACK: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main() {
    int choice, x;

    do {
        printf("Please select an option:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to push onto the stack: ");
                scanf("%d", &x);
                push(x);
                printf("%d has been pushed onto the stack.\n\n", x);
                break;

            case 2:
                pop();
                printf("The top element has been popped off the stack.\n\n");
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
        }

    } while (choice != 4);

    return 0;
}