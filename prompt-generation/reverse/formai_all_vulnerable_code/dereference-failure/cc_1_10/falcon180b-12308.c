//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_DATA_LEN 1000

// Node structure definition
typedef struct Node {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
    struct Node* next;
} Node;

// Linked list implementation
Node* createNode(char* key, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, char* key, char* data) {
    Node* newNode = createNode(key, data);
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
        printf("%s - %s\n", temp->key, temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    // Append nodes
    appendNode(&head, "John", "25");
    appendNode(&head, "Jane", "30");
    appendNode(&head, "Mike", "40");

    // Print list
    printList(head);

    return 0;
}