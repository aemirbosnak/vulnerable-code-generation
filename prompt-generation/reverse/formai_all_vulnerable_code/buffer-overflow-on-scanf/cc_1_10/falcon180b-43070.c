//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(Node* head, int key) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    int choice, data, key;

    do {
        printf("1. Insert at end\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            printf("Data inserted successfully!\n");
            break;
        case 2:
            printf("Enter the key to be searched: ");
            scanf("%d", &key);
            if (search(head, key)) {
                printf("Key found!\n");
            } else {
                printf("Key not found!\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}