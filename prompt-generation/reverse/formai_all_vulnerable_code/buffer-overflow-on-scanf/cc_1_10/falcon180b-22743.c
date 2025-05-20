//Falcon-180B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void add_node(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void delete_list(struct node** head) {
    struct node* temp = *head;
    while (temp!= NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    struct node* head = NULL;
    int choice, data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Delete list\n");
        printf("4. Exit\n");
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
                delete_list(&head);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}