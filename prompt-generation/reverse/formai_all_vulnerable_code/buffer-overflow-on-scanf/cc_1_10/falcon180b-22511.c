//Falcon-180B DATASET v1.0 Category: Memory management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_node(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    Node* prev = temp->next;
    while (prev!= NULL) {
        if (prev->next == temp) {
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = prev->next;
    }
}

void display_list(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;
    while (1) {
        printf("1. Add element\n2. Delete element\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 3:
                display_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}