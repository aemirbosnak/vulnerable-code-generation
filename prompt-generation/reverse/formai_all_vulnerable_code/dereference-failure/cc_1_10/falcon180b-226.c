//Falcon-180B DATASET v1.0 Category: Sorting ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_STR_LEN 50

typedef struct node {
    int data;
    char str[MAX_STR_LEN];
    struct node* next;
} Node;

Node* createNode(int data, char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    strncpy(newNode->str, str, MAX_STR_LEN);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data, char* str) {
    Node* newNode = createNode(data, str);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* currNode = *head;
    while (currNode->next!= NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

void printList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%d - %s\n", currNode->data, currNode->str);
        currNode = currNode->next;
    }
}

int main() {
    Node* head = NULL;
    char input[MAX_STR_LEN];
    int choice, data;
    char* str;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert node\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter string: ");
                scanf("%s", input);
                str = (char*)malloc(sizeof(char) * strlen(input) + 1);
                if (str == NULL) {
                    printf("Error: Memory allocation failed.\n");
                    exit(1);
                }
                strcpy(str, input);
                insertNode(&head, data, str);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}