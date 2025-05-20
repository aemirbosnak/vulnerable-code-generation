//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for storing email addresses
typedef struct node {
    char email[100];
    struct node *next;
} node;

// Create a new node
node *create_node(char *email) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the end of the list
void insert_node(node **head, char *email) {
    node *new_node = create_node(email);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Delete a node from the list
void delete_node(node **head, char *email) {
    node *temp = *head, *prev;
    if (strcmp(temp->email, email) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Print the list
void print_list(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

// Main function
int main() {
    node *head = NULL;
    int choice;
    char email[100];
    while (1) {
        printf("\n1. Add email\n2. Delete email\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                insert_node(&head, email);
                break;
            case 2:
                printf("Enter email to delete: ");
                scanf("%s", email);
                delete_node(&head, email);
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}