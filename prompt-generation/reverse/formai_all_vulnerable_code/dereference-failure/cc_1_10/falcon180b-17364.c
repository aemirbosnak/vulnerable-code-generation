//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;

    while (current!= NULL) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    struct Node* head = NULL;

    // Add nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print original list
    printf("Original list: ");
    printList(head);

    // Delete node with value 3
    deleteNode(&head, 3);

    // Print list after deleting node with value 3
    printf("\nList after deleting node with value 3: ");
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print reversed list
    printf("\nReversed list: ");
    printList(head);

    return 0;
}