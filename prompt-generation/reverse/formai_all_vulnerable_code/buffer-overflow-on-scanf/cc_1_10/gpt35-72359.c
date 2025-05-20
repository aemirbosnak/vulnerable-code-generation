//FormAI DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}NODE;

NODE* head = NULL; // global head pointer

// function to create a new node
NODE* createNode(int data) {
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a node at the beginning
void insertAtBeginning(int data) {
    NODE* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning!\n", data);
}

// function to insert a node at the end
void insertAtEnd(int data) {
    NODE* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        printf("%d inserted at the end!\n", data);
        return;
    }
    NODE* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    printf("%d inserted at the end!\n", data);
}

// function to insert a node at a specific position
void insertAtPosition(int data, int position) {
    NODE* newNode = createNode(data);
    if(position == 1) {
        newNode->next = head;
        head = newNode;
        printf("%d inserted at position %d!\n", data, position);
        return;
    }
    NODE* current = head;
    int count = 1;
    while(current != NULL && count < (position - 1)) {
        count++;
        current = current->next;
    }
    if(current == NULL) {
        printf("Position %d does not exist. Node not inserted!\n", position);
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
    printf("%d inserted at position %d!\n", data, position);
}

// function to delete the first occurrence of a node with a given value
void deleteNode(int data) {
    if(head == NULL) {
        printf("List is empty. Nothing to delete!\n");
        return;
    }
    NODE* current = head;
    NODE* previous = NULL;
    while(current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if(current == NULL) {
        printf("%d not found in the list. Nothing to delete!\n", data);
        return;
    }
    if(previous == NULL) { // deleting the first node
        head = current->next;
    }
    else {
        previous->next = current->next;
    }
    free(current);
    printf("%d deleted from the list!\n", data);
}

// function to display the contents of the linked list
void displayList() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    NODE* current = head;
    printf("List: ");
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data, position;
    while(1) {
        printf("\nLinked List Operations\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete node\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again!\n");
                break;
        }
    }
    return 0;
}