//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void push(struct Node** head_ref, int new_data);
void printList(struct Node* node);
void deleteNode(struct Node **head_ref, int key);

int main() {
    struct Node* head = NULL;

    // Insert 7
    push(&head, 7);

    // Insert 1
    push(&head, 1);

    // Insert 6
    push(&head, 6);

    // Insert 4
    push(&head, 4);

    // Print the list
    printf("List: ");
    printList(head);

    // Delete node which has data as 6
    deleteNode(&head, 6);

    // Print the list after deletion
    printf("\nList after deleting 6: ");
    printList(head);

    return 0;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key or if list is empty
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;   
        free(temp);               
        return;
    }

    // Delete node from middle or end
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);  // Free memory
}