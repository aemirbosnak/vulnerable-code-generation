//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a node struct for our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to insert a node at the end of the list
void insertNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Insert some nodes
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);

    // Print the list
    printf("Linked List:\n");
    printList(head);

    // Free the memory
    Node* temp = head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}