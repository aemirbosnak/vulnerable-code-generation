//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int search(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    printList(head); // Output: 10 20 30
    printf("Search for 20: %s\n", search(head, 20)? "Found" : "Not Found"); // Output: Found
    printf("Search for 40: %s\n", search(head, 40)? "Found" : "Not Found"); // Output: Not Found
    deleteNode(&head, 20);
    printList(head); // Output: 10 30
    return 0;
}