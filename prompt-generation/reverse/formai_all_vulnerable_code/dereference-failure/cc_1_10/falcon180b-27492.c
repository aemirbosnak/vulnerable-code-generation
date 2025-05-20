//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

/* Define node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Function prototypes */
void createNode(struct Node** head, int data);
void appendNode(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void printList(struct Node* head);

int main() {
    struct Node* head = NULL;

    /* Create nodes */
    createNode(&head, 5);
    createNode(&head, 10);
    createNode(&head, 15);

    /* Append nodes */
    appendNode(&head, 20);
    appendNode(&head, 25);

    /* Print list */
    printf("Original list:\n");
    printList(head);

    /* Delete nodes */
    deleteNode(&head, 5);
    deleteNode(&head, 10);

    /* Print list */
    printf("\nList after deleting nodes with values 5 and 10:\n");
    printList(head);

    return 0;
}

/* Create a new node with given data and add it to the beginning of the list */
void createNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

/* Add a new node with given data to the end of the list */
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* lastNode = *head;
    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

/* Delete a node with given data from the list */
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->data == data) {
        (*head) = (*head)->next;
        free(*head);
        return;
    }

    struct Node* currNode = *head;
    struct Node* prevNode = NULL;

    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("Node with value %d not found.\n", data);
        return;
    }

    prevNode->next = currNode->next;
    free(currNode);
}

/* Print the list */
void printList(struct Node* head) {
    struct Node* currNode = head;
    printf("List: ");
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}