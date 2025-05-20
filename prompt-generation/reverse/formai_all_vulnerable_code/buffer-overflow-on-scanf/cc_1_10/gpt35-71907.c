//FormAI DATASET v1.0 Category: Memory management ; Style: secure
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void printList() {
    struct Node* temp;
    temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insertAtBeginning(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* last = head;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

int main() {
    int n, i, x;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        insertAtEnd(x);
    }

    printf("The linked list is: ");
    printList();

    return 0;
}