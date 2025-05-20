//FormAI DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("\nLinked list is empty.");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int countNodes(Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("\nLinked list is empty.");
        return;
    }
    printf("\nLinked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;
    int choice, data;

    do {
        printf("\n\nLinked list operations\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete from beginning\n");
        printf("4. Count nodes\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                printf("\nEnter element to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 3:
                deleteFromBeginning(&head);
                break;

            case 4:
                printf("\nNumber of nodes: %d", countNodes(head));
                break;

            case 5:
                displayList(head);
                break;

            case 6:
                printf("\nExiting from program...");
                exit(EXIT_SUCCESS);

            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (1);

    return 0;
}