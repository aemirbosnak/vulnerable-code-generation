//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
/* A Donald Knuth style memory management example program in C */

#include <stdio.h>
#include <stdlib.h>

/* A structure to represent a node in the linked list */
struct Node {
    int data;
    struct Node* next;
};

/* A function to create a new node */
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* A function to add a new node at the end of the linked list */
void addNode(struct Node** head_ref, int data) {
    /* Allocate memory for the new node */
    struct Node* new_node = newNode(data);

    /* If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* Else traverse till the last node */
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    /* Add the new node at the end of the Linked List */
    last->next = new_node;
}

/* A function to print the linked list */
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* A function to delete a node at a given position */
void deleteNode(struct Node** head_ref, int pos) {
    /* Base case */
    if (*head_ref == NULL) {
        return;
    }

    /* If head node itself needs to be deleted */
    if (pos == 0) {
        *head_ref = (*head_ref)->next;
        free(*head_ref);
        return;
    }

    /* Find the node to be deleted */
    struct Node* temp = *head_ref;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }

    /* Remove the node from the Linked List */
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

/* Driver code */
int main() {
    /* Start with the empty list */
    struct Node* head = NULL;

    /* Insert 5 nodes in the Linked List */
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    /* Print the Linked List */
    printList(head);

    /* Delete the second node */
    deleteNode(&head, 2);

    /* Print the modified Linked List */
    printList(head);

    return 0;
}