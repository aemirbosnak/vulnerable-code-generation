//Falcon-180B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error: could not allocate space for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    Node* last = *head_ref;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
    } else {
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}

void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void delete_node(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev;
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;
    int choice, data;
    do {
        printf("\n");
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
                printf("Enter data for node to be deleted: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 3:
                printf("List: ");
                print_list(head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}