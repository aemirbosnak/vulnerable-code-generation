//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    }
    else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    printf("Node added successfully!\n");
}

// Function to delete a node with given data
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        printf("Node deleted successfully!\n");
    }
    else {
        while (temp!= NULL && temp->data!= data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node not found.\n");
        }
        else {
            prev->next = temp->next;
            free(temp);
            printf("Node deleted successfully!\n");
        }
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
    }
    else {
        printf("List elements:\n");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Add node\n2. Delete node\n3. Display list\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data for new node:\n");
            scanf("%d", &data);
            addNode(&head, data);
            break;
        case 2:
            printf("Enter data for node to be deleted:\n");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 3:
            displayList(head);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}