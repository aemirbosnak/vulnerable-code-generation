//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum number of nodes

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_node(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found.\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void search_node(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Node found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Node not found.\n");
}

void print_list(Node* head) {
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
        printf("3. Search node\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            add_node(&head, data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            delete_node(&head, data);
            break;
        case 3:
            printf("Enter data to search: ");
            scanf("%d", &data);
            search_node(head, data);
            break;
        case 4:
            print_list(head);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}