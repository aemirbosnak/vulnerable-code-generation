//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    int frequency;
    struct node* next;
};

typedef struct node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->frequency = 1;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d - %d\n", temp->data, temp->frequency);
        temp = temp->next;
    }
}

void deleteList(Node** head) {
    Node* temp = *head;
    while (temp!= NULL) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Add element\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added:\n");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Exiting...\n");
                deleteList(&head);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}