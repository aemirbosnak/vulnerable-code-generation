//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void delete_node(Node **head, int data) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void display_list(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    printf("Original list: ");
    display_list(head);

    delete_node(&head, 3);

    printf("\nList after deleting node with value 3: ");
    display_list(head);

    delete_node(&head, 1);

    printf("\nList after deleting node with value 1: ");
    display_list(head);

    delete_node(&head, 5);

    printf("\nList after deleting node with value 5: ");
    display_list(head);

    delete_node(&head, 2);

    printf("\nList after deleting node with value 2: ");
    display_list(head);

    delete_node(&head, 4);

    printf("\nList after deleting node with value 4: ");
    display_list(head);

    return 0;
}