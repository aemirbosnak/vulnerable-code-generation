//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[100];
    struct Node* next;
} Node;

Node* head = NULL;

void add_email(const char* email) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = head;
    head = new_node;
    printf("Email '%s' added to the mailing list.\n", email);
}

void view_emails() {
    if (head == NULL) {
        printf("No emails in the mailing list.\n");
        return;
    }
    Node* current = head;
    printf("Mailing List:\n");
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

void remove_email(const char* email) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email '%s' not found in the mailing list.\n", email);
        return;
    }

    if (previous == NULL) {
        head = current->next; 
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Email '%s' removed from the mailing list.\n", email);
}

void free_memory() {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice;
    char email[100];

    while (1) {
        printf("\n--- Mailing List Manager ---\n");
        printf("1. Add Email\n");
        printf("2. View Emails\n");
        printf("3. Remove Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after the number input

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';  // Remove newline character
                add_email(email);
                break;
            case 2:
                view_emails();
                break;
            case 3:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';
                remove_email(email);
                break;
            case 4:
                free_memory();
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}