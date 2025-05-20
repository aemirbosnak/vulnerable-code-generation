//Falcon-180B DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Error\n");
        exit(0);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* data) {
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

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    char data[50];
    int choice, i;

    do {
        printf("\n1. Add Node");
        printf("\n2. Print List");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%s", data);
                addNode(&head, data);
                break;
            case 2:
                printf("List: ");
                printList(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 3);

    return 0;
}