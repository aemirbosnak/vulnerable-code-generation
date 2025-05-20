//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(int data);
Node* addNode(Node* head, int data);
Node* deleteNode(Node* head, int data);
void printList(Node* head);

int main() {
    // Create an empty list
    Node* head = NULL;

    // Add some nodes
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);

    // Print the list
    printf("The list contains the following values:\n");
    printList(head);

    // Delete a node
    head = deleteNode(head, 2);

    // Print the list again
    printf("\nAfter deleting the node with value 2:\n");
    printList(head);

    return 0;
}

// Function to create a new node with given data
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

// Function to add a node at the end of the list
Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to delete a node with given data
Node* deleteNode(Node* head, int data) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("The node with value %d does not exist in the list.\n", data);
        return head;
    }
    if (prev == NULL) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    return head;
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}