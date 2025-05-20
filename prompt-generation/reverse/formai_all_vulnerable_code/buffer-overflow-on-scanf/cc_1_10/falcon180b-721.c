//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_element(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void traverse_list(struct node *head) {
    printf("List elements: ");
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search_element(struct node *head, int data) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct node *head = NULL;
    int choice, data;

    while (1) {
        printf("Enter 1 to insert an element\nEnter 2 to search an element\nEnter 3 to display the list\nEnter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert_element(&head, data);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                if (search_element(head, data)) {
                    printf("%d found in the list.\n", data);
                } else {
                    printf("%d not found in the list.\n", data);
                }
                break;
            case 3:
                traverse_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}