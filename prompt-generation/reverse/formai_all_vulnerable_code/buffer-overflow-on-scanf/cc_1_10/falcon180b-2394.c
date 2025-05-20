//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = -1;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* currNode = *head;
    while (currNode->next!= -1) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

void printList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

void searchList(Node* head, int target) {
    Node* currNode = head;
    while (currNode!= NULL) {
        if (currNode->data == target) {
            printf("Found element at position %d\n", currNode->data);
            return;
        }
        currNode = currNode->next;
    }
    printf("Element not found\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    printf("Enter 1 to add element\n");
    printf("Enter 2 to print list\n");
    printf("Enter 3 to search element\n");
    printf("Enter 4 to exit\n");

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchList(head, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}