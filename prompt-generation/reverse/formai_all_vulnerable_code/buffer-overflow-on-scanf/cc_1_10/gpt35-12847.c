//FormAI DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a node
struct node {
    int data;
    struct node *next;
};

// Function to print all the elements of the linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
struct node *insert_beginning(struct node *head, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end of the linked list
struct node *insert_end(struct node *head, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        return new_node;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Function to delete a node with a given value
struct node *delete_node(struct node *head, int data) {
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }
    return head;
}

int main() {
    struct node *head = NULL;
    int option, value;
    do {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Print the linked list\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insert_beginning(head, value);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insert_end(head, value);
                break;
            case 3:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                head = delete_node(head, value);
                break;
            case 4:
                printf("The linked list is: ");
                print_list(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 5);
    return 0;
}