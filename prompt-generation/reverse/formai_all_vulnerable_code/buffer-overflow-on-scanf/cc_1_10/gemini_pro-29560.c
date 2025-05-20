//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

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
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_at_position(int data, int position) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if (position == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
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
    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_at_position(int position) {
    if (head == NULL) {
        return;
    }
    if (position == 1) {
        node *temp = head;
        head = head->next;
        free(temp);
    } else {
        node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void print_list() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, position;
    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Print list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insert_at_position(data, position);
                break;
            case 4:
                delete_at_beginning();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_at_position(position);
                break;
            case 7:
                print_list();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}