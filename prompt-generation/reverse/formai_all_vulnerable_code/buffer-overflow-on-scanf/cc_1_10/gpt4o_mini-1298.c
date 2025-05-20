//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[256];
    struct Node* next;
} Node;

Node* head = NULL;

void addEmail(const char* email) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    strcpy(newNode->email, email);
    newNode->next = head;
    head = newNode;
    printf("Email '%s' added to the mailing list.\n", email);
}

void removeEmail(const char* email) {
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

void displayEmails() {
    Node* current = head;
    if (current == NULL) {
        printf("No emails in the mailing list.\n");
        return;
    }

    printf("Mailing List:\n");
    while (current != NULL) {
        printf(" - %s\n", current->email);
        current = current->next;
    }
}

void freeList() {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}

int main() {
    int choice;
    char email[256];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(email);
                break;

            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(email);
                break;

            case 3:
                displayEmails();
                break;

            case 4:
                freeList();
                printf("Exiting the mailing list manager. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}