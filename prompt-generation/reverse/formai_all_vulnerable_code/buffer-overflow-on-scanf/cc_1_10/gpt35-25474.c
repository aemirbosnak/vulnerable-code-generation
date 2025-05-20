//FormAI DATASET v1.0 Category: Linked list operations ; Style: genious
#include<stdio.h>
#include<stdlib.h>

// Defining the Node Structure 
typedef struct Node {
    int data;                   // For holding data in linked list
    struct Node *next;          // Pointer to the next node in a linked list
} Node;

// Defining the Head Node
Node *head = NULL;

// Function to insert the node at beginning of the linked list
void insertAtBeginning(int value) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert the node at end of the linked list
void insertAtEnd(int value) {
    Node *newNode, *temp;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert the node at a specific position in the linked list
void insertAtPosition(int value, int position) {
    Node *newNode, *temp;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    temp = head;
    for(int i = 1; i < position-1; i++) {
        temp = temp->next;
        if(temp == NULL) {
            printf("\nInvalid position");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the node at beginning of the linked list
void deleteFromBeginning() {
    if(head == NULL) {
        printf("\nUnderflow. Linked List is empty.");
        return;
    }
    Node *temp = head;
    head = temp->next;
    free(temp);
}

// Function to delete the node at end of the linked list
void deleteFromEnd() {
    if(head == NULL) {
        printf("\nUnderflow. Linked List is empty.");
        return;
    }
    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete the node at a specific position in the linked list
void deleteFromPosition(int position) {
    if(head == NULL) {
        printf("\nUnderflow. Linked List is empty.");
        return;
    }
    Node *temp1 = head, *temp2 = head;
    if(position == 1) {
        head = temp1->next;
        free(temp1);
        return;
    }
    for(int i = 1; i < position; i++) {
        temp2 = temp1;
        temp1 = temp1->next;
        if(temp1 == NULL) {
            printf("\nInvalid position");
            return;
        }
    }
    temp2->next = temp1->next;
    free(temp1);
}

// Function to display the linked list
void display() {
    Node *temp = head;
    if(head == NULL) {
        printf("\nLinked List is empty.");
        return;
    }
    printf("\nLinked List:");
    while (temp != NULL) {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL");
}

// Main Function
int main() {
    int value, position, choice;
    while(1) {
        printf("\n*** Linked List Operations ***\n");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at specific Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from specific Position");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                printf("\nNode has been inserted at the beginning of Linked List.");
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                printf("\nNode has been inserted at the end of Linked List.");
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("\nEnter the position to insert the node: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                printf("\nNode has been inserted at position %d.", position);
                break;
            case 4:
                deleteFromBeginning();
                printf("\nNode has been deleted from beginning of Linked List.");
                break;
            case 5:
                deleteFromEnd();
                printf("\nNode has been deleted from end of Linked List.");
                break;
            case 6:
                printf("\nEnter the position to delete the node: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                printf("\nNode has been deleted from position %d.", position);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid Choice. Please try Again!!\n");
                break;
        }
    }
    return 0;
}