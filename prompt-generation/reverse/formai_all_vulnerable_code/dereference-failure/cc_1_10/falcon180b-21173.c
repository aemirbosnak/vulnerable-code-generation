//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;

    // Insert a node at the beginning of the list
    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    // Insert a node at the end of the list
    struct Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = (struct Node*) malloc(sizeof(struct Node));
    temp->next->data = 2;
    temp->next->next = NULL;

    // Insert a node at a specific position
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 3;
    new_node->next = NULL;
    temp = head;
    int position = 1;
    while (position!= 2 && temp!= NULL) {
        temp = temp->next;
        position++;
    }
    new_node->next = temp->next;
    temp->next = new_node;

    // Delete a node from the beginning of the list
    head = head->next;

    // Delete a node from the end of the list
    temp = head;
    while (temp->next->next!= NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    // Delete a node from a specific position
    temp = head;
    position = 1;
    while (position!= 2 && temp!= NULL) {
        temp = temp->next;
        position++;
    }
    struct Node* temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);

    // Print the list
    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}