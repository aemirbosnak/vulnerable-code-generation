//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    struct node* last_node = *head_ref;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void print_list(struct node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int size = 0;
    char choice;
    do {
        printf("Enter 1 to add an element to the list\n");
        printf("Enter 2 to print the list\n");
        printf("Enter 3 to exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1': {
                int data;
                printf("Enter the data to add: ");
                scanf("%d", &data);
                add_node(&head, data);
                size++;
                break;
            }
            case '2': {
                print_list(head);
                break;
            }
            case '3': {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (choice!= '3');
    return 0;
}