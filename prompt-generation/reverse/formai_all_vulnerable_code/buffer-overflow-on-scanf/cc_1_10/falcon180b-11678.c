//Falcon-180B DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node* head, int data) {
    node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* current = head;
    while(current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(node* head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements:\n");
    node* current = head;
    while(current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteNode(node** head, int data) {
    node* current = *head;
    node* previous = NULL;
    while(current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }
    if(current == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }
    if(previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

int main() {
    node* head = NULL;
    int choice, data;
    while(1) {
        printf("\nLinked List Operations\n");
        printf("1. Insert Node\n");
        printf("2. Print List\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}