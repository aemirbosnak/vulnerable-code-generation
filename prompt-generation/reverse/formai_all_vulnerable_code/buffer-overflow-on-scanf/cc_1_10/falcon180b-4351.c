//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure definition
typedef struct {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
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
        return;
    }
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
    list->size++;
}

// Function to search for an element in the list
Node* searchList(LinkedList* list, int data) {
    Node* temp = list->head;
    while (temp!= NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void printList(LinkedList* list) {
    Node* temp = list->head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    list.head = NULL;
    list.size = 0;

    int choice, data;

    while (1) {
        printf("1. Add element\n2. Search element\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                addNode(&list, data);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &data);
                Node* result = searchList(&list, data);
                if (result == NULL)
                    printf("Element not found.\n");
                else
                    printf("Element found.\n");
                break;
            case 3:
                printList(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}