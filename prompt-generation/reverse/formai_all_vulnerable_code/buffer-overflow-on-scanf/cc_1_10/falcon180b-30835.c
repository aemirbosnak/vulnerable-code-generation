//Falcon-180B DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void add_node(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error: Unable to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void free_list(Node* head) {
    while (head!= NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("1. Add node\n2. Print list\n3. Free list\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                free_list(head);
                head = NULL;
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