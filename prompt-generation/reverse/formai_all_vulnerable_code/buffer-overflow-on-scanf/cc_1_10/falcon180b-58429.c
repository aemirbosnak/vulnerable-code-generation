//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createLinkedList(int size) {
    Node* head = NULL;
    int i;

    for (i = 0; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("Memory error\n");
            exit(1);
        }
        newNode->data = rand() % 1000;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    return head;
}

Node* searchLinkedList(Node* head, int target) {
    Node* current = head;

    while (current!= NULL) {
        if (current->data == target) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    int size, target;
    Node* head;

    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    head = createLinkedList(size);

    printf("Enter the target value to search: ");
    scanf("%d", &target);

    Node* result = searchLinkedList(head, target);

    if (result!= NULL) {
        printf("Target value found at position %d\n", result->data);
    } else {
        printf("Target value not found\n");
    }

    return 0;
}