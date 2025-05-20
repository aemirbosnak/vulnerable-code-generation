//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct node {
    int value;
    struct node* next;
} Node;

Node* head = NULL;

void insert(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value %d: ", i+1);
        scanf("%d", &value);
        insert(value);
    }

    printList(head);

    return 0;
}