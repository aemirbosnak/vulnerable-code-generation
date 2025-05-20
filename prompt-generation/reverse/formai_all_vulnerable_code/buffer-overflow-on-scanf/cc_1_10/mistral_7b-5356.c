//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define SIZE_OF_NODE 20

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *temp = NULL;
Node *newNode = NULL;

void createNode(int data) {
    newNode = (Node *)malloc(SIZE_OF_NODE * sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
}

void insertNode(int data) {
    createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList() {
    temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int i, data;

    for (i = 0; i < MAX_NODES; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(data);
    }

    displayList();

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("Memory freed!\n");

    return EXIT_SUCCESS;
}