//Falcon-180B DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

Node* create_node(char* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

void add_to_list(Node** head, char* data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete_node(Node** head, char* data) {
    Node* current = *head;
    Node* previous = NULL;
    while (current!= NULL && strcmp(current->data, data)!= 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void display_list(Node* head) {
    while (head!= NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    char choice;
    while (1) {
        printf("\nEnter 1 to add a node, 2 to delete a node, 3 to display the list, or any other key to exit: ");
        scanf("%c", &choice);
        if (choice == '1') {
            char data[MAX_SIZE];
            printf("Enter data: ");
            scanf("%s", data);
            add_to_list(&head, data);
        } else if (choice == '2') {
            char data[MAX_SIZE];
            printf("Enter data to delete: ");
            scanf("%s", data);
            delete_node(&head, data);
        } else if (choice == '3') {
            display_list(head);
        } else {
            break;
        }
    }
    return 0;
}