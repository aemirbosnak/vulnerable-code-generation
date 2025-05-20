//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if(*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while(temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to search for an element in the list
Node* search(Node* head, int key) {
    Node* current = head;
    while(current!= NULL) {
        if(current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* node) {
    while(node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("\n1. Add element\n2. Search element\n3. Print list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                Node* result = search(head, data);
                if(result!= NULL)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 3:
                printf("List: ");
                printList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 4);

    return 0;
}