//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void addNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node** head, int data) {
    Node* currNode = *head;
    Node* prevNode = NULL;

    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("Node with data %d not found.\n", data);
    } else {
        if (prevNode == NULL) {
            *head = currNode->next;
        } else {
            prevNode->next = currNode->next;
        }
        free(currNode);
    }
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int searchNode(Node* head, int data) {
    Node* currNode = head;

    while (currNode!= NULL) {
        if (currNode->data == data) {
            return 1;
        }
        currNode = currNode->next;
    }

    return 0;
}

int main() {
    Node* head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    printf("Linked List: ");
    printList(head);

    deleteNode(&head, 2);

    printf("After deleting node with data 2:\n");
    printList(head);

    int searchData = 3;
    if (searchNode(head, searchData)) {
        printf("Node with data %d found.\n", searchData);
    } else {
        printf("Node with data %d not found.\n", searchData);
    }

    return 0;
}