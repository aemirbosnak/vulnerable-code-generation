//FormAI DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert(int num) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}

void delete(int num) {
    Node *temp = head;
    Node *prev = NULL;

    if (temp != NULL && temp->data == num) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != num) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", num);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display() {
    Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, num;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to be inserted: ");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                printf("Enter number to be deleted: ");
                scanf("%d", &num);
                delete(num);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}