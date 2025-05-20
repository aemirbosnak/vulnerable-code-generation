//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

//Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

//Linked list structure
typedef struct list {
    Node* head;
    int size;
} List;

//Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error: Memory could not be allocated\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to create a new empty list
List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    if(newList == NULL) {
        printf("Error: Memory could not be allocated\n");
        exit(1);
    }
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

//Function to add a node at the end of the list
void addNode(List* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;
    if(temp == NULL) {
        list->head = newNode;
    }
    else {
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

//Function to display the list
void displayList(List* list) {
    Node* temp = list->head;
    if(temp == NULL) {
        printf("List is empty\n");
    }
    else {
        printf("List elements: ");
        while(temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

//Function to free memory allocated for the list
void freeList(List* list) {
    Node* temp = list->head;
    Node* next;
    while(temp!= NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

int main() {
    List* list = createList();
    int choice, data;

    while(1) {
        printf("1. Add node\n2. Display list\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data for the node: ");
                scanf("%d", &data);
                addNode(list, data);
                break;
            case 2:
                displayList(list);
                break;
            case 3:
                freeList(list);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}