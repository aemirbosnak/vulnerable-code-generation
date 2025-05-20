//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *head;

// Creating a new node for the linked list
Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Inserting a node at the end of the linked list
void insertEnd(int data) {
    Node *newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Inserting a node at the begining of the linked list
void insertBegin(int data) {
    Node *newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// Delete a node from the linked list
void deleteNode(int data) {
    if(head == NULL) {
        printf("List is empty. Cannot delete element.\n");
        return;
    }
    if(head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node *prev = head;
    Node *temp = head->next;
    while(temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Element not found. Cannot delete.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Display the linked list
void display() {
    if(head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    head = NULL;
    printf("Linked List operations:\n");
    printf("1. Insert at the begining\n2. Insert at the end\n3. Delete a node\n4. Display the list\n");
    while(1) {
        printf("\nEnter your choice: ");
        int choice, data;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertBegin(data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}