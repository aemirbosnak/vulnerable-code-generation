//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int next;
} Node;

Node *head = NULL;

void init() {
    head = (Node*)malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;
}

void addNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head->next == NULL) {
        head->next = newNode;
    } else {
        Node *temp = head->next;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(int data) {
    Node *temp = head;
    Node *prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

void searchNode(int data) {
    Node *temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Node found.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Node not found.\n");
}

int main() {
    init();

    addNode(1);
    addNode(2);
    addNode(3);

    searchNode(2); // Node found.
    searchNode(4); // Node not found.

    deleteNode(2);

    searchNode(2); // Node not found.

    return 0;
}