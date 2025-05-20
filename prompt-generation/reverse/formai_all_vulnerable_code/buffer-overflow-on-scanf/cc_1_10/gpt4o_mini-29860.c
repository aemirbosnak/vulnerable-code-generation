//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for a mailing list node
typedef struct MailNode {
    char email[100];
    struct MailNode *next;
} MailNode;

// Function prototypes
MailNode* createNode(const char *email);
void addEmail(MailNode **head, const char *email);
void removeEmail(MailNode **head, const char *email);
void displayEmails(MailNode *head);
void freeList(MailNode *head);

// Main function to demonstrate the mailing list manager
int main() {
    MailNode *mailList = NULL;
    int choice;
    char email[100];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Clear the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                addEmail(&mailList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                removeEmail(&mailList, email);
                break;
            case 3:
                displayEmails(mailList);
                break;
            case 4:
                printf("Exiting the program.\n");
                freeList(mailList);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Create a new mail node
MailNode* createNode(const char *email) {
    MailNode *newNode = (MailNode *)malloc(sizeof(MailNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new email node");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

// Add an email to the mailing list
void addEmail(MailNode **head, const char *email) {
    MailNode *newNode = createNode(email);
    newNode->next = *head;
    *head = newNode;
    printf("Email '%s' added to the mailing list.\n", email);
}

// Remove an email from the mailing list
void removeEmail(MailNode **head, const char *email) {
    MailNode *current = *head;
    MailNode *previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email '%s' not found in the mailing list.\n", email);
        return;
    }

    if (previous == NULL) {
        *head = current->next; // The email to be removed is at the head
    } else {
        previous->next = current->next; // Bypass the node to be removed
    }

    free(current);
    printf("Email '%s' removed from the mailing list.\n", email);
}

// Display all emails in the mailing list
void displayEmails(MailNode *head) {
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    printf("Current Mailing List:\n");
    MailNode *current = head;
    while (current != NULL) {
        printf(" - %s\n", current->email);
        current = current->next;
    }
}

// Free the allocated memory for the mailing list
void freeList(MailNode *head) {
    MailNode *current = head;
    MailNode *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}