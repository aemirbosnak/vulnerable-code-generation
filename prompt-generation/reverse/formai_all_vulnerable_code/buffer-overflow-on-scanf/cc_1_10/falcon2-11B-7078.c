//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createQueue(int size) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < size; i++) {
        Node* newNode = createNode(i);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printQueue(Node* head) {
    Node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    Node* head = createQueue(size);
    printQueue(head);

    return 0;
}