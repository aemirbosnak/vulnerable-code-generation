//Falcon-180B DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
    } else {
        while (last->next!= NULL)
            last = last->next;

        last->next = newNode;
        newNode->next = NULL;
    }
}

void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void searchNode(Node* head, int key) {
    Node* current = head;

    while (current!= NULL) {
        if (current->data == key) {
            printf("Node found with value %d\n", key);
            return;
        }
        current = current->next;
    }

    printf("Node not found\n");
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    printf("Linked List: ");
    printList(head);

    searchNode(head, 30);
    searchNode(head, 60);

    deleteNode(&head, 20);
    deleteNode(&head, 50);

    printf("\nLinked List after deleting 20 and 50: ");
    printList(head);

    return 0;
}