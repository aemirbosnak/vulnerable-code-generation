//FormAI DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node and initialize it
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the beginning of list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert node at the end of list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to remove node from the list
void removeNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev;
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print all nodes of list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    printf("Welcome to the Linked List Operations program!\n");
    printf("To get started, please enter the following commands:\n");

    while(1) {
        printf("\n1. Insert node at beginning of list\n");
        printf("2. Insert node at end of list\n");
        printf("3. Remove node from list\n");
        printf("4. Print all nodes in list\n");
        printf("5. Exit program\n");
        printf("Enter your command: ");

        int command, data;
        scanf("%d", &command);

        switch(command) {
            case 1:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("Node added successfully!\n");
                break;
            case 2:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Node added successfully!\n");
                break;
            case 3:
                printf("Enter the data of the node you want to remove: ");
                scanf("%d", &data);
                removeNode(&head, data);
                printf("Node removed successfully!\n");
                break;
            case 4:
                printf("Printing all nodes in list: ");
                printList(head);
                printf("\n");
                break;
            case 5:
                printf("Thank you for using the Linked List Operations program!\n");
                exit(0);
            default:
                printf("Invalid command! Please enter a valid command.\n");
        }
    }
    return 0;
}