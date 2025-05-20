//FormAI DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return head;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
    return head;
}

// Function to delete the first node of the linked list
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("Error: Linked list is empty.\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("Error: Linked list is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;
    do {
        printf("Choose an operation:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Print linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("%d inserted at beginning.\n", data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("%d inserted at end.\n", data);
                break;
            case 3:
                head = deleteAtBeginning(head);
                printf("First node deleted.\n");
                break;
            case 4:
                head = deleteAtEnd(head);
                printf("Last node deleted.\n");
                break;
            case 5:
                printf("Linked list: ");
                printList(head);
                break;
            case 6:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("\n");
    } while (choice != 6);

    return 0;
}