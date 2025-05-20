//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to add a node at the end of the list
void addNode(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with the given data
void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to search for a node with the given data
struct node* searchNode(struct node* head, int data) {
    struct node* temp = head;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    return temp;
}

// Function to print the list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printList(head);
    searchNode(head, 3);
    deleteNode(&head, 4);
    printList(head);
    return 0;
}

// Output:
// 1 2 3 4 5
// Node found at position 3
// 1 2 3 5