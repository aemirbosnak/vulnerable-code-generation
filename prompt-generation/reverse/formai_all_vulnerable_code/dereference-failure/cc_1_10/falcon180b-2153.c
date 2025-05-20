//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the list
void addNode(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Check if the list is empty
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the end of the list
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Add the new node at the end
    temp->next = newNode;
    return;
}

// Function to delete a node with the given data
void deleteNode(struct Node** head, int data) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Check if the first node contains the given data
    if ((*head)->data == data) {
        *head = (*head)->next;
        free(*head);
        return;
    }

    // Traverse to the node before the one to be deleted
    struct Node* temp = *head;
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }

    // Check if the node was found
    if (temp->next == NULL) {
        printf("Node not found.\n");
        return;
    }

    // Delete the node
    temp->next = temp->next->next;
    free(temp->next);
    return;
}

// Function to display the list
void displayList(struct Node* head) {
    printf("List: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Add some nodes
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);

    // Display the list
    displayList(head);

    // Delete a node
    deleteNode(&head, 10);

    // Display the list again
    displayList(head);

    return 0;
}