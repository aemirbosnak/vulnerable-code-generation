//FormAI DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Node structure to hold integer data and pointer to next node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with a given integer value
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert an element at the beginning of the list
void insertAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    if (newNode != NULL) {
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert an element at the end of the list
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (newNode != NULL) {
        Node* current = *head;
        if (current == NULL) {
            *head = newNode;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// Function to delete an element from the beginning of the list
void deleteFromBeginning(Node** head) {
    if (*head != NULL) {
        Node* current = *head;
        *head = (*head)->next;
        free(current);
    }
}

// Function to delete an element from the end of the list
void deleteFromEnd(Node** head) {
    if (*head != NULL) {
        Node* current = *head;
        Node* prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *head = NULL;
        }
        free(current);
    }
}

// Function to print all the elements in the list
void printList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL; // Initialize an empty linked list
    int choice, value;
    do {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Print list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                deleteFromBeginning(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                printList(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}