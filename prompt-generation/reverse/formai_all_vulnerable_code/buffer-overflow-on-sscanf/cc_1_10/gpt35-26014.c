//FormAI DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// define a structure for the Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function to print the Linked List
void printLinkedList(Node* head) {
    printf("Linked List: ");
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// function to insert a new node at the beginning of the Linked List
void insertAtBeginning(Node** head, int value) {
    // create a new Linked List Node
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = (*head);
    (*head) = newNode;
    printf("%d successfully added to the beginning of the Linked List!\n", value);
}

// function to insert a new node at the end of the Linked List
void insertAtEnd(Node** head, int value) {
    // create a new Linked List Node
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if ((*head) == NULL) {
        (*head) = newNode;
    } else {
        Node* ptr = (*head);
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    printf("%d successfully added to the end of the Linked List!\n", value);
}

// function to delete the first occurrence of a specific node in the Linked List
void deleteNode(Node** head, int key) {
    Node *temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("The first occurrence of %d successfully deleted from the Linked List!\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the Linked List!\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("The first occurrence of %d successfully deleted from the Linked List!\n", key);
}

// example main function
int main() {
    Node* head = NULL;  // initialize an empty Linked List
    printf("Welcome to My Unique Linked List Operations Program!\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Here are the valid commands for this program:\n");
    printf("------------------------------------------------------\n");
    printf("1. AddAtBeginning [value] - adds a node at the beginning of the Linked List\n");
    printf("2. AddAtEnd [value] - adds a node at the end of the Linked List\n");
    printf("3. Delete [value] - deletes the first occurrence of a specific node in the Linked List\n");
    printf("4. Print - prints the current Linked List\n");
    printf("5. Exit - exits the program\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    char command[50];
    int value;
    while (1) {
        printf("Please enter a command: ");
        fgets(command, sizeof(command), stdin);
        if (sscanf(command, "AddAtBeginning %d", &value) == 1) {
            insertAtBeginning(&head, value);
        } else if (sscanf(command, "AddAtEnd %d", &value) == 1) {
            insertAtEnd(&head, value);
        } else if (sscanf(command, "Delete %d", &value) == 1) {
            deleteNode(&head, value);
        } else if (strcmp(command, "Print\n") == 0) {
            printLinkedList(head);
        } else if (strcmp(command, "Exit\n") == 0) {
            printf("\nThank you for using My Unique Linked List Operations Program!\n");
            return 0;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }
    return 0;
}