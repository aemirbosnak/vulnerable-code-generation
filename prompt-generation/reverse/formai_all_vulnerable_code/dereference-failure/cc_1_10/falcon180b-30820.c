//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertNodeAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertNodeAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int searchNode(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertNodeAtBeginning(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtBeginning(&head, 0);
    insertNodeAtEnd(&head, 3);

    // Print the list
    printf("Initial List: ");
    printList(head);

    // Search for a node
    int result = searchNode(head, 2);
    if (result == 1) {
        printf("Node found!\n");
    } else {
        printf("Node not found.\n");
    }

    // Delete a node
    deleteNode(&head, 1);

    // Print the list again
    printf("List after deleting node with data 1: ");
    printList(head);

    return 0;
}