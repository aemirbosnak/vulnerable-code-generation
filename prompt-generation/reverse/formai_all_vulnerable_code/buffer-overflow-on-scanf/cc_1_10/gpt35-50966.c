//FormAI DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[50];
    struct node *next;
} Node;

void add_email(Node **head, char *new_email) {
    Node *current = *head;
    Node *new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->email, new_email);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_emails(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void delete_email(Node **head, char *email_to_delete) {
    Node *current = *head;
    Node *prev = NULL;
    while (current != NULL && strcmp(current->email, email_to_delete) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Email not found.\n");
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

int main() {
    Node *head = NULL;
    char email_input[50];
    int choice;
    while (1) {
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Print emails\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email_input);
                add_email(&head, email_input);
                break;
            case 2:
                printf("Enter email to delete: ");
                scanf("%s", email_input);
                delete_email(&head, email_input);
                break;
            case 3:
                printf("Emails:\n");
                print_emails(head);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}