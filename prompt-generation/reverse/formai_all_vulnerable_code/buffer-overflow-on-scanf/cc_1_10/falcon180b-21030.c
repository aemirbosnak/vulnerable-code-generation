//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int countNodes(Node* head) {
    int count = 0;
    while (head!= NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void reverseList(Node** headRef) {
    Node* prev = NULL;
    Node* current = *headRef;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

void deleteNode(Node** headRef, char key) {
    Node* temp = *headRef;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }
    if (prev == NULL) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;
    char choice;
    do {
        printf("1. Add node\n2. Print list\n3. Count nodes\n4. Reverse list\n5. Delete node\n6. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            printf("Enter data: ");
            char data;
            scanf("%c", &data);
            head = createNode(data);
            break;
        case '2':
            printList(head);
            break;
        case '3':
            printf("Number of nodes: %d\n", countNodes(head));
            break;
        case '4':
            reverseList(&head);
            printList(head);
            break;
        case '5':
            printf("Enter key: ");
            char key;
            scanf("%c", &key);
            deleteNode(&head, key);
            break;
        case '6':
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= '6');
    return 0;
}