//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Global variables
struct Node* head;

// Function to insert a Node at the beginning of the Linked List
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d inserted successfully.\n", value);
}

// Function to insert a Node at the end of the Linked List
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    newNode->data = value;
    newNode->next = NULL;
    current->next = newNode;
    printf("%d inserted successfully.\n", value);
}

// Function to insert a Node at a specified position in the Linked List
void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* current = head;
    int i;
    for(i = 1; i < position - 1; i++) {
        current = current->next;
    }
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
    printf("%d inserted successfully at position %d.\n", value, position);
}

// Function to delete a Node from the Linked List
void deleteNode(int value) {
    struct Node* current = head;
    struct Node* previous = NULL;
    while(current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    if(current == NULL) {
        printf("%d not found in the Linked List.\n", value);
        return;
    }
    if(previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    printf("%d deleted successfully.\n", value);
    free(current);
}

// Function to display the contents of the Linked List
void display() {
    struct Node* current = head;
    printf("The contents of the Linked List are:\n");
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    int choice, value, position;
    printf("Welcome to the Linked List operations program!\n");
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete a Node\n");
        printf("5. Display the Linked List\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be inserted:\n");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to be inserted:\n");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the value to be inserted:\n");
                scanf("%d", &value);
                printf("Enter the position:\n");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                printf("Enter the value to be deleted:\n");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}