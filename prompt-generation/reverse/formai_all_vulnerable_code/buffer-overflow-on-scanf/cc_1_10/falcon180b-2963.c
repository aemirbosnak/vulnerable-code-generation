//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    struct node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char data) {
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
        printf("%c ", temp->data);
        temp = temp->next;
    }
}

int searchList(Node* head, char data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    char choice;
    while (1) {
        printf("Enter 1 to add a node\n");
        printf("Enter 2 to print the list\n");
        printf("Enter 3 to search for a node\n");
        printf("Enter 4 to exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1': {
                char data;
                printf("Enter the data: ");
                scanf("%c", &data);
                addNode(&head, data);
                break;
            }
            case '2': {
                printf("List: ");
                printList(head);
                printf("\n");
                break;
            }
            case '3': {
                char data;
                printf("Enter the data to search: ");
                scanf("%c", &data);
                if (searchList(head, data)) {
                    printf("Node found\n");
                } else {
                    printf("Node not found\n");
                }
                break;
            }
            case '4': {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}