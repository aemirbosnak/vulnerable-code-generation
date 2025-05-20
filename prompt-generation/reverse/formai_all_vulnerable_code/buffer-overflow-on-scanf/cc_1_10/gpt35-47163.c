//FormAI DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emailList {
    char email[30];
    struct emailList *next;
} EmailList;

void addEmail(EmailList **head, char *email) {
    EmailList* newEmail = malloc(sizeof(EmailList));
    strcpy(newEmail->email, email);
    newEmail->next = NULL;

    if (*head == NULL) {
        *head = newEmail;
        return;
    }

    EmailList *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newEmail;
}

void printEmails(EmailList *head) {
    EmailList *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

void deleteEmail(EmailList **head, char *email) {
    EmailList *temp = *head;
    EmailList *prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && strcmp(temp->email, email) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted, keeping track of
    // the previous node as we need to change 'prev->next'
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Email not found!\n");
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

int main() {
    EmailList *head = NULL;
    int choice;
    char email[30];

    do {
        printf("\n1. Add email\n");
        printf("2. Delete email\n");
        printf("3. View email list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter email: ");
                scanf("%s", email);
                addEmail(&head, email);
                printf("\nEmail added successfully!\n");
                break;

            case 2:
                printf("\nEnter email to delete: ");
                scanf("%s", email);
                deleteEmail(&head, email);
                printf("\nEmail deleted successfully!\n");
                break;

            case 3:
                printf("\nEmail List:\n");
                printEmails(head);
                break;

            case 4:
                printf("\nThank you for using our mailing list manager!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}