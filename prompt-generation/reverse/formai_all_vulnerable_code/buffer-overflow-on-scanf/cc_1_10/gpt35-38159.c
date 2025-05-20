//FormAI DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email_address[100];
    struct node *next;
} Node;

Node *head = NULL;

void display_all_emails() {
    if (head == NULL) {
        printf("No emails to display.\n");
        return;
    }
    printf("Email List:\n");
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%s\n", current_node->email_address);
        current_node = current_node->next;
    }
}

void add_email(char email[]) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->email_address, email);
    new_node->next = head;
    head = new_node;
    printf("Email added successfully.\n");
}

void remove_email(char email[]) {
    if (head == NULL) {
        printf("No emails to remove.\n");
        return;
    }
    if (strcmp(head->email_address, email) == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Email removed successfully.\n");
        return;
    }
    Node *current_node = head->next;
    Node *previous_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->email_address, email) == 0) {
            previous_node->next = current_node->next;
            free(current_node);
            printf("Email removed successfully.\n");
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    printf("Email not found.\n");
}

int main() {
    int choice;
    char email[100];
    while (1) {
        printf("1. Display all emails.\n");
        printf("2. Add email.\n");
        printf("3. Remove email.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_all_emails();
                break;
            case 2:
                printf("Enter email address: ");
                scanf("%s", email);
                add_email(email);
                break;
            case 3:
                printf("Enter email address: ");
                scanf("%s", email);
                remove_email(email);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}