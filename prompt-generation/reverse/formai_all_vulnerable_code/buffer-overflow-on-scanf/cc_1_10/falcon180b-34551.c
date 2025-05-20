//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** head_ref) {
    struct Node* new_node = NULL;
    int num;

    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &num);

    printf("Enter the elements:\n");
    for (int i = 0; i < num; i++) {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        if (*head_ref == NULL) {
            *head_ref = new_node;
            return;
        }

        struct Node* last = *head_ref;
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void reverseList(struct Node **head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;

    while (current!= NULL) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
    struct Node* head = NULL;
    createList(&head);
    printf("Original list:\n");
    printList(head);

    reverseList(&head);
    printf("\nReversed list:\n");
    printList(head);

    return 0;
}