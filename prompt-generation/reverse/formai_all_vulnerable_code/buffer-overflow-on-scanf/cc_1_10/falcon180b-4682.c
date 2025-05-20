//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function to create a new node
Node* create_node(char *data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_node(Node** head, char *data) {
    Node *new_node = create_node(data);
    Node *temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the list
void delete_node(Node** head, char *data) {
    Node *temp = *head;
    Node *prev = NULL;
    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void print_list(Node* head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice;
    char data[MAX_SIZE];

    while (1) {
        printf("Cyberpunk Memory Management System\n");
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%s", data);
                add_node(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%s", data);
                delete_node(&head, data);
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}