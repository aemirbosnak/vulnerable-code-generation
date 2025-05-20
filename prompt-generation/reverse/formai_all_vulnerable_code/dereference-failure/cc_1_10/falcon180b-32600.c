//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void createList(Node** head) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = 0;
    newNode->next = NULL;
    *head = newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
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

void searchElement(Node* head, int key) {
    Node* current = head;

    while (current!= NULL) {
        if (current->data == key) {
            printf("%d found\n", key);
            return;
        }
        current = current->next;
    }

    printf("%d not found\n", key);
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    createList(&head);

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    printf("Linked List: ");
    printList(head);

    searchElement(head, 20);
    searchElement(head, 60);

    deleteNode(&head, 30);

    printf("\nLinked List after deleting 30: ");
    printList(head);

    return 0;
}