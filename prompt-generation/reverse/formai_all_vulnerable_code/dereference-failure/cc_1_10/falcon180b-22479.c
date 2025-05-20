//Falcon-180B DATASET v1.0 Category: Educational ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

void createList(Node** head);
void addNode(Node** head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;
    createList(&head);
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    printList(head);
    return 0;
}

void createList(Node** head) {
    *head = NULL;
}

void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}