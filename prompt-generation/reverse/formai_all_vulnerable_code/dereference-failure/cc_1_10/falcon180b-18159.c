//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int searchList(struct Node* head, int target) {
    while (head!= NULL) {
        if (head->data == target)
            return 1;
        head = head->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;

    // Adding nodes to the list
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    // Printing the list
    printf("Original List:\n");
    printList(head);

    // Searching for an element in the list
    int target = 30;
    if (searchList(head, target))
        printf("%d found in the list.\n", target);
    else
        printf("%d not found in the list.\n", target);

    return 0;
}