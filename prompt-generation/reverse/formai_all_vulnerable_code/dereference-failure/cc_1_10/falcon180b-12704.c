//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char name[50];
    char email[100];
    struct node* next;
} Node;

// Function to add a new node to the end of the list
void addNode(Node** head, char* name, char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
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

// Function to search for a node with the given email
Node* searchNode(Node* head, char* email) {
    Node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->email, email) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the entire list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s - %s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

// Function to sort the list alphabetically by name
void sortList(Node** head) {
    Node* temp = *head;
    Node* prev = NULL;
    while (temp!= NULL) {
        Node* next = temp->next;
        temp->next = NULL;

        while (prev!= NULL && strcmp(prev->name, temp->name) > 0) {
            prev = prev->next;
        }

        if (prev == NULL) {
            temp->next = *head;
            *head = temp;
        } else {
            temp->next = prev->next;
            prev->next = temp;
        }

        temp = next;
    }
}

int main() {
    Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, "John Doe", "john@example.com");
    addNode(&head, "Jane Smith", "jane@example.com");
    addNode(&head, "Bob Johnson", "bob@example.com");

    // Print the unsorted list
    printf("Unsorted list:\n");
    printList(head);

    // Sort the list alphabetically by name
    sortList(&head);

    // Print the sorted list
    printf("\nSorted list:\n");
    printList(head);

    return 0;
}