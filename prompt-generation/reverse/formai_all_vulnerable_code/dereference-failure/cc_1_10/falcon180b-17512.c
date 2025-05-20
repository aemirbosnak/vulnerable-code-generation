//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data);
void printList(struct node* node);
void deleteNode(struct node **head_ref, int key);

int main() {
    struct node* head = NULL;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Created Linked List: ");
    printList(head);

    deleteNode(&head, 2);
    printf("\nLinked List after deleting 2: ");
    printList(head);

    deleteNode(&head, 3);
    printf("\nLinked List after deleting 3: ");
    printList(head);

    deleteNode(&head, 1);
    printf("\nLinked List after deleting 1: ");
    printList(head);

    return 0;
}

void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void deleteNode(struct node **head_ref, int key) {
    struct node* temp = *head_ref;
    struct node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
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