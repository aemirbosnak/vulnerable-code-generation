//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the mailing list node
typedef struct MailNode {
    char email[100];
    struct MailNode *next;
} MailNode;

// Function to create a new mail node
MailNode* createNode(const char *email) {
    MailNode *newNode = (MailNode*)malloc(sizeof(MailNode));
    if (newNode != NULL) {
        strncpy(newNode->email, email, sizeof(newNode->email) - 1);
        newNode->email[sizeof(newNode->email) - 1] = '\0'; // Ensure null termination
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add an email to the mailing list
void addEmail(MailNode **head, const char *email) {
    MailNode *newNode = createNode(email);
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for new email.\n");
        return;
    }
    newNode->next = *head;
    *head = newNode;
    printf("Email '%s' added successfully!\n", email);
}

// Function to remove an email from the mailing list
void removeEmail(MailNode **head, const char *email) {
    MailNode *temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Email '%s' not found in the list.\n", email);
        return;
    }

    if (prev == NULL) {
        *head = temp->next; // The email to be deleted is the head
    } else {
        prev->next = temp->next; // Bypass the node to be deleted
    }
    
    free(temp);
    printf("Email '%s' removed successfully!\n", email);
}

// Function to display the mailing list
void displayEmails(MailNode *head) {
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    printf("Current Mailing List:\n");
    while (head != NULL) {
        printf("- %s\n", head->email);
        head = head->next;
    }
}

// Function to free allocated memory for the mailing list
void freeMailingList(MailNode *head) {
    MailNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function - Mailing list manager
int main() {
    MailNode *mailingList = NULL;
    int choice;
    char email[100];

    while (1) {
        printf("\nMailing List Manager:\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addEmail(&mailingList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; 
                removeEmail(&mailingList, email);
                break;
            case 3:
                displayEmails(mailingList);
                break;
            case 4:
                freeMailingList(mailingList);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
}