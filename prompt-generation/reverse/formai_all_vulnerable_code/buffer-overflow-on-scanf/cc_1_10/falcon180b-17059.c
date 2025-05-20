//Falcon-180B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Error: Not enough memory to create node\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void deleteList(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    free(temp);
    *head = NULL;
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("Enter 1 to add node\n");
        printf("Enter 2 to delete node\n");
        printf("Enter 3 to print list\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                deleteList(&head);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}