//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: brave
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

Node *insert_at_end(Node *head, int data) {
    Node *new_node = create_node(data);
    Node *temp = head;

    if (head == NULL) {
        head = new_node;
        return head;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;

    return head;
}

void delete_node(Node *head, int data) {
    Node *temp = head;
    Node *prev = NULL;

    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void search_element(Node *head, int data) {
    Node *temp = head;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }

    printf("Element not found\n");
}

int main() {
    Node *head = NULL;

    head = insert_at_end(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);

    printf("Linked list: ");
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    search_element(head, 4);

    delete_node(head, 3);

    printf("Linked list after deleting 3: ");
    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}