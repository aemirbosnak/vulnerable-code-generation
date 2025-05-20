//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert_at_beginning(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_position(int data, int position) {
    if (position == 1) {
        insert_at_beginning(data);
    } else {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;

        node *current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_beginning() {
    if (head == NULL) {
        return;
    }

    node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        return;
    }

    node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    node *temp = current->next;
    current->next = NULL;
    free(temp);
}

void delete_at_position(int position) {
    if (position == 1) {
        delete_at_beginning();
    } else {
        node *current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }

        node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void print_list() {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, i, data, position;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &data);
        insert_at_end(data);
    }

    printf("The original list is: ");
    print_list();

    printf("Enter the position to insert: ");
    scanf("%d", &position);
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    insert_at_position(data, position);

    printf("The list after insertion is: ");
    print_list();

    printf("Enter the position to delete: ");
    scanf("%d", &position);
    delete_at_position(position);

    printf("The list after deletion is: ");
    print_list();

    return 0;
}