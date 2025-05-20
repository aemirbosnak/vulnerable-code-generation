//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node to the end of the linked list
void addNode(Node** head, int data) {
    Node *node = newNode(data);
    Node *temp = *head;
    if (*head == NULL) {
        *head = node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

// Function to search for a node in the linked list
Node* searchNode(Node* head, int data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(Node* head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    // Add nodes to the linked list
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    // Print the linked list
    printf("Linked list: ");
    printList(head);

    // Search for a node in the linked list
    printf("\nEnter the data to search: ");
    scanf("%d", &data);
    Node* result = searchNode(head, data);
    if (result == NULL) {
        printf("Node not found.\n");
    } else {
        printf("Node found.\n");
    }

    // Exit the program
    return 0;
}