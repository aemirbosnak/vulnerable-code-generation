//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

int main() {
    // Initialize the head of the linked list
    Node* head = NULL;

    // Add nodes to the linked list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    // Print the linked list
    printList(head);

    // Delete a node from the linked list
    deleteNode(&head, 2);

    // Print the linked list after deletion
    printList(head);

    return 0;
}

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the linked list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

// Function to delete a node with the given data from the linked list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp!= NULL && temp->data!= data) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Error: Node with data %d not found.\n", data);
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
    }
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        Node* temp = head;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}