//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

void createLinkedList(struct Node** head, int size, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* searchLinkedList(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;
    int size, i, key;

    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        createLinkedList(&head, size, i + 1);
    }

    printf("Original linked list:\n");
    displayLinkedList(head);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    struct Node* result = searchLinkedList(head, key);

    if (result!= NULL) {
        printf("Key %d found at position %d\n", key, result->data);
    } else {
        printf("Key %d not found in the linked list\n", key);
    }

    return 0;
}