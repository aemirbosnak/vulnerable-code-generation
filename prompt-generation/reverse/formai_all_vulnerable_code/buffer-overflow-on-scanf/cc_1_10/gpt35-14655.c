//FormAI DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node with data %d inserted at beginning\n", data);
}

// function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Node with data %d inserted at end\n", data);
        return;
    }
    struct Node* lastNode = *head;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = newNode;
    printf("Node with data %d inserted at end\n", data);
}

// function to insert a new node at a given position
void insertAtPos(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    struct Node* tempNode = *head;
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node with data %d inserted at position %d\n", data, pos);
        return;
    }
    for (int i = 1; i < pos - 1 && tempNode != NULL; i++)
        tempNode = tempNode->next;
    if (tempNode == NULL) {
        printf("Position %d not found\n", pos);
        return;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    printf("Node with data %d inserted at position %d\n", data, pos);
}

// function to delete a node from the list by data value
void deleteNode(struct Node** head, int data) {
    struct Node* currentNode = *head, *prevNode;
    if (currentNode != NULL && currentNode->data == data) {
        *head = currentNode->next;
        free(currentNode);
        printf("Node with data %d deleted\n", data);
        return;
    }
    while (currentNode != NULL && currentNode->data != data) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    prevNode->next = currentNode->next;
    free(currentNode);
    printf("Node with data %d deleted\n", data);
}

// function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;
    while (1) {
        printf("\n-----Linked List Operations-----\n");
        printf("1. Insert node at beginning\n");
        printf("2. Insert node at end\n");
        printf("3. Insert node at position\n");
        printf("4. Delete node by data value\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insertAtPos(&head, data, pos);
            break;
        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 5:
            printList(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}