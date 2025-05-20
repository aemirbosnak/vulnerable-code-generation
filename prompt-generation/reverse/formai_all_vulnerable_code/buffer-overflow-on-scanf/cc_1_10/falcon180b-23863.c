//Falcon-180B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
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
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Error: Node with data %d not found.\n", data);
        return;
    }
    Node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }
    printf("List: ");
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
    do {
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                printf("Enter data for node to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}