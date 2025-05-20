//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
/*
 * Unique C Linked list operations example program
 */

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node *next;
};

/* Function to insert a node at the beginning of the list */
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

/* Function to insert a node at the end of the list */
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Function to delete a node at a given position */
void deleteNode(struct Node **head, int position) {
    struct Node *temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

/* Function to display the list */
void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Driver code */
int main() {
    struct Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtEnd(&head, 40);
    deleteNode(&head, 2);
    display(head);
    return 0;
}