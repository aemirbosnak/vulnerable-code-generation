//Falcon-180B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node *next;
};

void add_node(struct node **head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory Error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}