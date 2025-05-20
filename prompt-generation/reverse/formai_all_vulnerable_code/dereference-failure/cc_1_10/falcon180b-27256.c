//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* searchList(Node* head, char* data) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    addNode(&head, "apple");
    addNode(&head, "banana");
    addNode(&head, "cherry");
    addNode(&head, "date");
    addNode(&head, "elderberry");
    addNode(&head, "fig");
    addNode(&head, "grape");
    addNode(&head, "honeydew");
    addNode(&head, "kiwi");
    addNode(&head, "lemon");

    printf("Original list:\n");
    printList(head);

    Node* foundNode = searchList(head, "kiwi");
    if (foundNode!= NULL) {
        printf("Found \"%s\" in the list!\n", foundNode->data);
    } else {
        printf("\"%s\" not found in the list.\n", "kiwi");
    }

    return 0;
}