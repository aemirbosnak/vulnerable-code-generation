//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void appendNode(Node** head, int data);
void displayList(Node* head);
void freeList(Node* head);
void visualizeList(Node* head);

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Linked List Visualization Program ---\n");
        printf("1. Append Node\n");
        printf("2. Display List\n");
        printf("3. Visualize List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                appendNode(&head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                visualizeList(head);
                break;
            case 4:
                freeList(head);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to visualize the linked list
void visualizeList(Node* head) {
    if (head == NULL) {
        printf("The list is empty, visualization not possible.\n");
        return;
    }

    printf("\nVisualization of Linked List:\n");
    printf("Head -> ");
    Node* temp = head;
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Memory representation:\n");
    temp = head;
    while (temp != NULL) {
        printf("Node(%d): %p -> %p\n", temp->data, (void*)temp, (void*)temp->next);
        temp = temp->next;
    }
}