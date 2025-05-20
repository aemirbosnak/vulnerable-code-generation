//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* current = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(Node* head) {
    Node* current = head;

    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    printf("Enter %d integers:\n", MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; ++i) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printList(head);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }

    printf("Memory released.\n");

    return EXIT_SUCCESS;
}