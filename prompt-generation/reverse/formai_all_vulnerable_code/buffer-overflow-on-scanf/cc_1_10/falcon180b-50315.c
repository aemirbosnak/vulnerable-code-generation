//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure
typedef struct {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Function to delete a node with given data
void deleteNode(LinkedList* list, int data) {
    Node* temp = list->head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        list->head = temp->next;
        free(temp);
        list->size--;
    }
    else {
        while (temp!= NULL && temp->data!= data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node not found\n");
        }
        else {
            prev->next = temp->next;
            free(temp);
            list->size--;
        }
    }
}

// Function to display the list
void displayList(LinkedList* list) {
    Node* temp = list->head;
    if (temp == NULL) {
        printf("List is empty\n");
    }
    else {
        printf("List elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, data;
    LinkedList list;
    list.head = NULL;
    list.size = 0;

    while (1) {
        printf("1. Add node\n2. Delete node\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &data);
                addNode(&list, data);
                break;
            case 2:
                printf("Enter data for node to be deleted: ");
                scanf("%d", &data);
                deleteNode(&list, data);
                break;
            case 3:
                displayList(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}