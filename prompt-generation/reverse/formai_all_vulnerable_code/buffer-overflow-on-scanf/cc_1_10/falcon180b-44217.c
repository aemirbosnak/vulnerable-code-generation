//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct node {
    int data;
    struct node* next;
};

// Function to print linked list
void printList(struct node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to add element at the beginning of linked list
void push(struct node** head, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Function to add element at the end of linked list
void append(struct node** head, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
    } else {
        struct node* last = *head;
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}

int main() {
    struct node* head = NULL;
    int choice, data;

    while(1) {
        printf("\n1. Push\n2. Append\n3. Print List\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to be pushed: ");
                scanf("%d", &data);
                push(&head, data);
                break;

            case 2:
                printf("Enter data to be appended: ");
                scanf("%d", &data);
                append(&head, data);
                break;

            case 3:
                printList(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}